.title BUFF_TRAN

MM1 1 2 3 3 n18 W=0.4u L=0.2u
MM2 3 4 5 5 n18 W=0.4u L=0.2u

VDD 1 0 1.8V
VSS 0 5 1.8V
Vb  0 4 1.22V
vvin 2 0 sin(0.3 0.001 1K 0 0 0)

.tran 1u 5m
.probe v(3) v(2)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end