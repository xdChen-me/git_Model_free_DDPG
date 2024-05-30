#!/usr/bin/env python
# coding=utf-8

import os
import sys
import time
import h5py
from mindspore import Tensor
import mindspore as ms
from mindspore import ops

import datetime
import numpy as np

sys.path.append(os.path.split(os.path.abspath(os.path.dirname(__file__)))[0])

from env import OUNoise, Area1Env, Area1Envtest, auto_correlated_noise
from agent import DRL

import matplotlib
import matplotlib.pyplot as plt
from common.utils import make_dir, save_results
import matlab.engine
# import torch.optim as optim

matplotlib.use("Agg")

curr_path = os.path.dirname(os.path.abspath(__file__))  # 当前文件所在绝对路径
parent_path = os.path.dirname(curr_path)  # 父路径
sys.path.append(parent_path)  # 添加父路径到系统路径sys.path

curr_time = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")  # 获取当前时间
statemax = [0.0632, 0.0095, 0.5454]
statemin = [-0.0632, -0.0129, -0.5452]
actionmax = 0.1058
actionmin = -0.0959

class DRLConfig:
    def __init__(self):
        self.algo = 'DRL'  # 算法名称
        self.env = 'Area1Env'  # 环境名称
        self.result_path = curr_path + "/outputs/" + self.env + \
                           '/' + curr_time + '/results/'  # 保存结果的路径
        self.model_path = curr_path + "/outputs/" + self.env + \
                          '/' + curr_time + '/models/'  # 保存模型的路径
        self.model_epi_path = curr_path + "/outputs/" + self.env + \
                          '/' + curr_time + '/epi/'  # 保存每回合训练的模型的路径
        self.train_config_path = curr_path + "/outputs/" + self.env + \
                          '/' + curr_time + '/train_config/'  # 保存设置和每回合训练结果
        
        self.model_epi_mat_path = curr_path + "/outputs/" + self.env + \
                          '/' + curr_time + '/epi_mat/'  # 保存每回合训练的模型的路径
        self.curr_trained_path = curr_path + "/outputs/" + self.env + \
                          '/' + curr_time + '/curr_actor/'  # 保存设置和每回合训练结果
        
        self.train_eps = 10  # 训练的回合数
        self.eval_eps = 1  # 测试的回合数
        self.gamma = 0.99  # 折扣因子
        self.actor_lr = 0.00005  # 演员网络的学习率
        self.actor_lr_base = 0.00005
        self.decay_rate = 0.9
        self.decay_steps = 10
        self.memory_capacity = 12000
        self.batch_size = 256
        self.target_update = 2
        self.hidden_dim = 256
        self.soft_tau = 0.1  # 软更新参数

        self.simulation_time = 32
        self.n_for_draw = 1

        self.device = "cpu"

        # self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")


def env_agent_config(cfg, seed=1):
    env = Area1Env()

    state_dim = env.observation_dim
    action_dim = env.action_dim
    agent = DRL(state_dim, action_dim, cfg)
    return env, agent

def env_agent_config_test(cfg, seed=1):
    env = Area1Envtest()
    state_dim = env.observation_dim
    action_dim = env.action_dim
    agent = DRL(state_dim, action_dim, cfg)
    return env, agent


def train(cfg, env, agent):
    print('开始训练！')
    print(f'环境：{cfg.env}，算法：{cfg.algo}，设备：{cfg.device}')

    ou_noise = OUNoise()  # 动作噪声
    auto_noise = auto_correlated_noise()

    rewards = []  # 记录奖励
    ma_rewards = []

    my_engine = matlab.engine.start_matlab()  # 在python中启动matlab
    
    env_name = 'LFC_oneArea'  # 文件名
    
    fig, ax = plt.subplots(1, 1, sharex='col', sharey='row', figsize=(32, 32))

    for i_ep in range(cfg.train_eps):
        
        modified_finish = my_engine.modification_mat(cfg.model_epi_mat_path, str(i_ep))
        noise_generator_return = my_engine.noise_generator()
        print(noise_generator_return)
        my_engine.load_system(env_name)
        simulation_time =  cfg.simulation_time  # simulation time (s)

        time_begin = time.time()
        simuOUt = my_engine.sim(env_name, 'StopTime', str(simulation_time))
        time_end = time.time()
        time_for_simulink_run = time_end - time_begin
        print('time for running simulink:', time_for_simulink_run)
        
        simulinkdata_path = curr_path + '/simulinkData/'

        # 读取数据
        ACE_dev = h5py.File(simulinkdata_path + 'ACE_dev.mat')
        ACE_pro = h5py.File(simulinkdata_path + 'ACE_pro.mat')
        ACE_inte = h5py.File(simulinkdata_path + 'ACE_inte.mat')
        delta_f = h5py.File(simulinkdata_path + 'delta_f.mat')
        delta_Pc = h5py.File(simulinkdata_path + 'delta_Pc.mat')
        ACE_dev_data = ACE_dev['ans'][:, 1].transpose()
        ACE_pro_data = ACE_pro['ans'][:, 1].transpose()
        ACE_inte_data = ACE_inte['ans'][:, 1].transpose()
        delta_f_data = delta_f['ans'][:, 1].transpose()
        delta_Pc_data = delta_Pc['ans'][:, 1].transpose()

        ACE_dev.close()
        ACE_pro.close()
        ACE_inte.close()
        delta_f.close()
        delta_Pc.close()

        done = False  # 没有实际含义

        for i_transition in range(ACE_dev_data.size-1):
            if i_transition >= 0:
                obs = np.array([ACE_pro_data[i_transition], ACE_inte_data[i_transition], ACE_dev_data[i_transition]])
                action = np.array([delta_Pc_data[i_transition]])
                temp = i_transition + 1
                obs_n = np.array([ACE_pro_data[temp], ACE_inte_data[temp], ACE_dev_data[temp]])
                reward = np.array(-abs(ACE_pro_data[temp]))
                agent.memory.push(obs, action, reward, obs_n, done)


                ep_reward = np.array(sum(-abs(ACE_pro_data[0:-1])))
        
        flag = 0
        if ep_reward>-17.8:
            cfg.actor_lr = 0.00001
            flag = flag +1
        elif flag==0:
            cfg.actor_lr = cfg.actor_lr_base * cfg.decay_rate ** (i_ep / cfg.decay_steps)
        else:
            cfg.actor_lr = 0.00001

        ops.assign(agent.actor_optimizer.learning_rate, ms.Tensor(cfg.actor_lr, ms.float32))
        cfg.actor_lr = agent.actor_optimizer.learning_rate.data.asnumpy()
        # agent.actor_optimizer = nn.Adam(agent.actor_Q.trainable_params(), lr=cfg.actor_lr)

        agent.update()  # 这边为回合更新，看情况可以修改为单步更新
        agent.save_actor_numpy_for_matlab(path=actor_numpy_for_matlab)
        modified_finish = my_engine.modification_mat(cfg.model_epi_mat_path, str(i_ep))
        time.sleep(3)
        agent.save_model_epi(i_ep, path=cfg.model_epi_path)
        print(modified_finish)

        ep_reward = np.array(sum(-abs(ACE_pro_data[0:-1])))
        print('回合：{}/{}，奖励：{:.6f}, 学习率：{:.8f}'.format(i_ep + 1, cfg.train_eps, ep_reward, cfg.actor_lr))

        with open(cfg.train_config_path + "train_result.txt", "a") as f:
            f.write("episode: %s/%s, reward: %s, learning rate: %s\n, output:%s\n" % (str(i_ep + 1), str(cfg.train_eps), str(ep_reward), str(cfg.actor_lr), str(agent.actor(Tensor([[0.,0.,0.]])))))

        if (i_ep % cfg.n_for_draw == 0) or (i_ep == cfg.train_eps-1):
            ax.plot(ACE_pro_data, label='episode_%s' % (str(i_ep)))

        agent.save_model_epi(i_ep, path=cfg.model_epi_path)
        rewards.append(ep_reward)
        if ma_rewards:
            ma_rewards.append(0.9 * ma_rewards[-1] + 0.1 * ep_reward)
        else:
            ma_rewards.append(ep_reward)
    my_engine.exit()
    print('完成训练！')
    return rewards, ma_rewards


if __name__ == "__main__":
    cfg = DRLConfig()

    SDAE_trained_actor_path = curr_path + "/FCnnloadprocessed/"
    SDAE_trained_critic_path = curr_path + "/FCnnloadprocessedCritic/"
    figure_path = curr_path + "/figure/"

    actor_numpy_for_matlab = curr_path + '/actor_numpy_for_matlab/'
    # # 训练
    env, agent = env_agent_config(cfg, seed=1)
    agent.load_SDAE(path1=SDAE_trained_actor_path, path2=SDAE_trained_critic_path)
    agent.save_actor_numpy_for_matlab(path=actor_numpy_for_matlab)
    

    make_dir(cfg.result_path, cfg.model_path, cfg.model_epi_path, cfg.train_config_path, cfg.model_epi_mat_path)
    rewards, ma_rewards = train(cfg, env, agent)
    
    
    plt.figure(2)
    plt.plot(rewards, marker='o')
    plt.xlabel('episode')
    plt.ylabel('rewards(-|ACE|/p.u.)')
    plt.xlim([0, cfg.train_eps])
    plt.savefig(cfg.result_path + 'rewards.jpg')


    plt.figure(3)
    plt.plot(ma_rewards)
    plt.xlabel('episode')
    plt.ylabel('rewards(-|ACE|/p.u.)')
    plt.xlim([0, cfg.train_eps])
    plt.savefig(cfg.result_path + 'ma_rewards.jpg')

