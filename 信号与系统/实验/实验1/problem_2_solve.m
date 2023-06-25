N=6;
n1=0:1:24;
n2=n;
n3=0:1:48;

x1=cos(2.*pi.*n1./N)+2.*cos(3.*pi.*n1./N);
x2=2.*cos(2.*n2./N)+2.*cos(3.*n2./N);
x3=cos(2.*pi.*n3./N)+3.*sin(5.*pi.*n3./(2.*N));

subplot(3, 1, 1);
stem(n1,x1);
title('cos(2\pin/N)+2cos(3\pin/N)');
ylabel('x_1[n]');
xlabel('n');
grid on;

subplot(3, 1, 2);
stem(n2,x2);
title('2cos(2n/N)+2cos(3n/N)');
ylabel('x_2[n]');
xlabel('n');
grid on;

subplot(3, 1, 3);
stem(n3, x3);
title('cos(2\pin/N)+3sin(5\pin/(2N))');
ylabel('x_3[n]');
xlabel('n');
grid on;