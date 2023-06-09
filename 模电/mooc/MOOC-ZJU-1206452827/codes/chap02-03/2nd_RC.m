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
%　　　　参见PPT第13页

% with R1=R2=100, C1=1uF, C2=0.01uF
R1=100; R2=100; C1=1e-6; C2=0.01e-6; 
vi=1;   % vi = u(t)

% simulation time: 1ms;  time step: 0.01ms
t_total=1e-3; dt=0.01e-3;
A = ...
    [1/R1, -1/R1, 0, -1; ...
     -1/R1, 1/R1+1/R2+C1/dt, -1/R2, 0; ...
     0, -1/R2, 1/R2+C2/dt, 0; ...
     1, 0, 0, 0];
% zero state
t(1)=0; X(:,1) = [0, 0, 0, 0];

t_steps=t_total/dt; 
for n=1:1:t_steps
	B = [0; C1/dt*X(2,n); C2/dt*X(3,n); vi];
	t(n+1) = dt*n;
	X(:,n+1) = A \ B;   	
end

vo = X(3,:); plot(t, vo); grid on;
xlabel('Time, s'); ylabel('vo, V');