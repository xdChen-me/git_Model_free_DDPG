function modified_finish = modification_mat(path, epi) 


%% Actor1
load("bbb.mat")
layer1_weight = cell2mat(struct2cell(load('netParameter/w_in2hid.mat')));
layer1_bias = cell2mat(struct2cell(load('netParameter/b_in2hid.mat')));
layer2_weight = cell2mat(struct2cell(load('netParameter/w_hid2hid.mat')));
layer2_bias = cell2mat(struct2cell(load('netParameter/b_hid2hid.mat')));
layer3_weight = cell2mat(struct2cell(load('netParameter/w_hid2out.mat')));
layer3_bias = cell2mat(struct2cell(load('netParameter/b_hid2out.mat')));

temp_net = netone.saveobj;
temp_net.Layers(2,1).Weights = layer1_weight;
temp_net.Layers(2,1).Bias = layer1_bias;
temp_net.Layers(4,1).Weights = layer2_weight;
temp_net.Layers(4,1).Bias = layer2_bias;
temp_net.Layers(6,1).Weights = layer3_weight;
temp_net.Layers(6,1).Bias = layer3_bias;
net = netone.loadobj(temp_net);
save("aaa.mat", 'net')

%% Actor2
layer1_weight = cell2mat(struct2cell(load('netParameter/w_in2hid1.mat')));
layer1_bias = cell2mat(struct2cell(load('netParameter/b_in2hid1.mat')));
layer2_weight = cell2mat(struct2cell(load('netParameter/w_hid2hid1.mat')));
layer2_bias = cell2mat(struct2cell(load('netParameter/b_hid2hid1.mat')));
layer3_weight = cell2mat(struct2cell(load('netParameter/w_hid2out1.mat')));
layer3_bias = cell2mat(struct2cell(load('netParameter/b_hid2out1.mat')));

temp_net = netone.saveobj;
temp_net.Layers(2,1).Weights = layer1_weight;
temp_net.Layers(2,1).Bias = layer1_bias;
temp_net.Layers(4,1).Weights = layer2_weight;
temp_net.Layers(4,1).Bias = layer2_bias;
temp_net.Layers(6,1).Weights = layer3_weight;
temp_net.Layers(6,1).Bias = layer3_bias;
netone = netone.loadobj(temp_net);
save("bbb.mat", 'netone')

%% Actor3
layer1_weight = cell2mat(struct2cell(load('netParameter/w_in2hid2.mat')));
layer1_bias = cell2mat(struct2cell(load('netParameter/b_in2hid2.mat')));
layer2_weight = cell2mat(struct2cell(load('netParameter/w_hid2hid2.mat')));
layer2_bias = cell2mat(struct2cell(load('netParameter/b_hid2hid2.mat')));
layer3_weight = cell2mat(struct2cell(load('netParameter/w_hid2out2.mat')));
layer3_bias = cell2mat(struct2cell(load('netParameter/b_hid2out2.mat')));

temp_net = netone.saveobj;
temp_net.Layers(2,1).Weights = layer1_weight;
temp_net.Layers(2,1).Bias = layer1_bias;
temp_net.Layers(4,1).Weights = layer2_weight;
temp_net.Layers(4,1).Bias = layer2_bias;
temp_net.Layers(6,1).Weights = layer3_weight;
temp_net.Layers(6,1).Bias = layer3_bias;
nettwo = netone.loadobj(temp_net);
save("ccc.mat", 'nettwo')
modified_finish = 'simulink中actor参数更新完毕';
end