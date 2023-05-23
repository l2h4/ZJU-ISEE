#include"graphics.h"
#include"extgraph.h"
#include"genlib.h"

#define L 0.6

double w,h;

void display();
void draw();

void Main()
{
	InitGraphics();
	display();
}

void display()
{
	double str;
	string text;
	w=GetWindowWidth();
	h=GetWindowHeight();
	
	MovePen(w/2, h/2+3*L);
	draw();
	text="Program";
	str=TextStringWidth(text);
	MovePen(w/2-str/2,h/2+3*L-L/2);
	DrawTextString(text);
	
	MovePen(w/2, h/2+2*L);
	DrawLine(-3*L,-4*L);
	draw();
	text="GraphicsProgram";
	str=TextStringWidth(text);
	MovePen(w/2-3*L-str/2,h/2-2*L-L/2);
	DrawTextString(text);
	
	MovePen(w/2, h/2+2*L);
	DrawLine(0, -4*L);
	draw();
	text="ConcoleProgram";
	str=TextStringWidth(text);
	MovePen(w/2-str/2,h/2-2*L-L/2);
	DrawTextString(text);
	
	MovePen(w/2, h/2+2*L);
	DrawLine(3*L,-4*L);
	draw();
	text="DialogProgram";
	str=TextStringWidth(text);
	MovePen(w/2+3*L-str/2,h/2-2*L-L/2);
	DrawTextString(text);
}

void draw()
{
	StartFilledRegion(0.5);
	DrawLine(L,0);
	DrawLine(0,-L);
	DrawLine(-2*L,0);
	DrawLine(0,L);
	DrawLine(L,0);
	EndFilledRegion();
	
}
