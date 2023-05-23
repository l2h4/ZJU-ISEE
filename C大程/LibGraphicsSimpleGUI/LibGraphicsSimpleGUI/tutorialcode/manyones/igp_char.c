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

static double ccx = 1.0, ccy = 1.0;/*Բ������*/
static double radius = 1.0; /*Բ�뾶*/

static char text[100]; /*������ַ���������*/
static int textlen = 0;/*������ַ�������*/
static double textx, texty; /*�ַ�������ʼλ��*/

void DrawCenteredCircle(double x, double y, double r);/*������Բ*/
/*�жϵ�(x0,y0)�Ƿ��ھ��ΰ�Χ��(x1, y1) --> (x2, y2)��Χ��*/
void CharEventProcess(char c);/*�ַ���Ϣ�ص�����*/

void Main() /*����ʼ��ִ��һ��*/
{
    InitGraphics();        	
	
	registerCharEvent(CharEventProcess);/*ע���ַ���Ϣ�ص�����*/

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

void CharEventProcess(char c)
{
 	 static char str[2] = {0, 0};

     switch (c) {
       case '\r':  /* ע�⣺�س������ﷵ�ص��ַ���'\r'������'\n'*/
   	 	   break;
 	   case 27: /*ESC*/
 	       break;
      default:
	  	   str[0] = c;/*�γɵ�ǰ�ַ����ַ���*/
	 	   text[textlen++] = c;/*����ǰ�ַ����뵽�����ַ���������*/
	 	   text[textlen] = '\0';
	 	   DrawTextString(str);/*�����ǰ�ַ��������λ����Ӧ����*/
	 	   break;
    }
}
