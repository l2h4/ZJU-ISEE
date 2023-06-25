clear;clc;close all;

n=0:1:20;
x=[(n-0)>=0];

%假设a为-3
a=[1, -5/6, 1/6];
b=[1, -3];

y=filter(b, a, x);
stem(y);