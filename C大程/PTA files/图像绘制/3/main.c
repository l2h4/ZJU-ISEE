#include"anglefunction.h"
#include"graphics.h"
#define L 1

void display();
void draw();

void Main()
{
	InitGraphics();
	SetPenColor("Green");
	display();
	draw();
	
	Turn(3.14*2/18);
	draw();
	Turn(-3.14*2/18);
	
	Turn(2*3.14*2/18);
	draw();
}

void display()
{
	double w,h;
	int i;
	w=GetWindowWidth();
	h=GetWindowHeight();
	w=w/2;
	h=h/2;
	
	MovePen(w,h);
	
	for(i=1;i<=18;i++){
		Forward(L);
		Turn(3.14/3);
		Forward(L);
		move(-L);
		Turn(-3.14*2/3);
		Forward(L);
		MovePen(w,h);
		Turn(3.14/3);
		Turn(2*3.14/18);
	}
	
}

void draw()
{
	int i;
	
	move(L);
	Turn(3.14/3);
	move(L);
	Turn(3.14/3);
	Forward(L);
	for(i=1;i<=5;i++){
		Turn(3.14/3);
		Forward(2L);
	}
	Turn(3.14/3);
	Forward(L);
	
	Turn(-3.14/3);
	move(-L);
	Turn(-3.14/3);
	move(-L);
	
}













