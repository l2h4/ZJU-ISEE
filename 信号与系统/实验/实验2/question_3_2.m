alpha=0.5;
N=1000;
n=[0:1000];
b=[1];
a=[1,zeros(1,N-1),alpha];
d=[1,zeros(1,4000)];
her=filter(b,a,d);

load lineup.mat;
z=filter(b,a,y);
subplot(2,1,1)
stem(z);
subplot(2,1,2)
stem(y);

sound(y,8192);
sound(z,8192);