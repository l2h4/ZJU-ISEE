clear;clc;close all;

syms t;

%(3)
x3=4*sin(pi*(t-3))*heaviside(t-3);
X3=laplace(x3)

%(6)
x6=diff(cos(10*pi*t)*heaviside(t));
X6=laplace(x6)