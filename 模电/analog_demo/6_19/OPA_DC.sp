.title OPA_DC

.include 'OPA.cdl'

x1 1 2 3 4 5 6 OPAMP
* 1 VDD
* 2 vout
* 3 vip
* 4 vin
* 5 Vb
* 6 VGOUND

VDD 1 0 1.8V
Vb  5 0 0.5V
VGND 6 0 DC 0
vvin 4 0 DC 0.8V
vvip 3 0 DC 0.8V
CL 2 0 1p

.op
.dc vvin -0.5 0.5 100U
.probe dc v(2)

.temp 27								
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end