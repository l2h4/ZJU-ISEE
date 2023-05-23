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

1. ��������λ��
   ��������ʾһ���ı�box

***************************************************************/

#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"

double label_x = 1.0;
double label_y = 1.0;

double mouse_x = 0, mouse_y = 0;


void display()
{
	double w = 1.0;
	double h = GetFontHeight() * 2;
	// �����Ļ
	DisplayClear();
	// draw a square
	SetPenColor("Red");
	drawLabel(label_x, label_y, "Lable is Here");
	
	//draw a rect/box to trace the mouse
	//drawRectangle(mouse_x, mouse_y, w, h, 0);
	SetPenColor("Blue");
	drawBox(mouse_x, mouse_y, w, h, 1, "This box follows the mouse", 'L', "Red");
}

typedef enum {
	LabelTimer,
	BoxTimer,
} MyTimer;

void mytimer(int  timerID)
{
	switch (timerID)
	{
	case LabelTimer:
		label_x += 0.5;
		if (label_x > 5.0) label_x = 1.0;
		display();
		break;
	}
}

void myMouseEvent (int x, int y, int button, int event)
{
	mouse_x = ScaleXInches(x);
	mouse_y = ScaleYInches(y);
	display();
}

void Main()
{
	SetWindowTitle("��ʾ���ʹ�÷���");
	InitGraphics();

	registerTimerEvent(mytimer);
	startTimer(LabelTimer, 100);

	registerMouseEvent(myMouseEvent);

	display();
}
