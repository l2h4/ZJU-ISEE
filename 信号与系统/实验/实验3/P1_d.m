clear;clc;close all;

n=0:99;
h=0.9.^n.*([(n-0)>=0]-[(n-10)>=0]);
x=cos(n.^2).*sin(2*pi*n./5);

y=conv(h,x);
ny=0:99*2;

stem(ny,y);