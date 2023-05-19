﻿*-----------------------------------------------
* 　　　　模拟电路基础：                        
* 　　　　　　从系统级到电路级                  
*-----------------------------------------------
*　　　　陈抗生，周金芳                        
*　　　　科学出版社　2019                      
*-----------------------------------------------
*　　　　中国大学MOOC: 
*  https://www.icourse163.org/course/ZJU-1206452827
*-----------------------------------------------
*
*　　　　参见PPT第14页

.title OPAMP_DC

* 1 vip * 2 vin * 6 vout * 8 VDD * 9 VSS
M1 4 2 3 3 n08 W = 8U   L = 1U AD = 48P   AS = 48P   PD = 28U PS = 28U 
M2 5 1 3 3 n08 W = 8U   L = 1U AD = 48P   AS = 48P   PD = 28U PS = 28U 
M3 4 4 8 8 p08 W = 23U  L = 1U AD = 138P  AS = 138P  PD = 58U PS = 58U 
M4 5 4 8 8 p08 W = 23U  L = 1U AD = 138P  AS = 138P  PD = 58U PS = 58U 
M5 3 7 9 9 n08 W = 4U   L = 1U AD = 24P   AS = 24P   PD = 20U PS = 20U 
M6 6 5 8 8 p08 W = 190U L = 1U AD = 1140P AS = 1140P PD = 392U PS =392U
M7 6 7 9 9 n08 W = 17U  L = 1U AD = 102P  AS = 102P  PD = 46U PS = 46U 
M8 7 7 9 9 n08 W = 4U   L = 1U AD = 24P   AS = 24P   PD = 20U PS = 20U 
CC 5 6 3.0P
IBIAS 8 7 45U

VDD 8 0 DC  2.5
VSS 0 9 DC  2.5
vvip 1 0 DC 0
vvin 2 0 DC 0

.OP										 * 直流工作点仿真

.MODEL n08 NMOS VTO = 0.70 KP = 110U GAMMA = 0.4  LAMBDA = 0.04 
+ PHI = 0.7 MJ = 0.5 MJSW = 0.38 CGBO = 700P CGSO = 220P CGDO = 220P 
+ CJ = 770U CJSW = 380P LD = 0.016U TOX = 14N
.MODEL p08 PMOS VTO = -0.70 KP = 50U GAMMA = 0.57 LAMBDA = 0.05 
+ PHI = 0.8 MJ = 0.5 MJSW = 0.35 CGBO = 700P CGSO = 220P CGDO = 220P 
+ CJ = 560U CJSW = 350P LD = 0.014U TOX = 14N

.end