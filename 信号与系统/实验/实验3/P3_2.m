clear;clc;close all;

%3 d到f
%%
n=0:1:63;
N1=8; N2=16; N3=32;

x1n=ones(1,8);
x1=ones(1,64);
x2n=[ones(1,8) zeros(1,8)];
x2=[x2n x2n x2n x2n];
x3n=[ones(1,8) zeros(1,24)];
x3=[x3n x3n];

%%
%d问：构建三个序列
figure(1);
subplot(3,1,1);
stem(n,x1);
title('x1');
subplot(3,1,2);
stem(n,x2);
title('x2');
subplot(3,1,3);
stem(n,x3);
title('x3');

%%
%e问：求三个序列的DTFS系数
a1=(1/N1)*fft(x1n);
a2=(1/N2)*fft(x2n);
a3=(1/N3)*fft(x3n);

s1=sum(x1n)/N1;
s2=sum(x2n)/N2;
s3=sum(x3n)/N3;

figure(2);
subplot(2,1,1);
stem(real(a1));
title('a1实部');
subplot(2,1,2);
stem(imag(a1));
title('a1虚部');

figure(3);
subplot(2,1,1);
stem(real(a2));
title('a2实部');
subplot(2,1,2);
stem(imag(a2));
title('a2虚部');

figure(4);
subplot(2,1,1);
stem(real(a3));
title('a3实部');
subplot(2,1,2);
stem(imag(a3));
title('a3虚部');

%%
%f问：不同k值得到的x3还原结果
k2=0:4;
x32=a3(1:5)*exp(1i*k2'*n*2*pi/N3);

k8=0:16;
x38=a3(1:17)*exp(1i*k8'*n*2*pi/N3);

k12=0:24;
x312=a3(1:25)*exp(1i*k12'*n*2*pi/N3);

kall=0:31;
x3all=a3*exp(1i*kall'*n*2*pi/N3);

figure(5)
subplot(4,1,1)
stem(n,x32);
title('x3_2');
subplot(4,1,2);
stem(n,x38);
title('x3_8');
subplot(4,1,3);
stem(n,x312);
title('x3_{12}');
subplot(4,1,4);
stem(n,x3all);
title('x3_{all}');

%%
%验证x3all为实数序列
figure(6);
subplot(2,1,1)
stem(n,real(x3all));
title('x3_{all}实部');
subplot(2,1,2);
stem(n,imag(x3all));
title('x3_{all}虚部');


