clear;clc;close all;

syms s;

%(1)
X1=1./(s^2+4);
x1=ilaplace(X1)

%(2)
X2=1./(s+1);
x2=ilaplace(X2)

%(3)
X3=s./(s^2+25);
x3=ilaplace(X3)

%(5)
X5=(s+1)./(s^2+5*s+6);
x5=ilaplace(X5)