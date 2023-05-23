#include "graphics.h"
#include "extgraph.h"

#define L 0.2
double w,h;
double nw,nh;

void display();
void draw(double nw,double nh, int n);
void Main()
{
	SetWindowTitle("The Wall");
	InitGraphics();
	display();
	
}

void display()
{
	int i, k=1;
	
	h=GetWindowHeight();
	w=GetWindowWidth();
	
	MovePen(w/2,h-2L);
	nw=w/2;
	nh=h-2L;
	
	for(i=1;i<=14;i++){
		draw(nw, nh, i);
		MovePen(w/2-i*L, h-2L-i*L);
		nw=w/2-i*L;
		nh=h-2L-i*L;
		
	}
}

void draw(double nw,double nh, int n)
{
	int k;
	
	for(k=1;k<=n;k++){
		DrawLine(L,0);
		DrawLine(0,-L);
		DrawLine(-2*L,0);
		DrawLine(0,L);
		DrawLine(L,0);
		MovePen(nw+2*L,nh);
		nw=nw+2*L;
	}
	
}













