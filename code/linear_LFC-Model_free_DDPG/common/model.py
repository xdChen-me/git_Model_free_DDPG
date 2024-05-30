#!/usr/bin/env python
# coding=utf-8

import mindspore
import mindspore.nn as nn
from mindspore.ops import operations as P

class Critic(nn.Cell):
    def __init__(self, n_obs, output_dim, hidden_size, init_w=3e-3):
        super(Critic, self).__init__()

        self.linear1 = nn.Dense(n_obs + output_dim, hidden_size, weight_init='normal')
        self.linear2 = nn.Dense(hidden_size, hidden_size, weight_init='normal')
        self.linear3 = nn.Dense(hidden_size, 1, weight_init='normal')
        self.relu=nn.ReLU() 
        # # 随机初始化为较小的值
        # self.linear3.weight.data.uniform_(-init_w, init_w)
        # self.linear3.bias.data.uniform_(-init_w, init_w)

    def construct(self, state, action):
        # 按维数1拼接
        # 创建Concat操作
        concat = P.Concat(axis=1)

        # 拼接张量
        x = concat((state, action))
        # x = nn.cat([state, action], 1)
        x = self.relu(self.linear1(x))
        x = self.relu(self.linear2(x))
        x = self.relu(self.linear3(x))
        return x


class Actor(nn.Cell):
    def __init__(self, n_obs, output_dim, hidden_size, init_w=3e-3):
        super(Actor, self).__init__()
        self.linear1 = nn.Dense(n_obs, hidden_size, weight_init='normal')
        self.linear2 = nn.Dense(hidden_size, hidden_size, weight_init='normal')
        self.linear3 = nn.Dense(hidden_size, output_dim, weight_init='normal')
        self.relu = nn.ReLU()
        self.tanh = nn.Tanh()
        # self.linear3.weight.data.uniform_(-init_w, init_w)
        # self.linear3.bias.data.uniform_(-init_w, init_w)

    def construct(self, x):
        x1 = self.relu(self.linear1(x))
        x2 = self.relu(self.linear2(x1))
        x3 = self.tanh(self.linear3(x2))
        return x3

class Actor_Q(nn.Cell):
    def __init__(self, n_obs, output_dim, hidden_size, init_w=3e-3):
        super(Actor_Q, self).__init__()
        self.linear1 = nn.Dense(n_obs, hidden_size, weight_init='normal')
        self.linear2 = nn.Dense(hidden_size, hidden_size, weight_init='normal')
        self.linear3 = nn.Dense(hidden_size, output_dim, weight_init='normal')
        self.relu = nn.ReLU()
        self.tanh = nn.Tanh()
        # self.linear3.weight.data.uniform_(-init_w, init_w)
        # self.linear3.bias.data.uniform_(-init_w, init_w)

    def construct(self, x, Q_grad):
        x1 = self.relu(self.linear1(x))
        x2 = self.relu(self.linear2(x1))
        x3 = self.tanh(self.linear3(x2))
        actionmax = 0.1058
        actionmin = -0.0959
        x3 = (x3 + 1) * (actionmax - actionmin) / 2 + actionmin
        Q_value = Q_grad*x3
        return -Q_value


