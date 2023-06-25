n=[-5:5];
x1=[(n-0)==0];
x2=2*x1;

y1=sin((pi/2)*x1);
y2=sin((pi/2)*x2);

subplot(2,1,1);
stem(y1);
title('y_1');
xlabel('n');
ylabel('y_1[n]');
subplot(2,1,2);
stem(y2);
title('y_2');
xlabel('n');
ylabel('y_2[n]');
