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

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// ��ת��ʱ��
#define MY_ROTATE_TIMER  1

// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	display(); // ˢ����ʾ
}

// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("Graphics User Interface Demo");
	SetWindowSize(1600, 800);
    InitGraphics();
	InitGUI();

	// ���ö�ʱ��
	registerTimerEvent(TimerEventProcess);
	// ������ʱ��
	startTimer(MY_ROTATE_TIMER, 50);            
}

void display()
{
	double fh = GetFontHeight();
	double fa = GetFontAscent();
    double winwidth = GetWindowWidth();
    double winheight = GetWindowHeight();
	int maxPixels = 35, n;
	double x = 2*maxPixels/(double)GetXResolution();
	double y = winheight;
	double dy = maxPixels/(double)GetYResolution();
	double w = winwidth/3;
	char buf[256];

	// ����
	DisplayClear();
	for( n = 5; n<maxPixels; n++ )
	{
		double h = n/(double)GetYResolution();
		sprintf(buf, "Box Height = %d Pixels or %.2f Inches", n, h);
		drawBox(x, y-=dy, w, h, buf,'L');
		if(n==2+maxPixels/2) { 
			x += 1.5*w;
			y  = winheight;
		}
	}

	sprintf(buf, "font height = %.2f, font ascent = %.2f, Enjoy!", fh, fa);
	drawLabel(x, y-=dy, buf);
}
	
