clear, clc, close all
set(groot,'defaultLineLineWidth',1)
set(groot,'defaultAxesFontName','Arial')
set(groot,'defaultAxesFontSize',12)

fid=fopen('train_result.txt');       %首先打开文本文件coordinate.txt
temp = [];
flag = 1;
while ~feof(fid)    % while循环表示文件指针没到达末尾，则继续
    % 每次读取一行, str是字符串格式
    str = fgetl(fid);
    s = strsplit(str,{',',':'}); 
    temps1 = str2double(char(s{4}));
    temp = [temp,temps1];
end
fclose(fid);
%%

fillcolor1= [255, 187, 0]/255;
fillcolor2= [0, 161, 241]/255;
fillcolor3= [124, 187, 0]/255;
fillcolor4= [246, 83, 20]/255;



%%
figure(1)
temp = temp/(1/0.33+0.0015);

plot( temp,'linestyle','-', 'color', 'b','Marker','o',MarkerSize=3)

xlabel('Episode')
ylabel('Reward(Hz) ')
title('Reward of the Agent')
xlim([0,140])
grid on


