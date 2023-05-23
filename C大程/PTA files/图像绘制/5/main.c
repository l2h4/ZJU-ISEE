#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

#define MY_TIMER 1

static double winwidth, winheight;
static char str[200];
static char ptr[200];
static char result[400];
static int n=0, m=1, l=0;
static char ch1, ch2;


void display(void); 

void TimerEventProcess(int timerID)
{
	if(timerID==MY_TIMER && m==1)
	display();

}

void CharEventProcess(char ch)
{
	uiGetChar(ch);
	display();
}

void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event);
	int i;
	switch(key){
		case VK_RETURN:
			drawLabel(winwidth/2, winheight/2, result);
			m=0;
			break;
		case VK_LEFT:
			n--;
			display();
			break;
		case VK_RIGHT:
			n++;
			display();
			break;
		default:
			ch1=key;
			n++;
			l++;
			display();
			m=1;
			break;
		}

}

void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); 
	switch(event){
		case BUTTON_DOWN:
			display();
			break;
		default:
			break;
	}
}

void Main() 
{

	SetWindowTitle("Graphics User Interface Demo");
	InitGraphics();
	
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	registerCharEvent(CharEventProcess);
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerTimerEvent(TimerEventProcess);

	startTimer(MY_TIMER, 50);
}

void drawEditText()
{
	int i;
	
	double fH=GetFontHeight();
	double h = fH*2;
	double w = winwidth/4;
	double x = winwidth/15;
	double y = winheight/2-h;


	SetPenColor("Brown");
	if(n==l){
		textbox(GenUIID(0), x, y, w, h, str, sizeof(str));
		sprintf(result,"%s",str);
	}else{
		for(i=0;i<n;i++){
			ptr[i]=str[i];
		}
		ptr[i+1]='\0';
		textbox(GenUIID(0), x, y, w, h, ptr, sizeof(ptr));
	}

	
}

void display()
{
	DisplayClear();

	drawEditText();

}
