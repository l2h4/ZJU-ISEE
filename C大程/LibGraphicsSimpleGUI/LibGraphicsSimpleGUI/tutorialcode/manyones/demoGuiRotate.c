#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"

/***************************************************************
 VisualStudio 2010 �û�ע�⣺
    ��Character Set����Ϊ Use Multibyte Character Set
	����������ʾ������
***************************************************************/

// ȫ�ֱ���
static double winwidth, winheight;   // ���ڳߴ�
static float  rot_angle = 0;         // ��������ת�Ƕ�
static int    enable_rotation = 1;   // ������ת

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// �û����ַ��¼���Ӧ����
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	display(); // ˢ����ʾ
}

// ��ת��ʱ��
#define MY_ROTATE_TIMER  1

// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	if( timerID==MY_ROTATE_TIMER && enable_rotation ) 
	{
		rot_angle += 10; // ȫ�ֱ���
		display(); // ˢ����ʾ
	}
}

// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("Graphics User Interface Demo");
	//SetWindowSize(10, 10); // ��λ - Ӣ��
	//SetWindowSize(20, 10);
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
    InitGraphics();

	// ��ô��ڳߴ�
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��

	// ������ʱ��
	startTimer(MY_ROTATE_TIMER, 50);            

	// �򿪿���̨���������������Ϣ�����ڵ���
	// InitConsole(); 

}

#include <math.h>

// �������ε����������ת
// cenx, ceny - ��ת���ĵ�����
// angle - ��ת�Ƕ�
// tri[i][0/1] - �����ε� i �������x/y����
void rot_triangle(double cenx, double ceny, double angle, double tri[][2])
{
	double c = cos(angle/180*3.14159265);
	double s = sin(angle/180*3.14159265);
	int k;
	for( k = 0; k<3; k++ )
	{
		double dx = tri[k][0]-cenx;
		double dy = tri[k][1]-ceny;
		tri[k][0] = cenx + dx * c - dy * s;
		tri[k][1] = ceny + dx * s + dy * c;
	}
}

// �������� <t[0], t[1], t[2]>
void draw_triangle(double t[][2])
{
	int k;
	double x = t[2][0];
	double y = t[2][1];
	MovePen(x, y);
	for( k=0; k<3; k++ ) {
		DrawLine(t[k][0]-x, t[k][1]-y);
		x = t[k][0];
		y = t[k][1];
	}
}

// ��ת��������ʾ����
void drawRotateTriangle()
{
	double cx = winwidth/5*4;
	double cy = winheight/4*3;
	double dtx = winwidth/15;
	double dty = winheight/8;
	double tri[3][2] ={ {cx, cy}, {cx+dtx, cy}, {cx+dtx/2, cy+dty} };
	double fH = GetFontHeight();
	double h = fH*2; // �ؼ��߶�
	double w = winwidth/5; // �ؼ����
	double x = winwidth/2.5;
	double y = winheight/4*3;

	// ������
	rot_triangle(tri[0][0],tri[0][1],rot_angle,tri);
	SetPenColor("Green");
	draw_triangle(tri);

	// ��ת��ť
	if (button(GenUIID(0), x, y+h, w, h, enable_rotation ? "Stop Rotation" : "Start Rotation"))
		enable_rotation = ! enable_rotation;

	// �����˳���ť
	if( button(GenUIID(0), x, y-h, w, h, "Click to Quit") )
		exit(-1);
}


void display()
{
	// ����
	DisplayClear();

	// ��ת��������
	drawRotateTriangle();
}