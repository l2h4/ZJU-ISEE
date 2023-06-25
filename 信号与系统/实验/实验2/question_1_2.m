%系统2
n=[0:5];
x1=[(n-0)==0];
x2=[(n-1)==0];
x3=[(n-0)==0]+2*[(n-1)==0];

%系统2输出
y1=cos(x1/pi*180);
y2=cos(x2/pi*180);
y3=cos(x3/pi*180);

%线性系统验证
yeg=y1+2.*y2;

%绘图
subplot(4,1,1);
stem(n,y1);
title('y_1[n]');
subplot(4,1,2);
stem(n,y2);
title('y_2[n]');
subplot(4,1,3);
stem(n,y3);
title('y_3[n]');
subplot(4,1,4);
stem(n,yeg);
title('y_eg[n]');