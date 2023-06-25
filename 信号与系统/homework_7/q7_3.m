clear;clc;close all;

syms n;

%(1)
x1=(-1)^n*n;
X1=ztrans(x1)

%(5)
x5=(n+1)*(heaviside(n)-heaviside(n-3))*(heaviside(n)-heaviside(n-4));
X5=ztrans(x5)