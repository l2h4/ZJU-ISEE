clear;clc;close all;

a1=[1, -0.8];
b1=[2, 0, -1];

[H1, omega1]=freqz(b1,a1,4);
[H2, omega2]=freqz(b1,a1,4,"whole");
