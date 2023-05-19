.title OPA_AC

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
vvin 4 0 DC 0.9V AC 1 0.8
vvip 3 0 DC 0.9V

.ac dec 10 10 1g
.probe vdb(2) vp(2)

.temp 27								
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end