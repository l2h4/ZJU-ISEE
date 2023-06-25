syms x t;
x=exp(1j*2*pi*t/16)+exp(1j*2*pi*t/8);

x_Re=sreal(x);
x_Im=simag(x);

subplot(2,1,1);
fplot(x_Re,[0 32]);
title('X_{Re}');
xlabel('t');
ylabel('x_{Re}[t]');

subplot(2,1,2);
fplot(x_Im,[0 32]);
title('X_{Im}');
xlabel('t');
ylabel('x_{Im}[t]');
