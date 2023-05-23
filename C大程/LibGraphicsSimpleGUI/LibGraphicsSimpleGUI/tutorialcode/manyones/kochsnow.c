#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include "linkedlist.h"
#include <math.h>

#define PI 3.1415926

linkedlistADT SnowList; /*�����������δ�Ÿ��߶εĽǶ�*/
double length;          /*��ʼ�߳���inch��*/

static void DwawPolarLine(double r, double theta); /*���Ƽ������߶�*/
static void DrawKochSnowLine(void *obj); /*���Ƹ��߶�-Ϊ��������������ö���*/
static void SplitEdges(linkedlistADT linkedlist);/*ÿ�����ηֽ�Ϊ������*/
static void KochSnow(linkedlistADT linkedlist, int n);/*�ݹ���n��Kochѩ�����߽Ƕ�*/
static void KochSnow1(linkedlistADT linkedlist, int n);/*�ǵݹ鷽����n��Kochѩ�����߽Ƕ�*/

void Main() /*����ʼ��ִ��һ��*/
{
	int n;

    InitGraphics();/*ͼ�γ�ʼ��*/

	SetPenColor("Red"); /*���û�����ɫ*/
    SetPenSize(1);      /*���û��ʴ�ϸ*/

	InitConsole();
	printf("Enter n: "); /*�������*/
	n = GetInteger();
	printf("Enter length: ");/*�����ʼ�߳���inch��*/
	length = GetReal();
	FreeConsole();

    /*��ʼ�����η���ͼ�δ�������λ�á��������ƶ������½Ƕ���λ��*/
	MovePen(GetWindowWidth()/2.0 - length/2.0,
            GetWindowHeight()/2 - length/2.0*tan(30.0/180.0*PI));

	length = length / pow(3.0, (float)n); /*n��ѩ�����յ��߶δ�С*/

	SnowList = NewLinkedList(); /*��ʼ������*/
	KochSnow(SnowList, n);      /*�ݹ���������n��ѩ�����߶νǶȣ������������*/
//	KochSnow1(SnowList, n);      /*�ǵݹ���������n��ѩ�����߶νǶȣ������������*/
	
    TraverseLinkedList(SnowList, DrawKochSnowLine);/*�������������߶�*/
    FreeLinkedList(SnowList);/*ɾ�������ͷſռ�*/

}

/*���Ƽ�����ֱ�ߣ�����r���Ƕ�theta*/
static void DrawPolarLine(double r, double theta)
{
	double radians;

	radians = theta / 180 * PI;
	DrawLine(r * cos(radians), r * sin(radians));
}

/*ΪTraverseLinkedList���ú����������ƵĻ���ֱ�ߺ���
 *obj�ǽǶ�ָ�룬length��ֱ�߳��ȣ�ȫ�ֱ�����
*/
static void DrawKochSnowLine(void *obj)
{
	DrawPolarLine(length, *((double *)obj));
}

/*���������η���Ϊ�ıߡ���ÿ�߽Ƕ�����Ϊ��theta, theta-60, theta+60, theta
 *���У�thetaΪԭ�ߵĽǶȣ�Ҳ����n-1�״����������ڵ��еĸ��߽Ƕ�
 */
static void SplitEdges(linkedlistADT SnowList)
{
	linkedlistADT ptr1;
	double *ptheta, theta;

	ptr1 = SnowList;   /*����ָ�룬����ͷָ��*/
    ptr1 = NextNode(SnowList, ptr1);/*��ͷָ�����һ����㣬����һ�����ݽ��*/
	while (ptr1 != NULL) {
		theta = *((double *)NodeObj(SnowList, ptr1)); /*�����ԭ����ŵĽǶ�*/
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta - 60;
        InsertNode(SnowList, ptr1, (void *)ptheta); /*����ڶ����ǶȽ��*/
		ptr1 = NextNode(SnowList, ptr1);            /*�Ƶ��ղ���Ľ��*/
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta + 60;                       
        InsertNode(SnowList, ptr1, (void *)ptheta);  /*����������ǶȽ��*/
		ptr1 = NextNode(SnowList, ptr1);             /*�Ƶ��ղ���Ľ��*/
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta;
        InsertNode(SnowList, ptr1, (void *)ptheta);  /*������ĸ��ǶȽ��*/
		ptr1 = NextNode(SnowList, ptr1);             /*�Ƶ��ղ���Ľ��*/
		ptr1 = NextNode(SnowList, ptr1);             /*�Ƶ�ԭ���ĵڶ������*/
	}
}

/*�ݹ�����n��Kochѩ�����߽Ƕȵĺ���*/
static void KochSnow(linkedlistADT SnowList, int n)
{
	double *ptheta;

	if (n == 0) { /*0��ѩ������ʼ�����Σ������¶˿�ʼ���߽Ƕ�����Ϊ0��120��240*/
		ptheta = GetBlock(sizeof(double));
		*ptheta = 0;
        InsertNode(SnowList, NULL, (void *)ptheta);
		ptheta = GetBlock(sizeof(double));
		*ptheta = 120;
        InsertNode(SnowList, NULL, (void *)ptheta);
		ptheta = GetBlock(sizeof(double));
		*ptheta = 240;
        InsertNode(SnowList, NULL, (void *)ptheta);
	} else {
		KochSnow(SnowList, n-1);/*���ɵ�n-1��Kochѩ������*/
        SplitEdges(SnowList);/*����n�ס��������߷��ѳ��ı�*/
	}
}

static void KochSnow1(linkedlistADT SnowList, int n)
{
	int i;
	double *ptheta;

	if (n < 0) return; 
	/*������0��ѩ������ʼ�����Σ������¶˿�ʼ���߽Ƕ�����Ϊ0��120��240*/
	ptheta = GetBlock(sizeof(double));
	*ptheta = 0;
    InsertNode(SnowList, NULL, (void *)ptheta);
	ptheta = GetBlock(sizeof(double));
	*ptheta = 120;
    InsertNode(SnowList, NULL, (void *)ptheta);
	ptheta = GetBlock(sizeof(double));
	*ptheta = 240;
    InsertNode(SnowList, NULL, (void *)ptheta);
    /*���ηֽ���ߣ�������ɸ߽�ѩ������*/
	for (i = 1; i <= n; i++) SplitEdges(SnowList);
}
