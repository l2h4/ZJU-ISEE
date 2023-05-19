.title PMOS_DC

MM3 4 4 5 5 p18 w=1u L=0.2u
MM2 3 4 5 5 p18 w=1u L=0.2u
MM1 3 2 1 1 n18 w=1u L=0.2u
R1 4 0 120k

VDD 5 0 DC 1.8V
VB 2 0 DC 0.7V
vvin 1 0 0.15 ac 0.151 0.149

.ac dec 10 10 1g
.probe vdb(3) vp(3)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end