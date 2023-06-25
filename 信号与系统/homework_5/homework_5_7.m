T=2;
D=1.5;
a=D/(T+D);
A=1;B=1;
p=pi/3;

t=-100:0.1:100;
x=x_5_7(A, B, t, T/a, p);

s=-100*(T+D):T+D:100*(T+D);
n=-100:1:100;
w=-50:0.1:50;
y=x_5_7(A, B, s, T, p);
Y=y*exp(-1j*n'*w*(T+D));

Xa=Y.*(heaviside(w+2)-heaviside(w-2));
xa=1/(2*pi)*Xa*exp(1i*w'*n)*0.1;

figure(1);
subplot(2,1,1);
plot(t,x);
title('x(at)');
xlabel('t');
%画出的图像由于t取值的限制会有一定的失真，但可以看出其为正比
subplot(2,1,2);
plot(n,xa);
title('x_r(t)');
xlabel('t');
