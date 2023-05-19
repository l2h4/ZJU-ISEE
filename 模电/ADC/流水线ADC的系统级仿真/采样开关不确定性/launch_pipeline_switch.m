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

%����˲��ĵ�ѹ��ȷ����
cst=2*pi*fin/1000;%�˴�K=1000

bits_number = 13;

open_system('Sampling_switch_uncertainty')

sim('Sampling_switch_uncertainty', 5000*ts);	% Starts Simulink simulation