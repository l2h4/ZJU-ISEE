.title OPA_open_loop

.include 'OPA.cdl'

x1 1 2 3 4 5 6 OPAMP
*1 vin
*2 vip
*3 VDD
*4 VSS
*5 vop
*6 von
VDD 3 0 DC  5
VSS 0 4 DC  5
vip 2 0 DC 0 AC 1
vin 1 0 DC 0 AC -1
C3 5 0 10P
C4 6 0 10p

.op
.ac dec 10 1 1g
.print ac vdb(5) vp(5) vdb(6) vp(6)

.temp 27								   
.option post accurate probe

.end