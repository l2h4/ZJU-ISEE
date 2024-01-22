%已知参数
syms L;
x=0:100;
l=x*10^(-9);
z0=50;
r1=8.56;
r2=8.56;
r3=141.8;
f=2e9;

%输入阻抗
zin=z0+r1+1./(1./(1i.*2.*pi.*f.*l+r3)+1./(r2+z0));
zin1=z0+r1+1./(1./(1i.*2.*pi.*f.*L+r3)+1./(r2+z0));

%S11参数
S11_1=(zin1-z0)./(zin1+z0);
simplify(abs(S11_1))
gin=(zin-z0)./(zin+z0);
S11=20*log10(abs(gin));
figure(1);
plot(x,S11);
title("S11参数变化曲线");
xlabel("L/nH");
ylabel("S11(dB)");

%S21参数
S21=-10.*log10(1-abs(gin).^2);
figure(2);
plot(x,S21);
title("S21参数变化曲线");
xlabel("L/nH");
ylabel("S21(dB)");