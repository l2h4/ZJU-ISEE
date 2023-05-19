.title switch_test
.include 'sample_switch.cdl'
x1 1 3 4 5 6 bootstrap
* 1 vdd
* 3 vin
* 4 out
* 5 clk
* 6 clkb

VDD 1 0 3
vclk 5 0 PULSE (0 3 0 0.1ns 0.1ns 10ms 20ms)
vclkb 6 0 PULSE (0 3 10ms 0.1ns 0.1ns 10ms 20ms)
vin 3 0 sin (0 0.5 0.5 0 0 0 )

.tran 1u 1
.probe tran v(3) v(4) v(5)


.temp 75
.option post accurate probe
.end