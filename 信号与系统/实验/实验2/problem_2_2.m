t=[0:0.5:10];
u=[(t-2)>=0];
x=u;

a=[1, 2];
b=[1];

y=lsim(b, a, x, t);

plot(t, y);
grid on;
title('输出响应s(t)');
xlabel('t');
ylabel('s(t)');