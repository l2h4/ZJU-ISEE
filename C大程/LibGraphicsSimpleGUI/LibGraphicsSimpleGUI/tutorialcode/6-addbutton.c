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

1. ���ʹ��button
2. ��������ն����
3. ����޶��������������򣬱����button�໥����

***************************************************************/
#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

// ����һ������������������
//  ��ֹ��button���������
double canvasRect[4] = {0.5, 5.5, 0.5, 5.5};

int InCanvasRect(double x, double y)
{
	return (x >= canvasRect[0] && x <= canvasRect[1] &&
			y >= canvasRect[2] && y <= canvasRect[3] );
}


void SetCanvasRect()
{
	double w = GetWindowWidth();
	double h = GetWindowHeight();
	canvasRect[0] = 0.5;
	canvasRect[1] = w-0.5;
	canvasRect[2] = 1.0;
	canvasRect[3] = h - 0.5;
}

void displayCanvasRect()
{
	double dx = canvasRect[1] - canvasRect[0];
	double dy = canvasRect[3] - canvasRect[2];
	SetPenColor("Green");
	MovePen(canvasRect[0],canvasRect[2]);
	DrawLine(dx,0);
	DrawLine(0,dy);
	DrawLine(-dx,0);
	DrawLine(0,-dy);
}

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
	displayCanvasRect();
	SetPenColor("Blue");
	SetPenSize(3);
	drawPolygon();
	//drawLabel(1.0, 1.0, "Press F1 to create/close a polygon");
	if ( button(GenUIID(0), 0.5, 0.5, 2.0, 0.3, g_add_point ? "End Polygon" : "Start Polygon") )
	{
		g_add_point = !g_add_point;
	}
}

void AddPoint(double x, double y)
{
	Point * p = malloc(sizeof(Point));
	p->x = x;
	p->y = y;
	g_tail = InsertNode(g_polygon, g_tail, p);
}

void myMouseEvent (int x, int y, int button, int event)
{
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	if( InCanvasRect(mx, my) )
	{
		g_mousepoint.x = mx;
		g_mousepoint.y =my;
		switch (event)
		{
		case BUTTON_UP:
			if (button == LEFT_BUTTON && g_add_point )
				AddPoint(g_mousepoint.x, g_mousepoint.y);
			break;

		case MOUSEMOVE:
			break;

		default:
			break;
		}
	}
	display();
}

void myKeyboardEvent(int key, int event)
{
	uiGetKeyboard(key, event); // needed for using simpleGUI
	display();

	switch (event)
	{
	case KEY_UP:
		if (key == VK_F1)
			g_add_point = !g_add_point;

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

	SetCanvasRect();
}
