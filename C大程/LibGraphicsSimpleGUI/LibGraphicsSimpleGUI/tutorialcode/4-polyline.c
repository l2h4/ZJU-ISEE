//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��21�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================

/**************************************************************

1. ������������һ�����߶����
2. ���ʹ��ͨ��������

***************************************************************/
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

typedef struct{
	double x, y;
} Point;

linkedlistADT g_polylines = NULL;

void display()
{
	linkedlistADT poly = NextNode(g_polylines, g_polylines);
	
	SetPenColor("Blue");
	if (poly) {
		Point * p = (Point*) NodeObj(g_polylines, poly);
		double lx = p->x;
		double ly = p->y;
		MovePen(lx, ly);
		while (poly = NextNode(g_polylines, poly))
		{
			p = (Point*) NodeObj(g_polylines, poly);
			DrawLine(p->x - lx, p->y - ly);
			lx = p->x;
			ly = p->y;
		}
	}
}

void AddPoint(double x, double y)
{
	Point * p = malloc(sizeof(Point));
	p->x = x;
	p->y = y;
	InsertNode(g_polylines, NULL, p);
}

void myMouseEvent (int x, int y, int button, int event)
{
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	switch (event)
	{
	case BUTTON_UP:
		if (button == LEFT_BUTTON)
			AddPoint(mx, my);
		display();
		break;
	}
	display();
}

void Main()
{
	SetWindowTitle("���ƶ����");
	SetWindowSize(7.0, 5.0);
	InitGraphics();

	registerMouseEvent(myMouseEvent);

	g_polylines = NewLinkedList();
	//display();
}