#!/usr/bin/env python
# coding=utf-8
import itertools
from collections import deque

import numpy as np


loadchange = np.loadtxt('loadchange5s.txt')

class OUNoise(object):
    """
        Ornstein–Uhlenbeck噪声
    """
    def __init__(self, action_space=1, mu=0.0, theta=0.15, max_sigma=0.3, min_sigma=0.3, decay_period=100000):
        self.mu = mu  # OU噪声的参数
        self.theta = theta  # OU噪声的参数
        self.sigma = max_sigma  # OU噪声的参数
        self.max_sigma = max_sigma
        self.min_sigma = min_sigma
        self.decay_period = decay_period
        self.action_dim = 1
        self.low = -1
        self.high = 1
        self.reset()

    def reset(self):
        self.obs = np.ones(self.action_dim) * self.mu

    def evolve_obs(self):
        x = self.obs
        dx = self.theta * (self.mu - x) + self.sigma * np.random.randn(self.action_dim)
        self.obs = x + dx
        return self.obs

    def get_action(self, action, t=0):
        ou_obs = self.evolve_obs()
        self.sigma = self.max_sigma - (self.max_sigma - self.min_sigma) * min(1.0, t / self.decay_period)  # sigma会逐渐衰减
        return np.clip(action + ou_obs, self.low, self.high)  # 动作加上噪声后进行剪切


class auto_correlated_noise(object):
    def __init__(self):
        self.random_num = np.random.randn(10000)+1    # 平均值为1的随机数
        self.random_list = self.random_num.tolist()
        self.random_noise = list(self.moving_average(self.random_list, 3000))

    def get_noise(self, step):
        return self.random_noise[step % 5000]

    def reset(self):
        self.random_num = np.random.randn(10000)+1
        self.random_list = self.random_num.tolist()
        self.random_noise = list(self.moving_average(self.random_list, 3000))

    def moving_average(self, data_array, n=3):
        """
        Calcuate the moving average based on the specific data array.
        :param data_array: the array stored data to be calculated.
        :param n: the number of data in one time
        :return: Generate which contains the result
        """
        it = iter(data_array)
        d = deque(itertools.islice(it, n - 1))
        s = sum(d)
        # In the first round, to avoid getting extra element, so need zero in the head of queue.
        d.appendleft(0)
        for elem in it:
            s += elem - d.popleft()
            d.append(elem)
            yield s / float(n)


class Area1Env:
    # 系统状态
    def __init__(self):
        self.cons_Tg = 0.08
        self.cons_Tt = 0.4
        self.cons_H = 0.08335
        self.cons_D = 0.0015
        self.cons_R = 0.33
        self.cons_B = 1/self.cons_R + self.cons_D
        self.delta_t = 0.001

        self.__delta_f = 0
        self.__delta_Pg = 0
        self.__delta_Pm = 0
        self.__delta_PL = 0

        self.__delta_Pg_before = 0
        self.__delta_Pm_before = 0
        self.__delta_PL_before = 0

        self.i_delta_ACE = 0
        self.d_delta_ACE = 0
        self.pre_ACE = 0

        self.observation_dim = 3
        self.action_dim = 1

    def reset(self):
        self.__delta_f = 0
        self.__delta_Pg = 0
        self.__delta_Pm = 0
        self.__delta_PL = 0
        self.i_delta_ACE = 0
        self.d_delta_ACE = 0
        return np.array([0, 0, 0, 0, 0, 0, 0])

    def step(self, action, time):

        if time < 4000:
            self.__delta_PL = 0.01
        else:
            if time < 8000:
                self.__delta_PL = -0.01
            else:
                self.__delta_PL = 0.01

        if time < 12000:
            done = False
        else:
            done = True

        # self.__delta_PL = loadchange[time-1]
        #
        # if time < 5000:
        #     done = False
        # else:
        #     done = True

        __delta_Pc = action[0]
        dot_delf = self.__delta_Pm/(2*self.cons_H)-self.__delta_PL/(2*self.cons_H)-self.cons_D*self.__delta_f/(2*self.cons_H)
        dot_delPm = self.__delta_Pg / self.cons_Tt - self.__delta_Pm / self.cons_Tt
        dot_delPg = __delta_Pc / self.cons_Tg - self.__delta_f / (self.cons_R * self.cons_Tg) - self.__delta_Pg / self.cons_Tg

        delta_f = self.__delta_f + dot_delf * self.delta_t
        delta_Pm = self.__delta_Pm + dot_delPm * self.delta_t
        delta_Pg = self.__delta_Pg + dot_delPg * self.delta_t

        self.__delta_f = delta_f
        self.__delta_Pm = delta_Pm
        self.__delta_Pg = delta_Pg

        s_ = self.cons_B*self.__delta_f  # ACE
        self.i_delta_ACE = self.i_delta_ACE + s_
        self.d_delta_ACE = (s_ - self.pre_ACE) / self.delta_t
        self.pre_ACE = s_
        reward = -abs(self.__delta_f)

        return np.array([s_, self.i_delta_ACE, self.d_delta_ACE, self.__delta_f, self.__delta_Pg, self.__delta_Pm, self.__delta_PL]), reward, done

    def render(self):
        pass

class Area1Envtest:
    # 系统状态
    def __init__(self):
        self.cons_Tg = 0.08
        self.cons_Tt = 0.4
        self.cons_H = 0.08335
        self.cons_D = 0.0015
        self.cons_R = 0.33
        self.cons_B = 1/self.cons_R + self.cons_D
        self.delta_t = 0.001

        self.__delta_f = 0
        self.__delta_Pg = 0
        self.__delta_Pm = 0
        self.__delta_PL = 0

        self.__delta_Pg_before = 0
        self.__delta_Pm_before = 0
        self.__delta_PL_before = 0

        self.i_delta_ACE = 0
        self.d_delta_ACE = 0
        self.pre_ACE = 0

        self.observation_dim = 3
        self.action_dim = 1

    def reset(self):
        self.__delta_f = 0
        self.__delta_Pg = 0
        self.__delta_Pm = 0
        self.__delta_PL = 0
        self.i_delta_ACE = 0
        self.d_delta_ACE = 0
        return np.array([0, 0, 0, 0, 0, 0, 0])

    def step(self, action, time):

        if time < 5000:
            self.__delta_PL = 0
        else:
            if time < 25000:
                self.__delta_PL = -0.01
            else:
                self.__delta_PL = 0.02

        # self.__delta_PL = loadchange[time-1]

        if time < 50000:
            done = False
        else:
            done = True
        __delta_Pc = action[0]
        dot_delf = self.__delta_Pm/(2*self.cons_H)-self.__delta_PL/(2*self.cons_H)-self.cons_D*self.__delta_f/(2*self.cons_H)
        dot_delPm = self.__delta_Pg / self.cons_Tt - self.__delta_Pm / self.cons_Tt
        dot_delPg = __delta_Pc / self.cons_Tg - self.__delta_f / (self.cons_R * self.cons_Tg) - self.__delta_Pg / self.cons_Tg

        delta_f = self.__delta_f + dot_delf * self.delta_t
        delta_Pm = self.__delta_Pm + dot_delPm * self.delta_t
        delta_Pg = self.__delta_Pg + dot_delPg * self.delta_t

        self.__delta_f = delta_f
        self.__delta_Pm = delta_Pm
        self.__delta_Pg = delta_Pg

        s_ = self.cons_B*delta_f  # ACE
        self.i_delta_ACE += s_
        self.d_delta_ACE = (s_ - self.pre_ACE) / self.delta_t
        self.pre_ACE = s_
        reward = -abs(self.__delta_f)

        return np.array([s_, self.i_delta_ACE, self.d_delta_ACE, self.__delta_f, self.__delta_Pg, self.__delta_Pm, self.__delta_PL]), reward, done

    def render(self):
        pass
