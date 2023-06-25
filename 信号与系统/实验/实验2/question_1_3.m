%系统3
n=[0:5];
x1=[(n-0)==0];
x2=[(n-1)==0];
x3=[(n-0)==0]+2*[(n-1)==0];

%系统3输出
y1=n.*x1;
y2=n.*x2;
y3=n.*x3;

%线性系统验证
yeg=y1+2.*y2;

%绘图
subplot(4,1,1);
stem(n,y1);
title('z_1[n]');
subplot(4,1,2);
stem(n,y2);
title('z_2[n]');
subplot(4,1,3);
stem(n,y3);
title('z_3[n]');
subplot(4,1,4);
stem(n,yeg);
title('z_eg[n]');