%(2)
n1=-5:1:5;
w=-pi:0.001:pi;
X1=1-exp(-1j*w)+2*exp(-2j*w)-3*exp(-3j*w)+4*exp(-4j*w);

x1=1/(2*pi)*X1*exp(1i*w'*n1)*0.001;

figure(1);
stem(n1, x1);
title('x1');
xlabel('n');

%(6)
n2=-5:1:20;
X2=(1-exp(-1j.*w))./(1-5/6.*exp(-1j.*w)+1/6.*exp(-2j.*w));

x2=1/(2*pi)*X2*exp(1i*w'*n2)*0.001;

figure(2);
stem(n2,x2);
title('x2');
xlabel('n');
