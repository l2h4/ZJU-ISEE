clear;clc;close all;

t=0:0.1:100;
s=-2:0.1:100;

%(1)
figure(1);
x1=exp(-2.*t).*[(t+1)>0];
X1=x1*exp(-t'*s)*0.1;
plot(s,X1);

%(2)
figure(2);
x2=exp(-2*(t+3)).*[(t+1)>0];
X2=x2*exp(-t'*s)*0.1+1;
plot(s,X2);