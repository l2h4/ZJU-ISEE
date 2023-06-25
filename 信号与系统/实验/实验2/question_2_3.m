%微分方程参数设置
a1=[1 3];
b1=[1];
t=[0:0.05:5];

%当面积不为1时的delta函数
d1=0.1;
d2=0.2;
d3=0.4;
delt1=1.*(t>=0&t<d1)+0.*(t<0)+0.*(t>=d1);
delt2=1.*(t>=0&t<d2)+0.*(t<0)+0.*(t>=d2);
delt3=1.*(t>=0&t<d3)+0.*(t<0)+0.*(t>=d3);

%输出结果
h_delt1=lsim(b1,a1,delt1,t);
h_delt2=lsim(b1,a1,delt2,t);
h_delt3=lsim(b1,a1,delt3,t);

%绘图
subplot(4,1,1);
plot(t,h_delt1);
title('h_{\Delta=0.1}(t)');
subplot(4,1,2);
plot(t,h_delt2);
title('h_{\Delta=0.2}(t)');
subplot(4,1,3);
plot(t,h_delt3);
title('h_{\Delta=0.4}(t)');
subplot(4,1,4);
sys=tf(1,[1 3]);
impulse(sys,5);
