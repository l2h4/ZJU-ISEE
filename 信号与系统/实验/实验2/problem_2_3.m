t=[0:0.1:10];
u=[(t-0)>=0];
x=u;

a=[1, 2];
b=[1];

%question 1
figure(1);

subplot(2,1,1)
y=lsim(b, a, x, t);
plot(t, y);
grid on;
title('阶跃响应s_{lsim}(t)');
xlabel('t');
ylabel('s(t)');

subplot(2, 1, 2);
step(b ,a, t);
grid on;
title('输出响应s_{step}(t)');
xlabel('t');
ylabel('s(t)');

%question 2
yt=y.';
yd=diff(yt);
td=diff(t);
ydiff=yd./td;

figure(2);

subplot(2, 1, 1);
plot(t(1:end-1), ydiff);
grid on;
title('冲激响应h_{diff}[t]');
xlabel('t');
ylabel('h_{diff}[t]');

subplot(2, 1, 2);
impulse(b, a, t);
grid on;
title('冲激响应h_{step}[t]');
xlabel('t');
ylabel('h_{step}[t]');
