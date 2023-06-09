%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　模拟电路基础——从系统级到电路级             %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　　陈抗生　周金芳                       %
%++++++++++++++++++++++++++++++++++++++++++++++++%
% 　　　　 科学出版社　2020                      %
%++++++++++++++++++++++++++++++++++++++++++++++++%
%
% equation 1.4.25
%
syms R1 Rsc C1 C2 VS;
A = ...
    [1/R1+s*C1, -1/R1-s*C1, -1; ...
     -1/R1-s*C1, 1/R1+1/Rsc+s*C1+s*C2, 0; ...
     1, 0, 0];
B = [0; 0; VS];

% transpose of vector X is equal to [V1, V2, IS]
V = inv(A) * B;

V(2)