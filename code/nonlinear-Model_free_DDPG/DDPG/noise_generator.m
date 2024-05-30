function x = noise_generator()
%n_random_2 = 100000;
%n_time = 999.99;
clc;clear all;
random = rand([1,100000])+0.5;
x_1 = movmean(random, 1000);
time = [0:0.01:999.99];
ma_noise = timeseries(x_1', time');
save ma_noise -v7.3 ma_noise

random = rand([1,100000])+0.5;
x_1 = movmean(random, 1000);
time = [0:0.01:999.99];
ma_noise1 = timeseries(x_1', time');
save ma_noise1 -v7.3 ma_noise1

random = rand([1,100000])+0.5;
x_1 = movmean(random, 1000);
time = [0:0.01:999.99];
ma_noise2 = timeseries(x_1', time');
save ma_noise2 -v7.3 ma_noise2
x = "噪声更新完毕";





