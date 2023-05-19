.title SHA

.include 'sample_switch.cdl'
.include 'OPA.cdl'

X1 1 2 3 4 5 6 OPAMP

X2 11 9 14 16 15 bootstrap

X3 12 10 14 16 15 bootstrap

X4 9 5 15 16 14 bootstrap

X5 10 6 15 16 14 bootstrap

X6 13 4 14 16 15 bootstrap

X7 13 3 14 16 15 bootstrap

X8 5 6 15 16 14 bootstrap

vin 11 0 sin(0 0.5 0.5 0 0 0 )
vip 12 0 sin(0 -0.5 0.5 0 0 0 )
vcm 13 0 0
VDD 3 0 DC 5
VSS 0 4 DC 5
VCLK 14 0 PULSE(0 3 0 0.1ns 0.1ns 100ms 200ms)
VCLKF 15 0 PULSE(0 3 100ms 0.1ns 0.1ns 100ms 200ms)
VD 16 0 DC 3
C1 9 1 5p
C2 10 2 5p
C3 5 0 10p
C4 6 0 10p

.op
.tran 1u 1
.probe tran  v(6) vin_1=par('v(11)-v(12)') vin_2=par('v(1)-v(2)') vout=par('v(5)-v(6)')

.temp 27								   
.option post accurate probe

.end