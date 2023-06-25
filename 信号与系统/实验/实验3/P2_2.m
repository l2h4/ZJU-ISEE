clear;clc;close all;

%2.2 a到c

wc=0.4;
n1=10;n2=4;n3=12;

[b1,a1]=butter(n1, wc);
a2=1; b2=firpm(n2, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);
a3=1; b3=firpm(n3, [0 wc-0.04 wc+0.04 1],[1 1 0 0]);

N=1000;
[H1, omega1]=freqz(b1, a1, N);
[H2, omega2]=freqz(b2, a2, N);
[H3, omega3]=freqz(b3, a3, N);

figure(1);
subplot(2,1,1)
plot(omega1./pi, mag2db(abs(H1)));
title('幅频特性');
subplot(2,1,2)
plot(omega1./pi,unwrap(phase(H1)));
title('相频特性');

figure(2)
subplot(2,1,1)
plot(omega2./pi,mag2db(abs(H2)));
title('幅频特性');
subplot(2,1,2)
plot(omega2./pi,unwrap(phase(H2)));
title('相频特性');

figure(3)
subplot(2,1,1)
plot(omega3./pi,mag2db(abs(H3)));
title('幅频特性');
subplot(2,1,2)
plot(omega3./pi,unwrap(phase(H3)));
title('相频特性');

n=0:1:20;
x=[(n-0)>=0];

y1=filter(b1, a1, x);
y2=filter(b2, a2, x);
y3=filter(b3, a3, x);

figure(4);
subplot(3,1,1)
stem(n,y1);
title('滤波器1的阶跃响应');
subplot(3,1,2)
stem(n,y2);
title('滤波器2的阶跃响应');
subplot(3,1,3)
stem(n,y3);
title('滤波器3的阶跃响应');

