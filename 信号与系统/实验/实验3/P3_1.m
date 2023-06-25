clear;clc;close all;

%3 a到c

a=[2*exp(-pi/3j) 0 exp(-pi/4j) 0 1 0 exp(pi/4j) 0 2*exp(pi/3j)];
N=5;

k=-4:1:4;
n=-20:1:20;

x=a*exp(1i*k'*n*2*pi/N);

figure(1)
subplot(2,1,1);
stem(n,real(x));
ylabel('real(x)');
title('x[n]实部');
subplot(2,1,2);
stem(n,imag(x));
ylabel('imag(x)');
title('x[n]虚部');
