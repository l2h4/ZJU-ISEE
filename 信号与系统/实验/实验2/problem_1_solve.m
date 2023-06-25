n=1:4;
u=[(n-0)>0];
x=n.*u;

a1=[0.5, 1, 2];
a2=[2];
a3=[0, 2];

b1=[1];
b2=[1, -0.8];
b3=[1, -0.8];

y1=filter(a1, b1, x);
y2=filter(a2, b2, x);
y3=filter(a3, b3, x);

subplot(3,1,1);
stem(y1);
title('y_1');
xlabel('n');
ylabel('y_1[n]');
grid on;
subplot(3,1,2);
stem(y2);
title('y_2');
xlabel('n');
ylabel('y_1[n]');
grid on;
subplot(3,1,3);
stem(y3);
title('y_3');
ylabel('y_1[n]');
xlabel('n');
grid on;