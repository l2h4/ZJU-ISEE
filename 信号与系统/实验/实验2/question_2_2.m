%微分方程参数
a1=[1 3];
b1=[1];
t=[-1:0.05:4];

%delta函数设置
d1=0.1;
d2=0.2;
d3=0.4;
delt1=(1/d1).*(t>=0&t<d1)+0.*(t<0)+0.*(t>=d1);
delt2=(1/d2).*(t>=0&t<d2)+0.*(t<0)+0.*(t>=d2);
delt3=(1/d3).*(t>=0&t<d3)+0.*(t<0)+0.*(t>=d3);
fn=[(t-0)==0];

%delta函数输出
h_delt1=lsim(b1,a1,delt1,t);
h_delt2=lsim(b1,a1,delt2,t);
h_delt3=lsim(b1,a1,delt3,t);

%冲激函数输出
u1=[t>=0];
y1=lsim(b1,a1,u1,t);
yt=y1.';
yd=diff(yt);
td=diff(t);
ydiff=yd./td;

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
plot(t(1:end-1), ydiff);
title('h(t)');
