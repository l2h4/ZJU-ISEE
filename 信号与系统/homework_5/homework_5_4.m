t=-10:0.01:10;
n=-1000:1:1000;
T=0.2;
y=0;
u1=[(t+T)>=0]-[(t-0)>=0];
u2=[(t-0)>=0]-[(t-T)>=0];
x=cos(2*pi*n*T);

for i=1:2001
    y=y+x(i)*h_5_4(t-n(i)*T,T);
end

figure(1);
title('x_r(t)');
xlabel('t');
plot(t,y);
