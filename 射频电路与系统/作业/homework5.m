%已知参数
omega=0:0.1:1000;
omega_g=omega.*10^6;
r1=50;
r2=40;
r3=50;
c=2e-12;

%transfer function
H=1./(1+(1./(1i.*omega_g.*c)+r1).*(1/r2+1/r3));
Hr=20*log10(abs(H));
figure(1);
plot(omega,Hr);
title("H(\omega)幅频特性");
xlabel("\omega(MHz)");
ylabel("H(\omega)(dB)");

%Attenuation factor
a=-log(abs(H));
figure(2);
plot(omega,a);
title("\alpha (\omega)");
xlabel("\omega(MHz)");
ylabel("\alpha (\omega)");

%Corresponding phase
phi=atan(imag(H)./real(H));
figure(3);
plot(omega,phi);
title("\phi (\omega)");
xlabel("\omega(MHz)");
ylabel("\phi (\omega)");

%Group delay
aphi=diff(phi);
aw=diff(omega);
tg=aphi./aw;
figure(4);
plot(omega(1:end-1),tg);
title("t_g (\omega)");
xlabel("\omega(MHz)");
ylabel("t_g (\omega)");



