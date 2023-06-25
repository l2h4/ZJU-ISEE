w=-20:0.1:20;
n=-5:1:1000;
u=[(n-1)>=0];

%(1)
x1=3*(1/3).^n.*u;

y1=x1*exp(-1j*n'*w);
y1_Re=real(y1);
y1_Im=imag(y1);

figure(1);
subplot(2,1,1);
plot(w,y1_Re);
title('F变换实部');
xlabel('\omega');
ylabel('y1_{Re}');
subplot(2,1,2);
plot(w,y1_Im);
title('F变换虚部');
xlabel('\omega');
ylabel('y1_{Im}');

%(4)
y2=exp(-1j*3*w);
y2_Re=real(y2);
y2_Im=imag(y2);

figure(2);
subplot(2,1,1);
plot(w,y2_Re);
title('F变换实部');
xlabel('\omega');
ylabel('y2_{Re}');
subplot(2,1,2);
plot(w,y2_Im);
title('F变换虚部');
xlabel('\omega');
ylabel('y2_{Im}');

%(11)
x3=[1 1 1 1 1];
n=[0 1 2 3 4];

y3=x3*exp(-1j*n'*w);
y3_Re=real(y3);
y3_Im=imag(y3);

figure(3);
subplot(2,1,1);
subplot(2,1,1);
plot(w,y3_Re);
title('F变换实部');
xlabel('\omega');
ylabel('y3_{Re}');
subplot(2,1,2);
plot(w,y3_Im);
title('F变换虚部');
xlabel('\omega');
ylabel('y3_{Im}');