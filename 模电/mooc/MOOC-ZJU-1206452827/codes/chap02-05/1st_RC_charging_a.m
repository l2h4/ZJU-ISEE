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
%　　　　参见PPT第3页

% charging
syms RC Vs s;

VS=Vs/s/(1+s*RC)

Vt=ilaplace(VS)