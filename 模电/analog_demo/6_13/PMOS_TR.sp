.title PMOS_DC

MM3 4 4 5 5 p18 w=1u L=0.2u M=1
MM2 3 4 5 5 p18 w=1u L=0.2u M=1
MM1 3 2 1 1 n18 w=1u L=0.2u M=1
R1 4 0 120k

VDD 5 0 DC 1.8V
VB 2 0 DC 0.7V
vvin 1 0 sin(0.15 0.001 1K 0 0 0)

.tran 1u 5m
.probe v(3) v(1)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end