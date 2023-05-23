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
static int    show_more_buttons = 0; // ��ʾ���ఴť

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	display(); // ˢ����ʾ
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
	registerMouseEvent(MouseEventProcess);      // ���

	// �򿪿���̨���������������Ϣ�����ڵ���
	// InitConsole(); 

}


// ��ť��ʾ����
void drawButtons()
{
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double x = winwidth/2.5;  
	double y = winheight/2-h; 
	double w = winwidth/5; // �ؼ����

	if (button(GenUIID(0), x, y, w, h, show_more_buttons ? "Show Less Buttons" : "Show More Buttons"))
		show_more_buttons = ! show_more_buttons;
	
	if( button(GenUIID(0), x, y-2*h, w, h, "Click to Quit") )
		exit(-1);

	if( show_more_buttons ) {
		int k;
		
		for( k = 0; k<3; k++ ) {
			char name[128]; sprintf(name, "Button Array %d", k);
			// use GenUIID(k) to have different ID for multiple buttons by the same code
			button(GenUIID(k), x + w*1.2, y - k*h*2, w, h, name); 
		}

	}
}

void display()
{
	// ����
	DisplayClear();
			
	// ��ť
	drawButtons();
}