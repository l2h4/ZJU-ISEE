%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　模拟电路基础——从系统级到电路级             %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　　陈抗生　周金芳                       %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　 科学出版社　2020                      %
%++++++++++++++++++++++++++++++++++++++++++++++++%
%
% figure 1.4.8
%
sigma = 0:0.1:5;
omega = -20:0.1:20;
[sigma omega] = meshgrid(sigma, omega);

s = sigma + i* omega;
Fs = abs((1-exp(-2*s))./s);

meshc(sigma, omega, Fs);
view(-50,20);
axis([0, 5, -20, 20, 0, 2]);