sim_time = 32;
sim_time_step = 0.01;
% 生成时间戳
loadchange = importdata('loadchange100.txt');
time_stamp = zeros([length(loadchange), 1]);
for i = 1:length(loadchange)
    time_stamp(i,1)= (i-1)*sim_time_step;
end

B = [time_stamp, loadchange];

values = struct('values', loadchange);
A = struct('time', [], 'signals',values);

% loadchangeForSimulink = struct('signals', [], 'time', []);
% loadchangeForSimulink.signals.value = loadchange;
% loadchangeForSimulink.signals.dimensions = 1;