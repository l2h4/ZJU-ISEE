.title NP_DC

MM1 2 1 0 0 n18 W=0.4u L=0.2u
MM2 4 3 2 2 n18 W=0.4u L=0.2u
MM3 4 5 6 6 p18 W=0.4u L=0.2u
CL 4 0 1p

VDD 6 0 1.8V
Vibs1 5 0 0.9V
Vibs2 3 0 1.2V
vvin 1 0 0.64V

.op
.dc vvin 0 1.8 0.01
.probe dc v(1) v(4)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end