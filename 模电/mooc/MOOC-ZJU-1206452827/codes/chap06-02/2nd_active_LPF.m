﻿%-----------------------------------------------
% 　　　　模拟电路基础：                        
% 　　　　　　从系统级到电路级                  
%-----------------------------------------------
%　　　　陈抗生，周金芳                        
%　　　　科学出版社　2019                      
%-----------------------------------------------
%　　　　中国大学MOOC: 
%  https://www.icourse163.org/course/ZJU-1206452827
%-----------------------------------------------
%
%　　　　参见PPT第4页

syms R RF C s;
A = ...
    [1/R, -1/R, 0, 0, 0, 0, -1; ...
     -1/R, 2/R+s*C, -1/R, -s*C, 0, 0, 0; ...
     0, -1/R, 1/R+s*C, 0, 0, 0, 0; ...
     0, -s*C, 0, s*C+1/RF, -1/RF, 1, 0; ...
     0, 0, 0, -1/RF, 1/R+1/RF, 0, 0; ...
     0, 0, 1, 0, -1, 0, 0; ...
     1, 0, 0, 0, 0, 0, 0];
B = [0; 0; 0; 0; 0; 0; 1];

V = inv(A) * B;

H = V(4)