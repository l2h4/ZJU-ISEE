NA=1:1:1000;
NA=NA*10^15;

k=0.0259;
Jl=300e-3;
ND=1e19;
Dn=225;
Dp=7;
tn=5e-8;
tp=5e-8;
e=1.6e-19;
ni=1.8e6;

Ln=sqrt(tn*Dn);
Lp=sqrt(tp*Dp);
Js=e.*ni.^2.*(Dn./(Ln.*NA)+Dp./(Lp.*ND));

Voc=k.*log(Jl./Js+1);

plot(NA, Voc);
xlabel('N_A');
ylabel('V_{oc}');