.title NMOS_DC

.param W1=5u
VVDS net2 0 DC 1.8V
VVGS net1 0 DC 0.75V
MNM0 net2 net1 0 0 n18 W=W1 L=180n m=1

.op
.dc VVDS 0 1.8 0.1 W1 5u 25u 5u

.probe i(MNM0)

.temp 27
.option post accurate probe
.print gm=lx7(MNM0) gds=lx8(MNM0) cgs=lx20(MNM0) cgd=par('-lx19(MNM0)')
.lib '..\models\ms018.lib' tt

.end