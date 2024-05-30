w_in2hid = net.Layers(2,1).Weights;
b_in2hid = net.Layers(2,1).Bias;
w_hid2hid = net.Layers(4,1).Weights;
b_hid2hid = net.Layers(4,1).Bias;
w_hid2out = net.Layers(6,1).Weights;
b_hid2out = net.Layers(6,1).Bias;

save("netParameter\w_in2hid.mat","w_in2hid",'-v7.3');
save("netParameter\b_in2hid.mat","b_in2hid",'-v7.3');
save("netParameter\w_hid2hid.mat","w_hid2hid",'-v7.3');
save("netParameter\b_hid2hid.mat","b_hid2hid",'-v7.3');
save("netParameter\w_hid2out.mat","w_hid2out",'-v7.3');
save("netParameter\b_hid2out.mat","b_hid2out",'-v7.3');

w_in2hid = netone.Layers(2,1).Weights;
b_in2hid = netone.Layers(2,1).Bias;
w_hid2hid = netone.Layers(4,1).Weights;
b_hid2hid = netone.Layers(4,1).Bias;
w_hid2out = netone.Layers(6,1).Weights;
b_hid2out = netone.Layers(6,1).Bias;

save("netParameter\w_in2hid1.mat","w_in2hid",'-v7.3');
save("netParameter\b_in2hid1.mat","b_in2hid",'-v7.3');
save("netParameter\w_hid2hid1.mat","w_hid2hid",'-v7.3');
save("netParameter\b_hid2hid1.mat","b_hid2hid",'-v7.3');
save("netParameter\w_hid2out1.mat","w_hid2out",'-v7.3');
save("netParameter\b_hid2out1.mat","b_hid2out",'-v7.3');

w_in2hid = nettwo.Layers(2,1).Weights;
b_in2hid = nettwo.Layers(2,1).Bias;
w_hid2hid = nettwo.Layers(4,1).Weights;
b_hid2hid = nettwo.Layers(4,1).Bias;
w_hid2out = nettwo.Layers(6,1).Weights;
b_hid2out = nettwo.Layers(6,1).Bias;

save("netParameter\w_in2hid2.mat","w_in2hid",'-v7.3');
save("netParameter\b_in2hid2.mat","b_in2hid",'-v7.3');
save("netParameter\w_hid2hid2.mat","w_hid2hid",'-v7.3');
save("netParameter\b_hid2hid2.mat","b_hid2hid",'-v7.3');
save("netParameter\w_hid2out2.mat","w_hid2out",'-v7.3');
save("netParameter\b_hid2out2.mat","b_hid2out",'-v7.3');

