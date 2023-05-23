#include"graphics.h"
#include"extgraph.h"
#include<math.h>
#include<stdio.h>

static double angle=3.14/2;

double GetCurrentAngle()
{
	double w, h, x, y;
	double p;
	
	w=GetWindowWidth();
	h=GetWindowHeight();
	w=w/2;
	h=h/2;
	x=GetCurrentX();
	y=GetCurrentY();
	
	p=(x-w)/(y-h);
	angle=atan(p);
	
	if((x-w)>=0){
		angle=angle;
	}else if((x-w)<0){
		angle=3.14+angle;
	}
	
	return angle;
}

void Turn (double p)
{
	angle=angle-p;
}

void Forward(double distance)
{
	double x,y;
	
	x=distance*cos(angle);
	y=distance*sin(angle);
	
	DrawLine(x,y);
}

void move(double distance)
{
	double x,y;
	double x0,y0;
	
	x=distance*cos(angle);
	y=distance*sin(angle);
	
	x0=GetCurrentX();
	y0=GetCurrentY();
	
	MovePen(x0+x,y0+y);
}












