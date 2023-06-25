clear;clc;close all;

%2.2 f到h

load plus.mat;

N=32;
wc=0.4;
n1=10;n2=4;n3=12;
d=6;
m=0:1:N-1;

[b1,a1]=butter(n1, wc);
a2=1; b2=firpm(n2, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);
a3=1; b3=firpm(n3, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);

%为在图像中看出区别，将每个像素点都乘以10
y1=filt2d(b1,a1,d,x);
figure(1);
image(10*y1);

y2=filt2d(b2, a2, d, x);
figure(2);
image(10*y2);

y3=filt2d(b3, a3, d, x);
figure(3);
image(10*y3);
