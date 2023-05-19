%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　模拟电路基础——从系统级到电路级             %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　　陈抗生　周金芳                       %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　 科学出版社　2020                      %
%++++++++++++++++++++++++++++++++++++++++++++++++%
%
% 12bit pipeline ADC
%
clear;

fs=1;
ts=1/fs;

fin_pre=0.1;
nfft=2048;
fin=antismear(fin_pre,fs,nfft);

%采样瞬间的电压不确定性
cst=2*pi*fin/1000;%此处K=1000

bits_number = 13;

open_system('Sampling_switch_uncertainty')

sim('Sampling_switch_uncertainty', 5000*ts);	% Starts Simulink simulation