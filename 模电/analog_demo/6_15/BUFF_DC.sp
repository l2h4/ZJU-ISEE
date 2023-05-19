.title BUFF_DC

MM1 1 2 3 3 n18 W=0.4u L=0.2u
MM2 3 4 5 5 n18 W=0.4u L=0.2u
CL 3 0 1p

VDD 1 0 1.8V
VSS 0 5 1.8V
Vb  0 4 1.22V
vvin 2 0 0.3V

.op
.dc vvin 0 1.8 0.01
.probe dc v(3) v(1)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end