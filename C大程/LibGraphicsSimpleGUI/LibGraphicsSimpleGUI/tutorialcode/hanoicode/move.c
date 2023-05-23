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

#define MAX_STACK   MAX_DISC_COUNT*3

static struct {
	int n, a, b;
} stack[MAX_STACK];

static int stack_height = 0;

int pop(int *n, int *a, int *b)
{
	if( stack_height<=0 ) 
		return 0; // stack is empty
	stack_height --;
	*n = stack[stack_height].n;
	*a = stack[stack_height].a;
	*b = stack[stack_height].b;
	return 1;
}

int push(int n, int a, int b)
{
	if( stack_height >= MAX_STACK ) {
		printf("Stack is full\n");
		HandleError(0); // �򵥴���
	}
	stack[stack_height].n = n;
	stack[stack_height].a = a;
	stack[stack_height].b = b;
	stack_height ++;
	return 1;
}

void ResetMoveStack(int n, int a, int b)
{
	stack_height = 0;
	push(n,a,b);
}

int FindNextMove()
{
	int n, a, b, c;

	// ����Ƿ���disc���ƶ�
	if( g_flying_disc.id>=0 ) {
		printf("A disc is beeing moved\n");
		printf("You can only move one disc at a time\n");
		HandleError(0); // �򵥴���
	}

	while ( pop(&n, &a, &b) ) {  // ����һ����ģΪn�ĺ�ŵ������

		if( n<0 ) {
			printf("There must be some error\n");
			HandleError(0); // �򵥴���
		}
		
		// ֻ��1��disc����ô����������ȥŲ��
		if( n==1 ) { 
			int Na = g_towers[a].discNum;
			if( Na<=0 ) {
				printf("There must be some error in tower[%d]\n", a);
				HandleError(0); // �򵥴���
			}
			g_flying_disc.id = g_towers[a].discList[Na-1];
			g_flying_disc.towerFrom = a;
			g_flying_disc.towerTo = b;
			g_flying_disc.time = 0;
			return 1;
		}
		
		// ��������id��0, 1, 2����Ϊ3
		// ����a-->b�Ĺ�����id�ǣ�3 - a - b
		c = 3 - a - b;
		
		//
		// 1. �Ƚ� n-1 ������ a--> c����b���ɣ�
		// 2. �ٽ�������� 1 ������ a-->b
		// 3. ��� n-1 ������ c-->b����a���ɣ�
		//
		// ע�⣺������3��2��1���ηŵ�stack��
		//       ��Ϊ��stack�У��Ƚ����
		//
		push(n-1, c, b);
		push(1, a, b);
		push(n-1, a, c);
	}

	return 0; // no more move task
}