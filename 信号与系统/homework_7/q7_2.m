clear;clc;close all;

syms z a;

%(3)
X3=(1-1/2*z^(-1))/(1+3/4*z^(-1)+1/8*z^(-2));
x3=iztrans(X3)

%(4)
X4=(z-a)/(1-a*z);
x4=iztrans(X4, z)

%(7)
X7=(z^2-a*z)/(z-a)^3;
x7=iztrans(X7,z)
