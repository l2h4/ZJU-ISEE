n=0:1:23;
k=0:1:7;
ak=sin(k*pi/4);

x=ak*exp((1i*2*pi/8).*(k'*n));

subplot(2,1,1);
y1=real(x);
stem(n,y1);
title('x[n]的实部');
xlabel('n');
ylabel('x[n]_{Re}');

subplot(2,1,2);
y2=imag(x);
stem(n,y2);
title('x[n]的虚部');
xlabel('n');
ylabel('x[n]_{Im}')
