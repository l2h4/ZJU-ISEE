clc;clear;close all;

syms ND;
NA=1.433*ND;
ni=2.4e13;
VD=0.0259*log((NA*ND)/(ni^2));
e=1.6e-19;
epr=16;
ep0=8.85e-12;
VR=5;

CB=sqrt((e*epr*ep0*NA*ND)/(2*(VD+VR)*(NA+ND)))-1.6e-5;

ans=solve(CB,ND)*10^(-6)

