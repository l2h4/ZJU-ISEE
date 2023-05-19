.title PMOS_DC

MM3 3 3 4 4 p18 w=1u L=0.2u
MM2 2 3 4 4 p18 w=1u L=0.2u
MM1 2 1 0 0 p18 w=1u L=0.2u
R1 3 0 120k

VDD 4 0 DC 1.8V
vvin 1 0 ac 1 0

.op
.dc vvin 0 1.8 0.1
.probe v(2)

.tran 1u 5m
.probe v(2) v(1)

.ac dec 10 10 1g
.probe vdb(2) vp(2)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end