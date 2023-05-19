**************************************************
* ����ģ���·����������ϵͳ������·��             *
**************************************************
* �����������¿������ܽ�                       *
**************************************************
* �������� ��ѧ�����硡2020                      *
**************************************************

.title CS_amp_AC

.include 'CS_amp.cdl'

x1 GNDA VDDA vin vout Vbias CS_AMP
c10 vout 0 1p

vvdda VDDA 0 1.8
vgnda GNDA 0 0
vvbias Vbias 0 1.2
vvin vin 0 0.5 ac 1 0

.ac dec 10 10 1g			  *�������棬��10Hz��1GHz��ÿ10��Ƶ��ɨ��10����
.noise v(vout) vvin 10	*�����Ч�����������������
.probe vdb(vout) vp(vout)		*��ӡ�����Ƶ����
.probe inoise onoise				*��ӡ��������͵�Ч��������

.temp 27								
.option post accurate probe
.lib '..\models\ms018.lib' tt

.end