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

% charging 
% with normalized RC and Vs
RC=1;Vs=1;
syms s;

VS=Vs/s/(1+s*RC);

Vt=ilaplace(VS);

ezplot(Vt, [0, 10]);ylim([0 1]);grid on;