w=-pi:0.001:pi;
n=-1000:1:1000;
u=1/2*[(w+pi/2)==0];
H=heaviside(w+pi/2)-heaviside(w-pi/2)+u;

X=(1-2/pi*abs(w)).*H;

x=1/(2*pi)*X*exp(1i*w'*n)*0.001;

%1
x1=x.*cos(pi*n);
y1=x1*exp(-1j*n'*w);

figure(1);
plot(w,y1);
title('一个周期内的调制图像');
xlabel('\omega');
ylabel('y_1');

%2
x2=x.*cos(pi/2*n);
y2=x2*exp(-1j*n'*w);

figure(2);
plot(w,y2);
title('一个周期内的调制图像');
xlabel('\omega');
ylabel('y_2');

%3
k3=zeros(1,2001);
for m=1:2001
    if rem(m,2)~=0
        k3(m)=1;
    end
end
x3=x.*k3;
y3=x3*exp(-1j*n'*w);

figure(3);
plot(w,y3);
title('一个周期内的调制图像');
xlabel('\omega');
ylabel('y_3');

%4
k4=zeros(1,2001);
for m=1:2001
    if rem(m,4)==1
        k4(m)=1;
    end
end

x4=x.*k4;
y4=x4*exp(-1j*n'*w);

figure(4);
plot(w,y4);

