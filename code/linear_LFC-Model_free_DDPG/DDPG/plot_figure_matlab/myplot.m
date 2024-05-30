clear, clc, close all
set(groot,'defaultLineLineWidth',1.5)
set(groot,'defaultAxesFontName','Arial')
set(groot,'defaultAxesFontSize',12)
%%
path = "simulinkData_actor_PID";
ACE_pro = load(path+"\ACE_pro.mat").ans(2, :);
ACE_inte = load(path+"\ACE_inte.mat").ans(2, :);
ACE_dev = load(path+"\ACE_dev.mat").ans(2, :);
actions = load(path+"\delta_Pc.mat").ans(2, :);
delta_f = load(path+"\delta_f.mat").ans(2, :);
delta_Pm = load(path+"\delta_Pm.mat").ans(2, :);



path = "simulinkData_actor_50";
ACE_pro_train_2 = load(path+"\ACE_pro.mat").ans(2, :);
ACE_inte_train = load(path+"\ACE_inte.mat").ans(2, :);
ACE_dev_train = load(path+"\ACE_dev.mat").ans(2, :);
actions_train = load(path+"\delta_Pc.mat").ans(2, :);
delta_f_train = load(path+"\delta_f.mat").ans(2, :);
delta_Pm_train = load(path+"\delta_Pm.mat").ans(2, :);



%%
time= 0:0.01:32;
fillcolor1= [255, 187, 0]/255;
fillcolor2= [0, 161, 241]/255;
fillcolor3= [124, 187, 0]/255;
fillcolor4= [246, 83, 20]/255;



%%
figure(1)
ACE_pro = ACE_pro/(1/0.33+0.0015);
ACE_pro_train_2 = ACE_pro_train_2/(1/0.33+0.0015);

plot(time, ACE_pro,'linestyle','-', 'color', 'b')
hold on 
plot(time, ACE_pro_train_2,'linestyle','-', 'color', 'r')
legend('PID','Model-free DDPG')
xlabel('time(s)')
ylabel('Frequency Deviation(Hz)')
title('Frequency Deviation')
xlim([0,32])
grid on

figure(2)

plot(time, delta_Pm,'linestyle','-', 'color', 'b')
hold on 
plot(time, delta_Pm_train,'linestyle','-', 'color', 'r')

legend('PID','Model-free DDPG')
xlabel('time(s)')
ylabel('Output power(p.u.)')
title('Output of the generator')
xlim([0,32])
grid on




