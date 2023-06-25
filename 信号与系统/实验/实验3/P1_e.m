clear;clc;close all;

n=0:99;
L=50;
h=0.9.^n.*([(n-0)>=0]-[(n-10)>=0]);
nx1=0:49;
x1=cos(nx1.^2).*sin(2*pi*nx1./5);
nx2=L:99;
x2=cos(nx2.^2).*sin(2*pi*nx2./5);

y1=conv(h,x1);
y2=conv(h,x2);

y=y1+[zeros(1,L), y2(1:end-L)];
ny=0:length(y1)-1;

stem(ny,y);
