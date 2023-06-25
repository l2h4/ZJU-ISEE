%微分方程参数
a0=[1 3];
b0=[1];
t=[-1:0.05:4];

%dat函数设置
u1=[t>=0];
a1=4;
a2=8;
a3=16;
dat1=a1.*exp(-a1.*t).*u1;
dat2=a2.*exp(-a2.*t).*u1;
dat3=a3.*exp(-a3.*t).*u1;

%dat函数输出
h_delt1=lsim(b0,a0,dat1,t);
h_delt2=lsim(b0,a0,dat2,t);
h_delt3=lsim(b0,a0,dat3,t);

%冲激响应
y1=lsim(b1,a1,u1,t);
yt=y1.';
yd=diff(yt);
td=diff(t);
ydiff=yd./td;

%绘图
subplot(4,1,1);
plot(t,h_delt1);
title('h_{a=4}(t)');
subplot(4,1,2);
plot(t,h_delt2);
title('h_{a=8}(t)');
subplot(4,1,3);
plot(t,h_delt3);
title('h_{a=16}(t)');
subplot(4,1,4);
plot(t(1:end-1), ydiff);
title('h(t)');