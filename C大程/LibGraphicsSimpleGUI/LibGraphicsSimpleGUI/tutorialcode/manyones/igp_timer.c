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

#define TIMER_BLINK500  1     /*500ms��ʱ���¼���־��*/
#define TIMER_BLINK1000 2     /*1000ms��ʱ��ʱ���־��*/

const int mseconds500 = 500;   
const int mseconds1000 = 1000; 

static double ccx = 1.0, ccy = 1.0;/*Բ������*/
static double radius = 1.0; /*Բ�뾶*/

//static bool isBlink = FALSE;   /*�Ƿ���˸��־*/
static bool isDisplayCircle = TRUE; /*Բ��ʾ��־*/
static bool isDisplayCircle2 = TRUE; /*��Բ��ʾ��־*/

void DrawCenteredCircle(double x, double y, double r);/*������Բ*/
/*�жϵ�(x0,y0)�Ƿ��ھ��ΰ�Χ��(x1, y1) --> (x2, y2)��Χ��*/
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/

void Main() /*����ʼ��ִ��һ��*/
{
    InitGraphics();        	
	
	
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/

	SetPenColor("Red"); 
    SetPenSize(1);
    
    ccx = GetWindowWidth()/2;
    ccy = GetWindowHeight()/2;
    DrawCenteredCircle(ccx, ccy, radius);
    DrawCenteredCircle(ccx, ccy, radius*2);
    
    startTimer(TIMER_BLINK500, mseconds500);/*500ms��ʱ������*/
    startTimer(TIMER_BLINK1000, mseconds1000);/*1000ms��ʱ������*/
}

void DrawCenteredCircle(double x, double y, double r)
{
	SetPenSize(5);
    MovePen(x + r, y);
    DrawArc(r, 0.0, 360.0);
}

void TimerEventProcess(int timerID)
{
      bool erasemode;

	  switch (timerID) {
	    case TIMER_BLINK500: /*500ms�����˸��ʱ��*/
	      erasemode = GetEraseMode();
		  SetEraseMode(isDisplayCircle);
          DrawCenteredCircle(ccx, ccy, radius);
	      SetEraseMode(erasemode);
		  isDisplayCircle = !isDisplayCircle;
		  break;
	    case TIMER_BLINK1000: /*1000ms�����˸��ʱ��*/
	      erasemode = GetEraseMode();
		  SetEraseMode(isDisplayCircle2);
          DrawCenteredCircle(ccx, ccy, radius*2);
	      SetEraseMode(erasemode);
		  isDisplayCircle2 = !isDisplayCircle2;
		  break;
	    default:
		  break;
	  }
}
