clear, clc, close all

ACE_pro = load("simulinkData\ACE_pro.mat").ans(2, :);
ACE_inte = load("simulinkData\ACE_inte.mat").ans(2, :);
ACE_dev = load("simulinkData\ACE_dev.mat").ans(2, :);
actions = load("simulinkData\delta_Pc.mat").ans(2, :);
delta_f = load("simulinkData\delta_f.mat").ans(2, :);
Ptie = load("simulinkData\Ptie.mat").ans(2, :);

ACE_pro1 = load("simulinkData\ACE_pro1.mat").ans(2, :);
ACE_inte1 = load("simulinkData\ACE_inte1.mat").ans(2, :);
ACE_dev1 = load("simulinkData\ACE_dev1.mat").ans(2, :);
actions1 = load("simulinkData\delta_Pc1.mat").ans(2, :);
delta_f1 = load("simulinkData\delta_f1.mat").ans(2, :);
Ptie1 = load("simulinkData\Ptie1.mat").ans(2, :);

ACE_pro2 = load("simulinkData\ACE_pro2.mat").ans(2, :);
ACE_inte2 = load("simulinkData\ACE_inte2.mat").ans(2, :);
ACE_dev2 = load("simulinkData\ACE_dev2.mat").ans(2, :);
actions2 = load("simulinkData\delta_Pc2.mat").ans(2, :);
delta_f2 = load("simulinkData\delta_f2.mat").ans(2, :);
Ptie2 = load("simulinkData\Ptie2.mat").ans(2, :);

%得到obs输入向量
obs_act = zeros(3, length(actions)) ;
obs_act1 = zeros(3, length(actions)) ;
obs_act2 = zeros(3, length(actions)) ;
i_data = 0;
d_data = 0;
for j = 1:(length(actions))
    obs_act(1, j) = ACE_pro(j);
    obs_act(2, j) = ACE_inte(j);
    obs_act(3, j) = ACE_dev(j);

    obs_act1(1, j) = ACE_pro1(j);
    obs_act1(2, j) = ACE_inte1(j);
    obs_act1(3, j) = ACE_dev1(j);

    obs_act2(1, j) = ACE_pro2(j);
    obs_act2(2, j) = ACE_inte2(j);
    obs_act2(3, j) = ACE_dev2(j);
end
data = obs_act';
data1 = obs_act1';
data2 = obs_act2';

action = zeros(1, length(actions)) ;
action1 = zeros(1, length(actions)) ;
action2 = zeros(1, length(actions)) ;
for j = 1:(length(actions))
    action(j) = actions(j);
    action1(j) = actions1(j);
    action2(j) = actions2(j);
end
data_y = action';
data_y1 = action1';
data_y2 = action2';

%% 归一化
datamax = max(data);
datamin = min(data);
data_ymax = max(data_y);
data_ymin = min(data_y);

% datamax = [0.0443, 0.0097, 0.3634 ,0.0628];
% datamin = [-0.0443, -0.0097, -0.3634, -0.0628];
% data_ymax = 0.0146;
% data_ymin = -0.0146;

%输入为[0,1] 输出为[-1,1]
for j = 1:(length(actions))
    for i = 1:3
        data(j, i) = (data(j, i)- datamin(i))/(datamax(i)-datamin(i));
    end
     data_y(j) = (data_y(j)- data_ymin)/(data_ymax-data_ymin);
end

datamax1 = max(data1);
datamin1 = min(data1);
data_ymax1 = max(data_y1);
data_ymin1 = min(data_y1);

% datamax = [0.0443, 0.0097, 0.3634 ,0.0628];
% datamin = [-0.0443, -0.0097, -0.3634, -0.0628];
% data_ymax = 0.0146;
% data_ymin = -0.0146;

%输入为[0,1] 输出为[-1,1]
for j = 1:(length(actions))
    for i = 1:3
        data1(j, i) = (data1(j, i)- datamin1(i))/(datamax1(i)-datamin1(i));
    end
    data_y1(j) = (data_y1(j)- data_ymin1)/(data_ymax1-data_ymin1);
end


datamax2 = max(data2);
datamin2 = min(data2);
data_ymax2 = max(data_y2);
data_ymin2 = min(data_y2);

% datamax = [0.0443, 0.0097, 0.3634 ,0.0628];
% datamin = [-0.0443, -0.0097, -0.3634, -0.0628];
% data_ymax = 0.0146;
% data_ymin = -0.0146;

%输入为[0,1] 输出为[-1,1]
for j = 1:(length(actions))
    for i = 1:3
        data2(j, i) = (data2(j, i)- datamin2(i))/(datamax2(i)-datamin2(i));
    end
     data_y2(j) = (data_y2(j)- data_ymin2)/(data_ymax2-data_ymin2);
end


%%
numPoints = length(actions);
numFeatures = 3;


%训练自编码器
% 网络结构设置
layers = [
    % 特征输入层
    featureInputLayer(numFeatures);
    % 全连接层-1
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(1)
    reluLayer
    regressionLayer]

layers1 = [
    % 特征输入层
    featureInputLayer(numFeatures);
    % 全连接层-1
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(1)
    tanhLayer
    regressionLayer]

layers2 = [
    % 特征输入层
    featureInputLayer(numFeatures);
    % 全连接层-1
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(256)
    reluLayer
    fullyConnectedLayer(1)
    reluLayer
    regressionLayer]


% 训练参数设置
options = trainingOptions('adam', ...
    'ExecutionEnvironment', 'auto', ...
    'MiniBatchSize', 1000, ...
    'MaxEpochs', 100, ...
    'Shuffle', 'every-epoch', ...
    'Plots', 'training-progress', ...
    'Verbose', false,...
    'ExecutionEnvironment', 'cpu')

%% 训练
[net,info]= trainNetwork(data, data_y, layers, options);
[netone,info1]= trainNetwork(data1, data_y1, layers1, options);
[nettwo,info2]= trainNetwork(data2, data_y2, layers2, options);


yPred = predict(net, data);
yPred1 = predict(netone, data1);
yPred2 = predict(nettwo, data2);

%%
figure(1)
plot(data_y(:,1))
hold on
plot(yPred(:,1))
legend("区域1 \Deltaf", "SDAE预测控制信号")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")

figure(2)
plot(data_y1(:,1))
hold on
plot(yPred1(:,1))
legend("区域2 \Deltaf", "SDAE预测控制信号")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")

figure(3)
plot(data_y2(:,1))
hold on
plot(yPred2(:,1))
legend("区域3 \Deltaf", "SDAE预测控制信号")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")

save("aaa.mat", 'net')
save("bbb.mat", 'netone')
save("ccc.mat", 'nettwo')
