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

#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"

Tower      g_towers[3];   // 3������
int        g_disc_count;  // ��������
FlyingDisc g_flying_disc; // �ƶ�������

void ResetMoveStack(int n, int a, int b);

// ��ʼ����ŵ������
// n - number of discs
void InitTower(int n)
{
	int j;

	if( n<1 ) n = 1;

	if( n > MAX_DISC_COUNT ) {
		printf("Too many disc to handle\n");
		HandleError(0); // �򵥴���
	}

	g_disc_count = n;
	// 0��������n������
	g_towers[0].discNum = n;
	for( j = 0; j<n; j++ ) {
		// ����j���浽ower 0��
		g_towers[0].discList[j] = j; 
	}
	// 1�ź�2������������
	g_towers[1].discNum = 0;
	g_towers[2].discNum = 0;
	// ��n�����̴�0������Ų��1������
	ResetMoveStack(n,0,1); 
	// û�������ƶ�������
	g_flying_disc.id = -1;
}


int OneStepHanoi()
{
	if( g_flying_disc.id >=0 ) {
		// �����ƶ�һ������
		g_flying_disc.time += GetHanoiTimeElapseSpeed();
		if( g_flying_disc.time>=1 ) // �����̵���Ŀ�ĵ���
		{
			int tt = g_flying_disc.towerTo;
			// ��������̱��浽tower��
			g_towers[tt].discList[ g_towers[tt].discNum ++ ] = g_flying_disc.id; 
			g_flying_disc.id = -1; // ����ƶ���
		}
		return 1;
	}
	else if( FindNextMove() ) // ����Ҫ�����ƶ�
	{
		// FindNextMove�����Ѿ����ƶ����񱣴���g_flying_disc����
		int ft = g_flying_disc.towerFrom;
		// ��tower[ft]���Ƴ�
		g_towers[ft].discNum --; 
		return 1;
	}
	// ��ŵ���������
	return 0;	
}


static double time_elapse_speed = 0.02;

void SetHanoiTimeElapseSpeed( double speed )
{
	time_elapse_speed = speed;
}
double GetHanoiTimeElapseSpeed()
{
	return time_elapse_speed;
}


void HandleError(int errorCode)
{
	exit(errorCode);
}
