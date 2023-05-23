#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"
#include "strlib.h"
#include "function.h"

#define L 0.05

static double winwidth, winheight;
static char str[200];
static int n=0;

void display(void);
void drawEditText();
void drawbutton();
void drawtree(int i);

void CharEventProcess(char ch)
{
	uiGetChar(ch);
	display();
}

void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event);
	display();
	
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

	InitGraphics();
	
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	registerCharEvent(CharEventProcess);
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	
}

void drawbutton()
{
	double fH=GetFontHeight();
	double h = fH*2;
	double w = winwidth/20;
	double x = w;
	double y = winheight-2*h;
	int i=n;
	
	if(button(GenUIID(1),x, y,w,h,"click here to draw")){
		MovePen(winwidth/2,0);
		drawtree(i);
	}

}

void drawEditText()
{
	int i;
	
	double fH=GetFontHeight();
	double h = fH*2;
	double w = winwidth/20;
	double x = 0;
	double y = winheight-2*h;


	SetPenColor("Brown");
	textbox(GenUIID(0), x, y, w, h, str, sizeof(str));
	n=StringToInteger(str);
}

void display()
{
	DisplayClear();
	drawEditText();
	drawbutton();
}

void drawtree(int i)
{
	int j;
	if(i==1){
		return;
	}else{
		SetPenSize(i);
		Forward(n*L);
		Turn(3.14/3);
		for(j=i;j<=n;j++){
			drawtree(i-1);
			Turn(-3.14/3);
		}
	}
}


















