syms wc;
W=2.*pi;
T=10*(2.*pi/W);
w1=linspace(-3*W, 1.5*W, 512);
H=0.5*((sign(w1+eps+3*W)+1)-(sign(w1+eps-3*W)+1));

t=linspace(-10*T/2, 10*T/2, 512);
x=0.5*((sign(t+eps+3*T/2.0)+1.)-(sign(t+eps-3*T/2.0)+1.));

N=length(t); y1=zeros(1,N);y2=zeros(1,N);y3=zeros(1,N);
for k=1:N
    y1(k)=quadl(@XHforRect1,-W,W,[],[],t(k),T,W);
    y2(k)=quadl(@XHforRect2,-W,W,[],[],t(k),T,W);
    y3(k)=quadl(@XHforRect3,-W,W,[],[],t(k),T,W);
end

y=y1+y2+y3;
plot(t,y);
