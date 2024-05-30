function modified_finish = modification_mat(path, epi) 
%% Actor1
load("bbb.mat")
actor_num = '0';
actor_numpy_path = 'actor_numpy_for_matlab/';
layer1_weight = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer1_weight.npy']));
layer1_bias = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer1_bias.npy']));
layer2_weight = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer2_weight.npy']));
layer2_bias = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer2_bias.npy']));
layer3_weight = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer3_weight.npy']));
layer3_bias = single(readNPY([actor_numpy_path, 'Actor', actor_num,'layer3_bias.npy']));

temp_net = netone.saveobj;
temp_net.Layers(2,1).Weights = layer1_weight;
temp_net.Layers(2,1).Bias = layer1_bias;
temp_net.Layers(4,1).Weights = layer2_weight;
temp_net.Layers(4,1).Bias = layer2_bias;
temp_net.Layers(6,1).Weights = layer3_weight;
temp_net.Layers(6,1).Bias = layer3_bias;
netone = netone.loadobj(temp_net);
save("bbb.mat", 'netone')
actor_path = [path, 'Actor0_',epi,'.mat'];
save(actor_path, 'netone')

modified_finish = 'simulink中actor参数更新完毕';
end