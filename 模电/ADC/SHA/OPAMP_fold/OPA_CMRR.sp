.title OPA_open_loop

.include 'OPA.cdl'

x1 1 2 3 4 5 6 OPAMP
*1 VDD
*2 VSS
*3 Vip
*4 Vin
*5 Vop
*6 Von

VDD 1 0 DC 5
VSS 0 2 DC 5
C1 2 0 10p
C2 6 0 10p

.PARAM VCM=1
VCM1 3 0 DC 0 AC VCM
VCM2 4 6 DC 0 AC VCM 

.ac dec 10 1 1g
.probe ac vdb(6) vp(6)
.probe ac cmrr_db=par('- vdb(6)') cmrr_phase=par('- vp(6)')


.temp 27								   
.option post accurate probe

.end