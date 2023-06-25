clear;clc;close all;

%2.2 d到e

load plus.mat;

N=32;
wc=0.4;
n1=10;n2=4;n3=12;
d=6;
m=0:1:N-1;

[b1,a1]=butter(n1, wc);
a2=1; b2=firpm(n2, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);
a3=1; b3=firpm(n3, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);

x16=x(:, 16);

y161=filter(b1,a1,[x16;zeros(d,1)]);
y162=filter(b2,a2,[x16;zeros(d,1)]);
y163=filter(b3,a3,[x16;zeros(d,1)]);

figure(1);
subplot(4,1,1)
stem(m,y161(d:end-1));
title('滤波器1输出');
subplot(4,1,2)
stem(m,y161(d:end-1));
title('滤波器2输出');
subplot(4,1,3);
stem(m,y161(d:end-1));
title('滤波器3输出');
subplot(4,1,4)
stem(m,x16);
title('图像第16列输入');
