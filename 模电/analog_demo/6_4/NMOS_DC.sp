.title NMOS_DC

VVDS net2 0 DC 1.8V
VVGS net1 0 DC 0.75V
MNM0 net2 net1 0 0 n18 W=5u L=180n m=1

.op                                 * 打印直流工作点
.dc VVDS 0 1.8 0.1 VVGS 0 0.75 0.1  
                                    
.probe v(net2) v(net1) i(MNM0)

.temp 27
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end