%系统1
a1=[1];
b1=[1 -1 -1];
n=[0:5];
x1=[(n-0)==0];
x2=[(n-1)==0];
x3=[(n-0)==0]+2*[(n-1)==0];

%系统1的对应输出
w1=filter(b1,a1,x1);
w2=filter(b1,a1,x2);
w3=filter(b1,a1,x3);

%线性系统验证
w_eg=w1+2.*w2;

%绘图
figure(1);
subplot(4,1,1);
stem(n,w1);
title('w_1[n]');
subplot(4,1,2);
stem(n,w2);
title('w_2[n]');
subplot(4,1,3);
stem(n,w3);
title('w_3[n]');
subplot(4,1,4);
stem(n,w_eg);
title('w_eg[n]');
