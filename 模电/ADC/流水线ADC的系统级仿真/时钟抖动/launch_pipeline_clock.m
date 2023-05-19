%++++++++++++++++++++++++++++++++++++++++++++++++%
% ����ģ���·����������ϵͳ������·��             %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% �����������¿������ܽ�                       %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% �������� ��ѧ�����硡2020                      %
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

%clock jitter
meanvalue=0.01;
variance=1e-30;

bits_number = 13;

open_system('clock_jitter')

sim('clock_jitter', 5000*ts);	% Starts Simulink simulation