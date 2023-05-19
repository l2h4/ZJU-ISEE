%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 　　　　模拟电路基础：                        
% 　　　　　　从系统级到电路级                  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 　　　　陈抗生　周金芳                        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 　　　　科学出版社　2020                      
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% using data exported to simout2 (digitized signal)
%
figure(2);clf;

fx = fin; N = nfft;
% freq vector
f = (0:N/2-1) / N;

% digitized signal of length N
y = simout2(1+10:N+10);

% spectral data
s = abs(fft(y) /N *2); s = s(1:N/2);
sdB=20*log10(s);f2=f(sdB>-200);sdB2=sdB(sdB>-200);

% plot spectral data
plot(f2, sdB2);
axis([0 0.5 -120 20]);
title('ADC Output Spectrum');
grid on

% compute SNDR
bx=N*fx/fs +1; As = 20*log10(s(bx));
s(bx) = 0; An=10*log10(sum(s.^2));
SNDR = As - An
ENOB = (SNDR - 1.76)/6.02

% anotate
s_temp = sprintf('SNDR = %4.2fdB, ENOB = %4.2f', SNDR, ENOB); 
text(0.11, 5, s_temp);

clear fx N f f2 y s sdB sdB2 bx As An s_temp;