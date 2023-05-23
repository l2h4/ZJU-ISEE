#include "graphics.h" 
#include "extgraph.h"
#include "imgui.h"

int m=0;
double x0=0, y0=0;

void myMouseEvent (int x, int y, int button, int event)
{
	double x1, y1;
	uiGetMouse(x,y,button,event);
	
	switch(event){
		case BUTTON_UP:
			if(button==LEFT_BUTTON){
				m=0;
				break;
			}
			
		case BUTTON_DOWN:
			if(button==LEFT_BUTTON){
				m=1;
				x0=ScaleXInches(x);
				y0=ScaleYInches(y);
				MovePen(x0,y0);
				break;
			}
			
		case BUTTON_DOUBLECLICK:
			break;
			
		case MOUSEMOVE:
			if(m==1){
				x1=ScaleXInches(x);
				y1=ScaleYInches(y);
				DrawLine(x1-x0,y1-y0);
				MovePen(x1,y1);
				x0=x1;
				y0=y1;
				break;
			}else{
				break;
			}
	}
	
}

void Main()
{
	InitGraphics();
	SetPenColor("Red");

	registerMouseEvent(myMouseEvent);
	
}










