t=[0:0.1:10];
u=[(t-0)>=0];
x=u;

a=[1, 1/2];
b=[1];

y=lsim(b, a, x, t);

plot(t, y);
grid on;
title('阶跃响应s(t)');
xlabel('t');
ylabel('s(t)');