%(2)
n=-5:10;
h=[(n-0)==0];
x=h;

a=[1, 1/6, -1/6];
b=[1, -1];

y=filter(b, a, x);

figure(1);
stem(n,y);
title('单位脉冲响应');
xlabel('n');
ylabel('h[n]');

%(3)
u=[(n-0)>=0];
x2=(1/4).^n.*u;

a=[1, 1/6, -1/6];
b=[1, -1];

y=filter(b, a, x2);

figure(2);
stem(n,y);
title('输出相应y[n]');
xlabel('n');
ylabel('y[n]');