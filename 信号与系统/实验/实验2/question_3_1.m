%差分方程参数设置
alpha=0.5;
N=1000;
n=[0:1000];
a=[1];
b=[1,zeros(1,N-1),alpha];
fn=[(n-0)==0];

%单位冲激响应
he=filter(b,a,fn);
stem(n,he);
title('he');