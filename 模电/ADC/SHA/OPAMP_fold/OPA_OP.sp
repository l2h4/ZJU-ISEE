.title OPA_open_loop

.include 'OPA.cdl'

x1 1 2 3 4 5 6 OPAMP
*1 VDD
*2 VSS
*3 Vip
*4 Vin
*5 Vop
*6 Von

VDD 1 0 DC 2.5
VSS 0 2 DC 2.5
vvip 3 0 DC 0 AC 1
vvin 4 0 DC 0
C1 2 0 10p
C2 6 0 10p

.op											   * 分析电路直流工作点
.tf v(6) vvip		    		   * 计算小信号传输函数
.dc vvip -0.05 0.05 100U * 直流仿真，设置扫描变量
.probe dc v(6)						 * 观察输出翻转


.temp 27								   
.option post accurate probe

.end