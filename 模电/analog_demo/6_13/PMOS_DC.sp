.title PMOS_DC

MM3 4 4 5 5 p18 w=1u L=0.2u
MM2 3 4 5 5 p18 w=1u L=0.2u
MM1 3 2 1 1 n18 w=1u L=0.2u
R1 4 0 120k
CL 3 0 10p

VDD 5 0 DC 1.8V
VB 2 0 DC 0.7V
vvin 1 0 0.15

.op
.dc vvin 0 1.8 0.02
.probe dc v(3) v(1)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end