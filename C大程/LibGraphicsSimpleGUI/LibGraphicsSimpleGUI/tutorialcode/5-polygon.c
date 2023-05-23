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

1. ��������ն����
2. ���ʹ�ð��������Ƴ�������
	F1 - ����/��ʼ ����
	ESC��Q - �˳�Ӧ�ó���

***************************************************************/
#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

typedef struct{
	double x, y;
} Point;

linkedlistADT g_polygon = NULL, g_tail = NULL;

int g_add_point = 0;
Point g_mousepoint;

void drawPolygon()
{
	linkedlistADT poly = NextNode(g_polygon, g_polygon);
	if (poly) {
		Point * p = (Point*) NodeObj(g_polygon, poly);
		double lx = p->x;
		double ly = p->y;
		MovePen(lx, ly);
		while (poly = NextNode(g_polygon, poly))
		{
			p = (Point*) NodeObj(g_polygon, poly);
			DrawLine(p->x - lx, p->y - ly);
			lx = p->x;
			ly = p->y;
		}
		if (g_add_point)
		{	//draw a line to the mouse
			SetPenColor("Red");
			DrawLine(g_mousepoint.x - lx, g_mousepoint.y - ly);
		}
		else
		{	//draw closed polygon
			linkedlistADT fp = NextNode(g_polygon, g_polygon);
			Point * p = (Point*)NodeObj(g_polygon, fp);
			DrawLine(p->x - lx, p->y - ly);
		}
	}
}

void display()
{
	DisplayClear();
	SetPenColor("Blue");
	SetPenSize(3);
	drawPolygon();
	drawLabel(1.0, 1.0, "Press F1 to create/close a polygon");
}

void AddPoint(double x, double y)
{
	Point * p = (Point*) malloc(sizeof(Point));
	p->x = x;
	p->y = y;
	g_tail = InsertNode(g_polygon, g_tail, p);
}

void quitMyApp()
{
	//TODO���ͷ�����

	// quit
	exit(-1);
}

void myMouseEvent (int x, int y, int button, int event)
{
	g_mousepoint.x = ScaleXInches(x);
	g_mousepoint.y = ScaleYInches(y);
	switch (event)
	{
	case BUTTON_UP:
		if (button == LEFT_BUTTON && g_add_point )
			AddPoint(g_mousepoint.x, g_mousepoint.y);
		display();
		break;

	case MOUSEMOVE:
		display();
		break;

	default:
		break;
	}
}

void myKeyboardEvent(int key, int event)
{
	switch (event)
	{
	case KEY_UP:
		if (key == VK_F1)
			g_add_point = !g_add_point;
		else if (key=='Q' || key==VK_ESCAPE)
			quitMyApp();
		display();
		break;

	default:
		break;
	}
}
void Main()
{
	SetWindowTitle("���ƶ����");
	SetWindowSize(7.0, 5.0);
	InitGraphics();

	registerMouseEvent(myMouseEvent);
	registerKeyboardEvent(myKeyboardEvent);

	g_polygon = NewLinkedList();

	//display();
}
