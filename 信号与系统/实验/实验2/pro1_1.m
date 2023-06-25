clear all;
clc;

n=[0:5];
x1=[n==0];
x2=[n==1];
x3=x1+2*x2;

%system 1
a=[1];
b=[1 -1 -1];

w1=filter(b,a,x1);
subplot(4,1,1);
stem(n,w1);
title('w_1[n]');

w2=filter(b,a,x2);
subplot(4,1,2);
stem(n,w2);
title('w_2[n]');

w3=filter(b,a,x3);
subplot(4,1,3);
stem(n,w3);
title('w_3[n]');

subplot(4,1,4);
stem(n,w1+2*w2);
title('w_1[n]+2w_2[n]');


