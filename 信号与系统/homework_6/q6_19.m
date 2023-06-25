clear;clc;close all;

syms s;
Vzi=4/(s+1)-3/(s+2);
Vzs=1/((1/2*s^2+3/2*s+1)*(s+3));

vc=ilaplace(Vzi)+ilaplace(Vzs)
