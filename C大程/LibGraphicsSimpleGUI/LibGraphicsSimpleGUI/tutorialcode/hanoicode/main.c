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

#include "hanoi.h"

// ��ת��ʱ��
#define MOVE_DISC  1


/***************************************************************
 VisualStudio 2010 �û�ע�⣺
    ��Character Set����Ϊ Use Multibyte Character Set
	����������ʾ������
***************************************************************/

// ȫ�ֱ���
static double winwidth, winheight;   // ���ڳߴ�
static int    enable_move_disc = 1;  // �����ƶ�
static int    timer_interval = 2;    // ���ʱ�� (in ms)
static char   time_elapse_speed[64]; // ���ڱ༭ʱ�������ٶ�

void SetSpeedEditString(double speed)
{
	sprintf(time_elapse_speed, "%f", speed);
}
double GetEditTimeSpeed()
{
	double v = 0;
	sscanf(time_elapse_speed, "%lf", &v);
	return v;
}

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

// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	if( timerID==MOVE_DISC && enable_move_disc ) 
	{
		int s = OneStepHanoi();
		// if( s )	display(); // ˢ����ʾ
	}
	display(); // ˢ����ʾ
}

// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// �򿪿���̨��������printf/scanf���/�������Ϣ���������
	//InitConsole(); 

	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("��ŵ��������ʾ");
	SetWindowSize(10, 8); // ��λ - Ӣ��
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
    InitGraphics();

	// ��ô��ڳߴ�
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��

	// ������ʱ��
	startTimer(MOVE_DISC, timer_interval);

	// ��ʼ����ŵ��
	InitTower(6);
	SetSpeedEditString(GetHanoiTimeElapseSpeed());
}

void DrawMenu()
{
	static char * menuListFile[] = {"File",  
		"���¿�ʼ  | Ctrl-R", // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
		"Exit            | Ctrl-E"};
	static char * menuListTool[] = {"Tool",
		"��ͣ����    | Ctrl-T"};
	static char * menuListHelp[] = {"Help",
		"���ڱ����"};

	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH*1.5; // �ؼ��߶�
	double w = TextStringWidth(menuListFile[0])*2; // ���˵����
	double wlist = TextStringWidth(menuListFile[1])*1.2;
	double xindent = winheight/20; // ����
	int    selection;
	
	// menu bar
	drawMenuBar(0,y-h,winwidth,h);
	// File �˵�
	selection = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	if( selection==2 )
		exit(-1); // choose to exit
	else if( selection==1 )
	{
		InitTower(g_disc_count);
	}
	
	// Tool �˵�
	menuListTool[1] = enable_move_disc ? "��ͣ����   |   Ctrl-T" : "��������   |   Ctrl-T";
	selection = menuList(GenUIID(0),x+w,  y-h, w, wlist,h, menuListTool,sizeof(menuListTool)/sizeof(menuListTool[0]));
	if( selection==1 )
		enable_move_disc = ! enable_move_disc;
	
	// Help �˵�
	selection = menuList(GenUIID(0),x+2*w,y-h, w, wlist, h, menuListHelp,sizeof(menuListHelp)/sizeof(menuListHelp[0]));
	if( selection==1 ) {
		//TODO����ʾ�������Ϣ
	}
}

void DrawButtons()
{
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double x = winwidth/4;  
	double y = winheight/4; 
	double w = TextStringWidth("��ͣ")*3;
	double dx = w + TextStringWidth("��");
	double dy = h * 2;

	// ����ʱ�������ٶ�
	drawLabel(x,y+dy,"�����ٶ�");
	if( textbox(GenUIID(0), x+dx*0.7, y+dy*0.8, w, h, time_elapse_speed, sizeof(time_elapse_speed) ) )
		SetHanoiTimeElapseSpeed( GetEditTimeSpeed() );

	if( button(GenUIID(0), x+dx*1.7, y+dy*0.8, w, h, "��������") ) {
		InitTower(g_disc_count + 1);
	}
	if( button(GenUIID(0), x+dx*2.7, y+dy*0.8, w, h, "��������") ) {
		InitTower(g_disc_count - 1);
	}

	if( button(GenUIID(0), x, y-=dy, w, h, "����") ) {
		InitTower(g_disc_count);
	}

	if( button(GenUIID(0), x+=dx, y, w, h, enable_move_disc ? "��ͣ" : "����") ) {	
		enable_move_disc = ! enable_move_disc;
	}

	if( button(GenUIID(0), x+=dx, y, w, h, "�˳�") ) {	
		exit(-1); 
	}
	if( button(GenUIID(0), x+=dx, y, w, h, "����") ) {	
		SetHanoiTimeElapseSpeed( GetHanoiTimeElapseSpeed()*1.5 );
		SetSpeedEditString( GetHanoiTimeElapseSpeed() );
	}
	if( button(GenUIID(0), x+=dx, y, w, h, "����") ) {
		SetHanoiTimeElapseSpeed( GetHanoiTimeElapseSpeed()*0.7 );
		SetSpeedEditString( GetHanoiTimeElapseSpeed() );
	}
}

void display()
{
	// ����
	DisplayClear();
	// ���ƺ�ŵ��������
	DrawHanoi(winwidth, winheight);
	// ���ƿؼ�
	DrawMenu();
	DrawButtons();
}
