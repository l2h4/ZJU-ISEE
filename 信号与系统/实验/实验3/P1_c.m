clear;clc;close all;
nx1=0:1:24;
nh1=0:14;

x1=(1/2).^(nx1-2).*[(nx1-2)>=0];
h1=[(nh1+2)>=0];

y1=conv(x1,h1);
ny1=[0:24+14];

%
nx2=-50:50;
nh2=-20:20;

x2=(1/2).^(nx2-2).*[(nx2-2)>=0];
h2=[(nh2+2)>=0];

y2=conv(x2,h2);
y22=[y2(69:107)];
ny2=[0:38];

figure(1);
subplot(2,1,1);
stem(ny1,y1);
title('截断后卷积结果');
subplot(2,1,2)
stem(ny2,y22);
title('取较长区间的卷积结果');