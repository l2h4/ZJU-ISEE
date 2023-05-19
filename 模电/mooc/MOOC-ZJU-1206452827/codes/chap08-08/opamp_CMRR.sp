*-----------------------------------------------
* ��������ģ���·������                        
* ��������������ϵͳ������·��                  
*-----------------------------------------------
*���������¿������ܽ�                        
*����������ѧ�����硡2019                      
*-----------------------------------------------
*���������й���ѧMOOC: 
*  https://www.icourse163.org/course/ZJU-1206452827
*-----------------------------------------------
*
*���������μ�PPT��23ҳ

.title OPAMP_CMRR

.include 'OPA.cdl'

X1 1 2 3 4 5 OPAMP
* 1 vip  * 2 vin  * 3 vout  * 4 VDD  * 5 VSS
VDD 4 0 DC  2.5 
VSS 0 5 DC  2.5
CL 3 0 10P

.PARAM VCM=1
Vcm1 1 0 DC 0 AC VCM
Vcm2 2 3 DC 0 AC VCM 

.AC dec 10 10 1g
.probe ac vdb(3) vp(3)
.probe ac cmrr_db=par('- vdb(3)') cmrr_phase=par('- vp(3)')
* Vout / Vcm = 1 / CMRR		
* cmrr_db = - (vdb(3))   	����������������
* cmrr_phase = - (vp(3))  ����������������
						
.option post probe

.end