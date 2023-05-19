**************************************************
* ����ģ���·����������ϵͳ������·��             *
**************************************************
* �����������¿������ܽ�                       *
**************************************************
* �������� ��ѧ�����硡2020                      *
**************************************************

.title CS_amp_TRAN

.include 'CS_amp.cdl'

x1 GNDA VDDA vin vout Vbias CS_AMP
c10 vout 0 1p

vvdda VDDA 0 1.8
vgnda GNDA 0 0
vvbias Vbias 0 1.2
vvin vin 0 sin(0.5 0.001 1k 0 0 0)

.tran 1u 5m					*˲̬���棬����1us����ʱ��5ms
.probe v(vin) v(vout)		*��ӡvin��vout�ڵ��ѹ

.temp 27						
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end