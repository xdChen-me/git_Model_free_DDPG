#!/usr/bin/env python
# coding=utf-8

import numpy as np
import mindspore
import mindspore.nn as nn
from mindspore import Tensor
from mindspore import load_checkpoint, load_param_into_net, ops, save_checkpoint

import mindspore.numpy as mnp

from common.model import Actor, Critic, Actor_Q
from common.memory import ReplayBuffer

statemax = [0.0883, 0.0269, 0.5483]
statemin = [-0.0887, -0.0279, -0.5488]
actionmax = 0.5296
actionmin = -0.5192

statemax_critic = [0.1044, 0.0315, 0.5879]
statemin_critic = [-0.1098, -0.0311, -0.5935]
actionmax_critic = 0.4503
actionmin_critic = -0.4398
delta_f_max = 0.0344
delta_f_min = -0.0362
alpha = 0.001
cons_B = (1/0.33+0.0015)

class SimpleLoss(nn.Cell):
    def __init__(self):
        super(SimpleLoss, self).__init__()

    def construct(self, Q_value):
        return Q_value
    
class MyWithLossCell(nn.Cell):
   def __init__(self, backbone, loss_fn):
       super(MyWithLossCell, self).__init__(auto_prefix=False)
       self._backbone = backbone
       self._loss_fn = loss_fn

   def construct(self, x, y):
       out = self._backbone(x, y)
       return self._loss_fn(out)

   @property
   def backbone_network(self):
       return self._backbone

class DRL:
    def __init__(self, state_dim, action_dim, cfg):
        self.device = cfg.device
        self.actor = Actor(state_dim, action_dim, cfg.hidden_dim)
        self.critic = Critic(state_dim, action_dim, cfg.hidden_dim)
        self.actor_Q = Actor_Q(state_dim, action_dim, cfg.hidden_dim)

        self.target_actor = Actor(state_dim, action_dim, cfg.hidden_dim)

        # 复制参数到目标网络
        load_param_into_net(self.target_actor, self.actor.parameters_dict())
        load_param_into_net(self.actor_Q, self.actor.parameters_dict())

        self.actor_optimizer = nn.Adam(self.actor_Q.trainable_params(), learning_rate=cfg.actor_lr)
        
        self.memory = ReplayBuffer(cfg.memory_capacity)
        self.batch_size = cfg.batch_size
        self.soft_tau = cfg.soft_tau  # 软更新参数
        self.gamma = cfg.gamma
        self.Q_value = []

        self.grad_op = ops.GradOperation(get_by_list=True)

    def choose_action(self, state):
        state = Tensor(state)
        action = self.actor(state)
        return action

    def update(self):
        if len(self.memory) < self.batch_size: # 当 memory 中不满足一个批量时，不更新策略
            return
        # 从经验回放中(replay memory)中随机采样一个批量的转移(transition)
        state, action, reward, next_state, done = self.memory.sample(self.batch_size)
        # 转变为张量

        states_numpy = np.array(state) 
        action_n_numpy = action
        next_states_numpy = next_state

        for i in range(3):
            for j in range(256):
                # observation[:, i] = observation[:, i] * (statemax[i] - statemin[i]) + statemin[i]
                states_numpy[j, i] = (states_numpy[j, i] - statemin_critic[i]) / (statemax_critic[i] - statemin_critic[i])

        observation = Tensor(states_numpy, mindspore.float32)
        next_state = Tensor(next_states_numpy, mindspore.float32)
        action = Tensor(action_n_numpy, mindspore.float32)


        ACE_next = next_state[:, 0].reshape(-1, 1)
        ACE_next = ACE_next * (statemax[0] - statemin[0]) + statemin[0]
        delta_f_next = ACE_next / cons_B

        action1 = action - alpha
        action2 = action + alpha
        action1 = (action1 - actionmin_critic) / (actionmax_critic - actionmin_critic)
        action2 = (action2 - actionmin_critic) / (actionmax_critic - actionmin_critic)

        delta_f1 = self.critic(observation, action1)
        delta_f2 = self.critic(observation, action2)
        delta_f1 = delta_f1 * (delta_f_max - delta_f_min) + delta_f_min
        delta_f2 = delta_f2 * (delta_f_max - delta_f_min) + delta_f_min

        Q_grads = -2 * delta_f_next * (delta_f2 - delta_f1) / (2 * alpha)

        grad_fn = mindspore.value_and_grad(self.actor_Q, None, self.actor_optimizer.parameters, has_aux=False)
        loss, grads = grad_fn(observation, Q_grads)
        old_param = self.actor_Q.trainable_params()  # 获取更新前的参数值
        self.actor_optimizer(grads)
        new_param = self.actor_Q.trainable_params()  # 获取更新后的参数值

        load_param_into_net(self.actor, self.actor_Q.parameters_dict())

        # 软更新
        # Get the parameters of the target actor and the actor
        target_actor_params = self.target_actor.parameters_dict()
        actor_params = self.actor.parameters_dict()

        # Perform the soft update
        for name in target_actor_params:
            target_actor_params[name].set_data(
            target_actor_params[name].data * (1.0 - self.soft_tau) +
            actor_params[name].data * self.soft_tau
            )
    def save(self, path):
        torch.save(self.actor.state_dict(), path+'checkpoint.pt')

    def load(self, path):
        self.actor.load_state_dict(torch.load(path+'checkpoint.pt'))

    def load_SDAE(self, path1, path2):
        param_dict = load_checkpoint(path1+'initial_for_ms.ckpt')
        load_param_into_net(self.actor, param_dict)
        param_dict = load_checkpoint(path1+'initial_for_ms.ckpt')
        load_param_into_net(self.actor_Q, param_dict)
        param_dict = load_checkpoint(path2+'initial_for_ms.ckpt')
        load_param_into_net(self.critic, param_dict)

    def save_model_epi(self, episode, path):
        for i in range(1):  # Assuming you have 1 agent; adjust the range if you have more
            model_name_a = "Actor_Agent" + str(i) + "_" + str(episode) + ".ckpt"
            save_checkpoint(self.agents[i].target_actor, path + model_name_a)

    # def load_model_epi(self, episode, path):
    #     model_name_a = "Actor" + "_" + str(episode) + ".pt"
    #     self.actor.load_state_dict(torch.load(path + model_name_a))

    def save_model_epi(self, episode, path):
        model_name_a = "Actor" + "_" + str(episode) + ".ckpt"
        save_checkpoint(self.actor, path + model_name_a)

    def save_actor_numpy_for_matlab(self, path):
        for i in range(1):
            parameters = self.actor.trainable_params()
            for p, i_flag, layer in zip(parameters, range(6), [1, 1, 2, 2, 3, 3]):
                numpy_para = p.asnumpy()
                file_name = ""
                if i_flag % 2 == 0:
                    file_name = path + "Actor" + str(i) + "layer" + str(layer) + "_weight.npy"
                else:
                    file_name = path + "Actor" + str(i) + "layer" + str(layer) + "_bias.npy"
                np.save(file_name, numpy_para)
