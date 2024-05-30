% save net
% data_y = data_y'
% yPred = yPred'
figure(1)
plot(data_y(:,1))
hold on
plot(yPred(:,1))
legend("区域1 \Deltaf_1", "emulator网络预测\Deltaf_1")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")
% xlim([0, 12000])

figure(2)
plot(data_y(:,2))
hold on
plot(yPred(:,2))
legend("区域1 \DeltaP_{tie,1}", "emulator网络预测\DeltaP_{tie,1}")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")
% xlim([0, 12000])

figure(3)
plot(data_y(:,3))
hold on
plot(yPred(:,3))
legend("区域2 \Deltaf_2", "emulator网络预测\Deltaf_2")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")
% xlim([0, 12000])

figure(4)
plot(data_y(:,4))
hold on
plot(yPred(:,4))
legend("区域2 \DeltaP_{tie,2}", "emulator网络预测\DeltaP_{tie,2}")
ylabel("控制信号P_c/p.u.")
xlabel("时间/ms")
% xlim([0, 12000])