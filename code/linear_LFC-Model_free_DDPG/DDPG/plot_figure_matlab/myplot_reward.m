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
    if mod(flag,2)==1
        s = strsplit(str,{',',':'}); 
        temps1 = str2double(char(s{4}));
        temp = [temp,temps1];
    end
    flag = flag +1;
end
fclose(fid);
%%
fillcolor1= [255, 187, 0]/255;
fillcolor2= [0, 161, 241]/255;
fillcolor3= [124, 187, 0]/255;
fillcolor4= [246, 83, 20]/255;

reward1_test = temp;
%%
figure(1)

plot(reward1_test,'linestyle','-', 'color', 'b', Marker='o',MarkerSize=3)


xlabel('Episode(s)')
ylabel('Reward(Hz)')
title('Reward of the Agent')
xlim([0,100])
grid on



