#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "linkedlist.h"

#define NLIST     4
#define LINE      0
#define RECT      1
#define ELLIPSE   2
#define STRING    3

#define SYSCOLOR "Red"  /*Ĭ�ϻ�ͼ��ɫ*/

#define CURSOR "_"          /*������*/
#define CURSOR_BLINK  1     /*�����˸��ʱ���¼���־��*/
const int timerseconds = 500; /*�����˸����ms*/
bool isCursorBlink = FALSE;  /*����Ƿ���˸*/ 

void KeyboardEventProcess(int key,int event);/*������Ϣ�ص�����*/
void CharEventProcess(char c);/*�ַ���Ϣ�ص�����*/
void MouseEventProcess(int x, int y, int button, int event);/*�����Ϣ�ص�����*/
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/

typedef struct {/*ֱ������*/
	double x1, y1;/*��һ��������*/
    double x2, y2;/*�ڶ���������*/
    int PenSize; /*��ϸ*/
    string color; /*��ɫ*/
    bool isSelected; /*ѡ��*/ 
} *LineT;

typedef struct {/*��������*/
	double x1, y1;/*���½�����*/
    double x2, y2;/*���Ͻ�����*/
    int PenSize; /*��ϸ*/
    string color; /*��ɫ*/
    bool isSelected; /*ѡ��*/ 
} *RectT;

typedef struct {/*��Բ����*/
    double cx, cy;/*Բ��*/
    double rx, ry;/*���̰뾶*/
    int PenSize; /*��ϸ*/
    string color; /*��ɫ*/
    bool isSelected; /*ѡ��*/ 
} *EllipseT;

typedef struct {/*�ı�����*/
	string text;/*�ı�ָ��*/
	double x, y;/*�ı���ʾ��ʼλ������*/
    int PointSize; /*���ִ�С*/
    string color; /*��ɫ*/
    bool isSelected; /*ѡ��*/ 
    int curPos; /*���λ��*/
    bool isDisplayed; /*����Ƿ�����ʾ״̬*/ 
} *TextT;

linkedlistADT list[NLIST]={NULL, NULL, NULL, NULL};/*����ͼ��Ԫ������ָ��*/
double minDistance[NLIST]={100000000.0, 1000000000.0, 1000000000.0, 1000000000.0};
int curList = LINE; /*��ǰ�������*/
LineT curLine = NULL;/*ֱ������ĵ�ǰ����ָ��*/
RectT curRect = NULL;/*��������ĵ�ǰ����ָ��*/
EllipseT curEllipse = NULL;/*��Բ����ĵ�ǰ����ָ��*/
TextT curText = NULL;/*�ı�����ĵ�ǰ����ָ��*/

bool isSelected = FALSE; /*ͼ��Ԫ��ѡ��״̬*/ 

#define TEXTLEN  100
static TextT tptr; /*��ǰ�༭�ı�����ָ��*/
static bool inText = FALSE; /*�Ƿ��ڵ�ǰ�ı��༭״̬*/
static char textbuf[TEXTLEN+1];/*��ǰ�ı�������*/

/*��Բ������*/
void DrawCenteredEllipse(void *ellipse);/*����Բ*/
bool EllipseEqual(void *ellipse1, void *ellipse2);/*�Ƚ�������Բ���*/
EllipseT SelectNearestNodeE(linkedlistADT list, double mx, double my);/*ѡ��(mx,my)����Ľ��*/

/*ֱ�ߴ�����*/
void DrawLineD(void *line);
bool LineEqual(void *line1, void *line2);
LineT SelectNearestNodeL(linkedlistADT list, double mx, double my);

/*���δ�����*/
void DrawRect(void *rect);
bool RectEqual(void *rect1, void *rect2);
RectT SelectNearestNodeR(linkedlistADT list, double mx, double my);

/*�ı�������*/
void DrawTextT(void *text); /*��ʾ�ı�*/
bool TextEqual(void *text1, void *text2);/*�Ƚ������ı��Ƿ���ͬ*/
TextT SelectNearestNodeT(linkedlistADT list, double mx, double my);
void InsertCharToString(string str, int pos, char c);/*���ַ�c���뵽�ַ���str��posλ��*/
void DeleteCharFromString(string str, int pos);/*ɾ���ַ���str��posλ���ַ�*/
void DrawCursor(string str, int curPos, double startx, double starty);/*��ʾ�ı����*/

void PickNearestNode(linkedlistADT list[], double mx, double my);/*ѡ��(mx,my)������*/
void TraverseAllList();/*ˢ������ͼ�ζ���*/



// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);
void cancelTimer(int id);

void Main() /*����ʼ��ִ��һ��*/
{
	int i;

    InitGraphics();/*ͼ�γ�ʼ��*/
	Randomize();/*���������ʼ��*/
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerCharEvent(CharEventProcess);/*ע���ַ���Ϣ�ص�����*/
	registerMouseEvent(MouseEventProcess);/*ע�������Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/
	
	SetPenColor(SYSCOLOR); 
    SetPenSize(1);

	for (i = 0; i < NLIST; i++) list[i] = NewLinkedList();
}

void KeyboardEventProcess(int key,int event)/*ÿ������������Ϣ����Ҫִ��*/
{
	 LineT lptr;
	 RectT rptr;
	 EllipseT eptr;
	 double x1, y1, x2, y2;

     switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_F1:/*F1: �������ֱ��*/
					 lptr = GetBlock(sizeof(*lptr));
					 lptr->x1 = RandomReal(0.0, GetWindowWidth());
					 lptr->y1 = RandomReal(0.0, GetWindowHeight());
					 lptr->x2 = RandomReal(0.0, GetWindowWidth());
					 lptr->y2 = RandomReal(0.0, GetWindowHeight());
					 lptr->PenSize = GetPenSize();
					 lptr->color = GetPenColor();
					 lptr->isSelected = FALSE;
					 InsertNode(list[LINE], NULL, lptr);
					 DrawLineD(lptr);
                     break;
			     case VK_F2:/*F2: ������ɾ���*/
					 rptr = GetBlock(sizeof(*rptr));
					 x1 = RandomReal(0.0, GetWindowWidth());
					 y1 = RandomReal(0.0, GetWindowHeight());
					 x2 = RandomReal(0.0, GetWindowWidth());
					 y2 = RandomReal(0.0, GetWindowHeight());
					 if (x1 < x2) {
                         rptr->x1 = x1;
                         rptr->x2 = x2;
					 } else {
                         rptr->x1 = x2;
                         rptr->x2 = x1;
					 }
					 if (y1 < y2) {
                         rptr->y1 = y1;
                         rptr->y2 = y2;
					 } else {
                         rptr->y1 = y2;
                         rptr->y2 = y1;
					 }
					 rptr->PenSize = GetPenSize();
					 rptr->color = GetPenColor();
					 rptr->isSelected = FALSE;
					 InsertNode(list[RECT], NULL, rptr);
					 DrawRect(rptr);
                     break;
			     case VK_F3:/*F3: ���������Բ*/
					 eptr = GetBlock(sizeof(*eptr));
					 eptr->cx = RandomReal(1.0, GetWindowWidth()-1.0);
					 eptr->cy = RandomReal(1.0, GetWindowHeight()-1.0);
					 eptr->rx = RandomReal(0.5, 3.0);
					 eptr->ry = RandomReal(0.5, 2.0);
					 eptr->PenSize = GetPenSize();
					 eptr->color = GetPenColor();
					 eptr->isSelected = FALSE;
					 InsertNode(list[ELLIPSE], NULL, eptr);
					 DrawCenteredEllipse(eptr);
                     break;
			     case VK_F4:/*F4: ������ɿյ��ı�����*/
			         if (inText) break;/*���Ѵ����ı��༭״̬���������µĿ��ı�*/
					 inText = TRUE; /*�����µ��ı�������״̬*/
					 tptr = GetBlock(sizeof(*tptr));
					 tptr->x = RandomReal(1.0, GetWindowWidth()-1.0);
                     tptr->y = RandomReal(1.0, GetWindowHeight()-1.0);
					 MovePen(tptr->x, tptr->y);/*�ı���ʾ��ʼλ��*/
	 	   			 DrawTextString(CURSOR);/*��ʾ���*/
                     textbuf[0] = '\0'; /*�γ��ַ���*/
                     tptr->PointSize = GetPointSize();
                     tptr->color = GetPenColor();
                     tptr->isSelected = FALSE;
                     tptr->curPos = 0; /*���õ�ǰ���λ��*/
                     tptr->isDisplayed = TRUE; /*���ù����˸��־*/ 
                     startTimer(CURSOR_BLINK, timerseconds);/*�����˸��ʱ������*/
                     isCursorBlink = TRUE;/*���ù����˸��־*/
                     break;
                 case VK_F5: /*�༭�����ı���*/ 
					if (!isSelected || curList != STRING) break;/*��ǰ�������ı��б༭״̬*/
					if (inText) break;/*�Ѵ����ı��б༭״̬*/
					inText = TRUE;/*�����ı��༭״̬*/
					tptr = curText;/*ȡ��ǰѡ�е��ı�����*/
					strcpy(textbuf, tptr->text);/*����ǰ�ı��ַ�����������ʱ�ı��������Ա��༭*/
					DeleteNode(list[STRING], curText, TextEqual);/*�ӵ�ǰ�ı�������ɾ�����ı�����*/
					SetPenColor(tptr->color); /*����ѡ���ı�����ɫ*/
					DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*��ʾ��ǰ�ı����*/
					tptr->isDisplayed = TRUE; /*���õ�ǰ�ı������˸��־*/ 
            		startTimer(CURSOR_BLINK, timerseconds);/*�����˸��ʱ������*/
            		isCursorBlink = TRUE; /*���ù����˸״̬*/
                    break;
                 case VK_LEFT: /*���Ƽ�*/
                 	if (!inText) break;/*�������ı��༭״̬*/
                    SetEraseMode(TRUE);
	 	   			MovePen(tptr->x, tptr->y);
	 	   			DrawTextString(textbuf);/*������ǰ�ı�*/
					DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y); /*�������*/
                    if (tptr->curPos>0) tptr->curPos--;/*���ƹ��һ���ַ�λ��*/
                    SetEraseMode(FALSE);
	 	   			MovePen(tptr->x, tptr->y);
	 	   			DrawTextString(textbuf);/*������ʾ��ǰ�ı�*/
					DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y); /*��ʾ���*/
					break;                     
                 case VK_RIGHT: /*���Ƽ�*/
                 	if (!inText) break;/*�������ı��༭״̬*/
                    SetEraseMode(TRUE);
	 	   			MovePen(tptr->x, tptr->y);
	 	   			DrawTextString(textbuf);/*������ǰ�ı�*/
					DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y); /*�������*/
                    if (tptr->curPos<strlen(textbuf)) tptr->curPos++;/*���ƹ��һ���ַ�λ��*/
                    SetEraseMode(FALSE);
	 	   			MovePen(tptr->x, tptr->y);
	 	   			DrawTextString(textbuf);/*������ʾ��ǰ�ı�*/
					DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y); /*��ʾ���*/
				    break;                     
			     case VK_DELETE:/*DELETE*/
				    if (inText) { /*�������ı��༭״̬����ɾ����ǰ�ַ�*/
						SetEraseMode(TRUE);
						MovePen(tptr->x, tptr->y);
						DrawTextString(textbuf);
						DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*������ǰ���*/
						DeleteCharFromString(textbuf, tptr->curPos);/*ɾ����ǰλ�õ��ַ�*/
				 	   	SetEraseMode(FALSE);
				 	   	TraverseAllList();/*ˢ������ͼ��Ԫ��*/
				 	   	MovePen(tptr->x, tptr->y);
				 	   	DrawTextString(textbuf);
				 	   	DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*��ʾ��ǰ���*/
				    	break;	
				    }
				    if (!isSelected) break;
				    /*����ɾ��ѡ�е�ͼ��Ԫ��*/
			  		SetEraseMode(TRUE);
               		TraverseAllList();
		         	switch (curList) {
		         	  	case LINE:
					 		DeleteNode(list[LINE], curLine, LineEqual);
		         	  		break;
		         	  	case RECT:
		         	  		DeleteNode(list[RECT], curRect, RectEqual);
		         	  		break;
		         	  	case ELLIPSE:
					 		DeleteNode(list[ELLIPSE], curEllipse, EllipseEqual);
		         	  		break;
		         	  	case STRING:
		         	  		DeleteNode(list[STRING], curText, TextEqual);
		         	  		break;
		         	}
				    SetEraseMode(FALSE);
		         	TraverseAllList();
		         	isSelected = FALSE; 
                    break;
                case VK_ESCAPE:/*�˳�ͼ��Ԫ��ѡ��״̬*/
                	  if (!isSelected) break;/*������ѡ��״̬�򲻴���*/
		         	  switch (curList) {
		         	  	case LINE:
		         	  		curLine->isSelected = FALSE;
		         	  		curLine->color = GetPenColor();
		         	  		break;
		         	  	case RECT:
		         	  		curRect->isSelected = FALSE;
		         	  		curRect->color = GetPenColor();
		         	  		break;
		         	  	case ELLIPSE:
		         	  		curEllipse->isSelected = FALSE;
		         	  		curEllipse->color = GetPenColor();
		         	  		break;
		         	  	case STRING:
		         	  		curText->isSelected = FALSE;
		         	  		curText->color = GetPenColor();
		         	  		break;
		         	  }
		         	  isSelected = FALSE; 
		         	  TraverseAllList();
                	  break;
			 }
			 break;
		case KEY_UP:
			 break;
	 }	 
}

void CharEventProcess(char c)
{
	int len;

	if (!inText) return;
    switch (c) {
    	case 27: /*ESC*/
    	case '\r':  /* ע�⣺�س������ﷵ�ص��ַ���'\r'������'\n'*/
			inText = FALSE;/*�˳���ǰ�ı�����*/
           	SetEraseMode(TRUE);
	 	   	MovePen(tptr->x, tptr->y);
	 	   	DrawTextString(textbuf);
			DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*������ǰ���*/
			TraverseAllList();
			tptr->isDisplayed = FALSE;
			tptr->text = CopyString(textbuf);/*�����ַ����ռ�*/
           	InsertNode(list[STRING], NULL, tptr);
           	SetEraseMode(FALSE);
			TraverseAllList();
			cancelTimer(CURSOR_BLINK);/*ע�������˸��ʱ��*/
			isCursorBlink = FALSE;
			SetPenColor(SYSCOLOR);
			break;
 	    case '\b':/*BACKSPACE*/
 	    	if ((len = strlen(textbuf)) == 0) break;
			SetEraseMode(TRUE);
			MovePen(tptr->x, tptr->y);
			DrawTextString(textbuf);
			DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*������ǰ���*/
			DeleteCharFromString(textbuf, tptr->curPos-1);
	 	   	SetEraseMode(FALSE);
	 	   	TraverseAllList();
	 	   	MovePen(tptr->x, tptr->y);
	 	   	DrawTextString(textbuf);
	 	   	if (tptr->curPos > 0) tptr->curPos--;
	 	   	DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*��ʾ��ǰ���*/
 	    	break;
    	default:
    		if ((len = strlen(textbuf)) >= TEXTLEN) break; 
			SetEraseMode(TRUE);
			MovePen(tptr->x, tptr->y);
			DrawTextString(textbuf);
			DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*������ǰ���*/
			InsertCharToString(textbuf, tptr->curPos, c);/*����ǰ�ַ����뵽���λ��*/
	 	   	SetEraseMode(FALSE);
	 	   	MovePen(tptr->x, tptr->y);
	 	   	DrawTextString(textbuf);
	 	   	tptr->curPos++; 
	 	   	DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);/*��ʾ��ǰ���*/
			break;
    }
}

void MouseEventProcess(int x, int y, int button, int event)
{
	static bool isMove = FALSE; /*�ƶ���־*/
	static bool isChangeSize = FALSE; /*���ű�־*/ 
 	static double omx = 0.0, omy = 0.0;/*ǰһ�������*/
    double mx, my;/*��ǰ�������*/
	double x1, y1, x2, y2, dx, dy;
	 
 	mx = ScaleXInches(x);/*pixels --> inches*/
	my = ScaleYInches(y);/*pixels --> inches*/
 
	switch (event) {
		case BUTTON_DOWN:
			if (isSelected) { /*����ѡ��״̬*/
       	    	omx = mx;
			  	omy = my;
			   	if (button == LEFT_BUTTON) { /*������£������ƶ�״̬*/
         	    	isMove = TRUE;
         	    } else if (button == RIGHT_BUTTON) {/*�Ҽ������£���������״̬*/
         	    	isChangeSize = TRUE;
         	    }
				break;
         	} 
         	PickNearestNode(list, mx, my);/*ѡ�����*/ 
         	switch (curList) {
         	  	case LINE:
					if( curLine ) {
	         	  		curLine->isSelected = TRUE;
		     	  		curLine->color = CopyString("GREEN");
					}
         	  		break;
         	  	case RECT:
         	  		curRect->isSelected = TRUE;
         	  		curRect->color = CopyString("GREEN");
         	  		break;
         	  	case ELLIPSE:
         	  		curEllipse->isSelected = TRUE;
         	  		curEllipse->color = CopyString("GREEN");
         	  		break;
         	  	case STRING:
         	  		curText->isSelected = TRUE;
         	  		curText->color = CopyString("GREEN");
         	  		break;
         	  }
         	  isSelected = TRUE;
         	  TraverseAllList();
              break;
		case BUTTON_DOUBLECLICK:
			break;
		case BUTTON_UP:
        	isMove = FALSE; /*�˳��ƶ�״̬*/
         	isChangeSize = FALSE;/*�˳�����״̬*/ 
            break;
		case MOUSEMOVE:
			if (isSelected && (isMove || isChangeSize)) { /*ѡ��״̬�£��ƶ�������*/ 
			  	SetEraseMode(TRUE);
               	TraverseAllList();
               	dx = mx - omx;
               	dy = my - omy;
				if (isMove) { /*�ƶ�*/
					switch (curList){
						case LINE:
					  		curLine->x1 += dx;
					  		curLine->y1 += dy;
							curLine->x2 += dx;
							curLine->y2 += dy;
							break;
		 		    	case RECT:
					  		x1 = curRect->x1 + dx;
					  		y1 = curRect->y1 + dy;
					  		x2 = curRect->x2 + dx;
					  		y2 = curRect->y2 + dy;
					  		if (x1 < x2) {
                         		curRect->x1 = x1;
                         		curRect->x2 = x2;
					  		} else {
                         		curRect->x1 = x2;
                         		curRect->x2 = x1;
					  		}
					  		if (y1 < y2) {
                         		curRect->y1 = y1;
                         		curRect->y2 = y2;
					  		} else {
                         		curRect->y1 = y2;
                         		curRect->y2 = y1;
					  		}
					  		break;
		 		  		case ELLIPSE:
					  		curEllipse->cx += dx;
					  		curEllipse->cy += dy;
					  		break;
		 		  		case STRING:
					  		curText->x += dx;
					  		curText->y += dy;
					  		break;
				  	}
			  	} else if (isChangeSize) {/*����*/
					switch (curList){
						case LINE:
							if (fabs(omx-curLine->x1)+fabs(omy-curLine->y1) <
							    fabs(omx-curLine->x2)+fabs(omy-curLine->y2)) {
					  			curLine->x1 += dx;
					  			curLine->y1 += dy;
						    } else {
   								curLine->x2 += dx;
								curLine->y2 += dy;
						    }
							break;
		 		    	case RECT:
		 		    		if (fabs(omx-curRect->x1) < fabs(omx-curRect->x2)) {
		 		    			curRect->x1 += dx;
		 		    		} else {
		 		    			curRect->x2 += dx;
		 		    		}
		 		    		if (fabs(omy-curRect->y1) < fabs(omy-curRect->y2)) {
		 		    			curRect->y1 += dy;
		 		    		} else {
		 		    			curRect->y2 += dy;
		 		    		}
					  		break;
		 		  		case ELLIPSE:
					  		curEllipse->rx += dx;
					  		curEllipse->ry += dy;
					  		break;
		 		  		case STRING:
		 		  			//curText->PointSize + (dx>0?1:-1);
					  		break;
				  	}
				}
				omx = mx;
				omy = my;
				SetEraseMode(FALSE);
				TraverseAllList();
			}
            break;
    }	
}

void TimerEventProcess(int timerID)
{
	switch (timerID) {
		case CURSOR_BLINK: /*100ms�����˸��ʱ��*/
			SetEraseMode(!tptr->isDisplayed);
			DrawCursor(textbuf, tptr->curPos, tptr->x, tptr->y);
			SetEraseMode(FALSE);
			MovePen(tptr->x, tptr->y);
			DrawTextString(textbuf);
			tptr->isDisplayed=!tptr->isDisplayed;
			break;
	    default:
			break;
	}
}

/*for Line*/
void DrawLineD(void *line)
{
	LineT lptr = (LineT)line;
	int pensize = GetPenSize();/*���浱ǰϵͳ�ʻ���ϸ*/
	string color = GetPenColor();/*���浱ǰϵͳ��ɫ*/

	SetPenSize(lptr->PenSize);/*���ô�ϸ*/
	SetPenColor(lptr->color);/*������ɫ*/
	MovePen(lptr->x1, lptr->y1);
	DrawLine(lptr->x2-lptr->x1,lptr->y2-lptr->y1);
	SetPenSize(pensize); /*�ָ���ϸ*/
	SetPenColor(color);/*�ָ���ɫ*/
}

bool LineEqual(void *line1, void *line2)
{
	LineT lptr1 = (LineT)line1, lptr2 = (LineT)line2;

	return lptr1->x1 == lptr2->x1 && lptr1->y1 == lptr2->y1 &&
           lptr1->x2 == lptr2->x2 && lptr1->y2 == lptr2->y2;
}

double distLine(double x, double y, LineT line)
{
	double x0, y0;

	x0 = (line->x1 + line->x2)/2;
	y0 = (line->y1 + line->y2)/2;
	return fabs(x-x0) + fabs(y-y0);
}

LineT SelectNearestNodeL(linkedlistADT list, double mx, double my)
{
	linkedlistADT nearestnode = NULL, ptr;
	double mindistance, dist;

	ptr = NextNode(list, list);
	if (ptr == NULL) return NULL;
    nearestnode = ptr;
  	mindistance = distLine(mx, my, (LineT)NodeObj(list, ptr));
	while (NextNode(list, ptr) != NULL) {
		ptr = NextNode(list, ptr);
  	    dist = distLine(mx, my, (LineT)NodeObj(list, ptr));
		if (dist < mindistance) {
			nearestnode = ptr;
			mindistance = dist;
		}
	}
	minDistance[LINE] = mindistance;

	return (LineT)NodeObj(list, nearestnode);
}

/*for rectangle */
void DrawRect(void *rect)
{
	RectT r = (RectT)rect;
	int pensize = GetPenSize();/*���浱ǰϵͳ�ʻ���ϸ*/
	string color = GetPenColor();/*���浱ǰϵͳ��ɫ*/

	SetPenSize(r->PenSize);/*���ô�ϸ*/
	SetPenColor(r->color);/*������ɫ*/
	MovePen(r->x1, r->y1);
	DrawLine(r->x2-r->x1, 0);
	DrawLine(0, r->y2-r->y1);
	DrawLine(r->x1-r->x2, 0);
	DrawLine(0, r->y1-r->y2);
	SetPenSize(pensize); /*�ָ���ϸ*/
	SetPenColor(color);/*�ָ���ɫ*/
}

bool RectEqual(void *rect1, void *rect2)
{
	RectT r1, r2;

	r1 = (RectT)rect1;
	r2 = (RectT)rect2;
	return r1->x1 == r2->x1 && r1->y1 == r2->y1 &&
		   r1->x2 == r2->x2 && r1->y2 == r2->y2;
}

double distRect(double x, double y, RectT rect)
{
	double x0, y0;

	x0 = (rect->x1 + rect->x2)/2;
	y0 = (rect->y1 + rect->y2)/2;
	return fabs(x-x0)+fabs(y-y0);
}

RectT SelectNearestNodeR(linkedlistADT list, double mx, double my)
{
	linkedlistADT nearestnode = NULL, ptr;
	double mindistance, dist;

	ptr = NextNode(list, list);
	if (ptr == NULL) return NULL;
    nearestnode = ptr;
  	mindistance = distRect(mx, my, (RectT)NodeObj(list, ptr));
	while (NextNode(list, ptr) != NULL) {
		ptr = NextNode(list, ptr);
  	    dist = distRect(mx, my, (RectT)NodeObj(list, ptr));
		if (dist < mindistance) {
			nearestnode = ptr;
			mindistance = dist;
		}
	}
	minDistance[RECT] = mindistance;

	return (RectT)NodeObj(list, nearestnode);
}

/*For ellipse*/
void DrawCenteredEllipse(void *ellipse)
{
	EllipseT eptr = (EllipseT)ellipse;
	int pensize = GetPenSize();
	string color = GetPenColor();

	SetPenSize(eptr->PenSize);
	SetPenColor(eptr->color);
	MovePen(eptr->cx + eptr->rx, eptr->cy);
    DrawEllipticalArc(eptr->rx, eptr->ry, 0.0, 360.0);
    SetPenSize(pensize);
    SetPenColor(color);
}

bool EllipseEqual(void *ellipse1, void *ellipse2)
{
	EllipseT eptr1 = (EllipseT)ellipse1, eptr2 = (EllipseT)ellipse2;

	return eptr1->cx == eptr2->cx && eptr1->cy == eptr2->cy &&
           eptr1->rx == eptr2->rx && eptr1->ry == eptr2->ry;

}

double distEllipse(double x, double y, EllipseT ellipse)
{
	return fabs(x-ellipse->cx) + fabs(y-ellipse->cy);
}

EllipseT SelectNearestNodeE(linkedlistADT list, double mx, double my)
{
	linkedlistADT nearestnode = NULL, ptr;
	double mindistance, dist;

	ptr = NextNode(list, list);
	if (ptr == NULL) return NULL;
    nearestnode = ptr;
	mindistance = distEllipse(mx, my, (EllipseT)NodeObj(list, ptr));
	while (NextNode(list, ptr) != NULL) {
		ptr = NextNode(list, ptr);
  	    dist = distEllipse(mx, my, (EllipseT)NodeObj(list, ptr));
		if (dist < mindistance) {
			nearestnode = ptr;
			mindistance = dist;
		}
	}
	minDistance[ELLIPSE] = mindistance;

	return (EllipseT)NodeObj(list, nearestnode);
}

/*for text*/
void DrawTextT(void *text)
{
	TextT tptr = (TextT)text;
	string color = GetPenColor();
	int pointsize = GetPointSize();
	 
	MovePen(tptr->x, tptr->y);
	SetPenColor(tptr->color);
	SetPointSize(tptr->PointSize);
    DrawTextString(tptr->text);
    SetPenColor(color);
    SetPointSize(pointsize);
}

/*�����*/
void DrawCursor(string str, int curPos, double startx, double starty)
{
	if (curPos < 0 || curPos > strlen(str)) return;
	MovePen(startx+TextStringWidth(SubString(str, 0, curPos-1)), starty);
	DrawTextString(CURSOR);
	return;
}
 
bool TextEqual(void *text1, void *text2)
{
	TextT tptr1 = (TextT)text1, tptr2 = (TextT)text2;

	return StringEqual(tptr1->text, tptr2->text) &&
           tptr1->x == tptr2->x && tptr1->y == tptr2->y;
}

double distText(double x, double y, TextT text)
{
	return fabs(x - text->x) + fabs(y - text->y);
}

TextT SelectNearestNodeT(linkedlistADT list, double mx, double my)
{
	linkedlistADT nearestnode = NULL, ptr;
	double mindistance, dist;

	ptr = NextNode(list, list);
	if (ptr == NULL) return NULL;
    nearestnode = ptr;
	mindistance = distText(mx, my, (TextT)NodeObj(list, ptr));
	while (NextNode(list, ptr) != NULL) {
		ptr = NextNode(list, ptr);
  	    dist = distText(mx, my, (TextT)NodeObj(list, ptr));
		if (dist < mindistance) {
			nearestnode = ptr;
			mindistance = dist;
		}
	}
	minDistance[STRING] = mindistance;

	return (TextT)NodeObj(list, nearestnode);
}

/*Insert char c to the string str at the position pos*/
void InsertCharToString(string str, int pos, char c)
{
	int len;
	
	if (pos < 0 || pos >= TEXTLEN) return;
	len = strlen(str);
	*(str+len+1) = '\0';/*������γ��ַ���*/
	while (len > pos) {
		*(str+len) = *(str+len-1);
		len--;
	}	
	*(str+len) = c;
	return;
}

/*Delete the character at the pos position of string str*/
void DeleteCharFromString(string str, int pos)
{
	int len;
	
	len = strlen(str);
	if (pos < 0 || pos >= len) return;
	
	while (*(str+pos) != '\0') {
		*(str+pos) = *(str+pos+1);
		pos++; 
	}
	return;
}

/*for all*/
void PickNearestNode(linkedlistADT list[], double mx, double my)
{
	int i, minlist;

	curLine = SelectNearestNodeL(list[LINE], mx, my);
	curRect = SelectNearestNodeR(list[RECT], mx, my);
    curEllipse = SelectNearestNodeE(list[ELLIPSE], mx, my);
	curText = SelectNearestNodeT(list[STRING], mx, my);

	minlist = 0;
	for (i = 1; i < NLIST; i++) {
		if (minDistance[i] < minDistance[minlist]) minlist = i;
	}
	curList = minlist;
}

void TraverseAllList()
{
    TraverseLinkedList(list[LINE], DrawLineD);
    TraverseLinkedList(list[RECT], DrawRect);
    TraverseLinkedList(list[ELLIPSE], DrawCenteredEllipse);
    TraverseLinkedList(list[STRING], DrawTextT);
}
