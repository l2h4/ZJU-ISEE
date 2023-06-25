%微分方程参数
a1=[1 3];
b1=[1];
t=[-1:0.05:4];

%阶跃信号
u1=[t>=0];

%阶跃信号输出
y1=lsim(b1,a1,u1,t);

%冲激信号输出
yt=y1.';
yd=diff(yt);
td=diff(t);
ydiff=yd./td;

%绘图
figure(1);
subplot(2,1,1);
plot(t,y1);
title('s(t)');
subplot(2,1,2);
plot(t(1:end-1), ydiff);
title('h(t)');

%step、impulse函数验证
figure(2);
subplot(2,1,1);
sys1=tf(1,[1 3]);
step(sys1,5);
subplot(2,1,2);
sys2=tf(1,[1 3]);
impulse(sys2,5);