//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  
//  ���δ�����2018��4��8�գ�����<<�������ר��>>�γ̽�ѧ
//            ��ʾ���ݣ�
//            1. ��ŵ���������
//            2. libgraphics����
//            3. ���ڶ�ջ�ĵݹ�ʵ��
//            
//
//===========================================================================

#ifndef __hanoi_h______________________
#define __hanoi_h______________________

#define MAX_DISC_COUNT   30

// ��ŵ��
typedef struct {
	int discList[MAX_DISC_COUNT]; // ���ϵ�����
	int discNum;                  // ���ӵĸ���
} Tower;

typedef struct {
	int id;
	int towerFrom;
	int towerTo;
	double time;
} FlyingDisc;


extern Tower      g_towers[3];   // 3������
extern int        g_disc_count;  // ��������
extern FlyingDisc g_flying_disc; // �ƶ�������

void HandleError(int errorCode); // һ����������

void InitTower(int n); // ��ʼ������
int  OneStepHanoi();   // ����Hanoi����
int  FindNextMove();   // ȷ����һ���ƶ���disc
// ��������������ʾ�ڸ�����С�Ĵ�����
//  winwidth   - ���ڿ��
//  winheight  - ���ڸ߶�
void DrawHanoi(double winwidth, double winheight);
// ����ʱ�����ŵ��ٶȣ��ٶ�Խ�󣬶���Խ��
void SetHanoiTimeElapseSpeed( double speed );
// ��ѯʱ�����ŵ��ٶ�
double GetHanoiTimeElapseSpeed();

#endif // ifndef __hanoi_h______________________
