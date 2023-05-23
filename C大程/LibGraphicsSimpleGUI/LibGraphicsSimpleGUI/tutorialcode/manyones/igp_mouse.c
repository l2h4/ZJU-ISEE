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

static double ccx, ccy;/*Բ������*/
static double radius = 1.0; /*Բ�뾶*/

void DrawCenteredCircle(double x, double y, double r);/*������Բ*/
/*�жϵ�(x0,y0)�Ƿ��ھ��ΰ�Χ��(x1, y1) --> (x2, y2)��Χ��*/
bool inBox(double x0, double y0, double x1, double x2, double y1, double y2);
void MouseEventProcess(int x, int y, int button, int event);/*�����Ϣ�ص�����*/

void Main() /*����ʼ��ִ��һ��*/
{
    InitGraphics();        	
	
	registerMouseEvent(MouseEventProcess);/*ע�������Ϣ�ص�����*/

	SetPenColor("Red"); 
    SetPenSize(1);
    
    ccx = GetWindowWidth()/2;
    ccy = GetWindowHeight()/2;
    
    DrawCenteredCircle(ccx, ccy, radius);/*��Բ*/
}

void DrawCenteredCircle(double x, double y, double r)
{
    MovePen(x + r, y);
    
    DrawArc(r, 0.0, 360.0);
}

bool inBox(double x0, double y0, double x1, double x2, double y1, double y2)
{
	return (x0 >= x1 && x0 <= x2 && y0 >= y1 && y0 <= y2);
}

void MouseEventProcess(int x, int y, int button, int event)
{
 	 static bool isDraw = FALSE;
	 static bool isChangeRadius = FALSE;
     static double r = 0.2;
 	 static double omx = 0.0, omy = 0.0;
     double mx, my;

 	 mx = ScaleXInches(x);/*pixels --> inches*/
 	 my = ScaleYInches(y);/*pixels --> inches*/
 
     switch (event) {
         case BUTTON_DOWN:
   		 	  if (button == LEFT_BUTTON) {
				  if (inBox(mx, my, ccx-radius, ccx+radius, ccy-radius, ccy+radius)){
					  isDraw = TRUE;
				  }
			  } else if (button == RIGHT_BUTTON) {
					  isChangeRadius = TRUE;
			  }
		      omx = mx; omy = my;
              break;
    	 case BUTTON_DOUBLECLICK:
			  break;
         case BUTTON_UP:
  		 	  if (button == LEFT_BUTTON) isDraw = FALSE;
			  else if (button == RIGHT_BUTTON) isChangeRadius = FALSE;
              break;
         case MOUSEMOVE:
			  if (isDraw) {
                  SetEraseMode(TRUE);/*����ǰһ��*/
                  DrawCenteredCircle(ccx, ccy, radius);
				  ccx += mx - omx;
				  ccy += my - omy;
				  omx = mx;
				  omy = my;
				  SetEraseMode(FALSE);/*���µ�*/
                  DrawCenteredCircle(ccx, ccy, radius);
			  } else if (isChangeRadius) {
                  SetEraseMode(TRUE);/*����ǰһ��*/
                  DrawCenteredCircle(ccx, ccy, radius);
				  radius += mx - omx;
				  omx = mx;
				  omy = my;
				  SetEraseMode(FALSE);/*���µ�*/
                  DrawCenteredCircle(ccx, ccy, radius);
			  }
              break;
     }	
}
