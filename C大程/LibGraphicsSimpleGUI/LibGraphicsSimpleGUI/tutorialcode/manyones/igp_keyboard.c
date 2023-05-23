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

#define deltax 0.03
#define deltay 0.03

static double ccx = 1.0, ccy = 1.0;/*Բ������*/
static double radius = 1.0; /*Բ�뾶*/

void DrawCenteredCircle(double x, double y, double r);/*������Բ*/
void KeyboardEventProcess(int key,int event);/*������Ϣ�ص�����*/

void Main() /*����ʼ��ִ��һ��*/
{
    InitGraphics();        	
	
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/

	SetPenColor("Red"); 
    SetPenSize(1);
    
    ccx = GetWindowWidth()/2;
    ccy = GetWindowHeight()/2;
    DrawCenteredCircle(ccx, ccy, radius);
}

void DrawCenteredCircle(double x, double y, double r)
{
    MovePen(x + r, y);
    DrawArc(r, 0.0, 360.0);
}

void KeyboardEventProcess(int key,int event)/*ÿ������������Ϣ����Ҫִ��*/
{
 	 double oldradius;
 	 
     switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_UP:/*UP*/
			         SetEraseMode(TRUE);/*����ǰһ��*/
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccy += deltay;
					 SetEraseMode(FALSE);/*���µ�*/
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_DOWN:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccy -= deltay;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_LEFT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx -= deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_RIGHT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx += deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F1:
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
		 	         SetPenSize(GetPenSize()+1);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 break;
			     case VK_F2:
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
		 	         SetPenSize(GetPenSize()-1);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F3:
			     case VK_PRIOR:
	 	     		 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     radius += 0.1;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F4:
			     case VK_NEXT:
		 	         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     radius -= 0.1;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F5:
                     break;
			     case VK_F6:
                     break;
			     case VK_F9:
			         InitConsole();
			         oldradius = radius;
			         printf("Input radius: ");
			         radius = GetReal();
			         FreeConsole();
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, oldradius);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_ESCAPE:/*���ù����˸��־*/
/*
                     isBlink = !isBlink;
                     if (isBlink ) {
						startTimer(TIMER_BLINK500, mseconds500);
						startTimer(TIMER_BLINK1000, mseconds1000);
                     } else {
						cancelTimer(TIMER_BLINK500);
    					cancelTimer(TIMER_BLINK1000);
					 }
*/
                     break;
			 }
			 break;
		case KEY_UP:
			 break;
	 }	 
}
