clear;clc;close all;

% a=[11 2 5];
% b=[2 3];
% sys=tf(b, a);

syms s;
sys=(2*s+3)/(1*s^2+2*s+5);

%(1)
% X1=tf(1, [1 0]);
X1=1/s;
Y1=X1*sys;
y1=ilaplace(Y1)

%(2)
X2=1/(s+1);
Y2=X2*sys;
y2=ilaplace(Y2)