//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��24�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================

#include <math.h>
#include "turtle.h"
#include "graphics.h"
#include "extgraph.h"

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

static double turtle_front = 0; // ������ǰ���Ƕ�
static int turtle_filling_flag = 0; //���״̬��־
static int turtle_pendown_flag = 0;

static double turtle_to_win_scale = 1; // �����ƶ�����
static double turtle_to_win_tx = 0; 
static double turtle_to_win_ty = 0; 

static double Turtle2WinX(double x)
{
	return turtle_to_win_tx + x * turtle_to_win_scale;
}

static double Turtle2WinY(double y)
{
	return turtle_to_win_ty + y * turtle_to_win_scale;
}

// �����˶�����

void turtle_put(double x, double y)
{
	MovePen(Turtle2WinX(x),Turtle2WinY(y));
}

void turtle_pendown()
{
	turtle_pendown_flag = 1;
}

void turtle_penup()
{
	turtle_pendown_flag = 0;
}

void turtle_lookat(double angle)
{
	turtle_front = angle;
}

// ��ǰ���ʷ����ƶ�distance
void turtle_forward(double distance)	
{
	double f = turtle_front/180*M_PI;
	double dx = cos(f)*distance*turtle_to_win_scale;
	double dy = sin(f)*distance*turtle_to_win_scale;
	if( turtle_pendown_flag==1 )
		DrawLine(dx,dy);
	else
	{
		dx += GetCurrentX();
		dy += GetCurrentY();
		MovePen(dx, dy);
	}
}


// ��ǰ�����෴�����ƶ�distance
void turtle_backward(double distance)	
{
	turtle_forward(-distance);
}

// ˳ʱ��ת��degree
void turtle_right(double degree)		
{
	turtle_front -= degree;
}

// ��ʱ��ת��degree
void turtle_left(double degree)			
{	
	turtle_front += degree;
}


// ��Բ,�뾶Ϊ��(��),��ʾԲ���ڻ��ʵ����(�ұ�)��Բ
void turtle_circle(double radius)					
{
	if( turtle_pendown_flag ) {
		double cx = GetCurrentX();
		double cy = GetCurrentY();
		double r = fabs(radius) * turtle_to_win_scale;
		double a = turtle_front + (radius > 0 ? 1 : -1 ) * 90;
		double ny = cy + r*sin(a/180*M_PI);
		double nx = cx + r*cos(a/180*M_PI);
		MovePen(nx+r, ny);
		DrawArc(r,0,360);
		MovePen(cx,cy);
	}
}

void turtle_circle_arc(double radius, double arcdegree)
{
	double cx = GetCurrentX();
	double cy = GetCurrentY();
	double r = fabs(radius) * turtle_to_win_scale;
	double a = turtle_front + (radius > 0 ? 1 : -1 ) * 90;
	double ny = cy + r*sin(a/180*M_PI);
	double nx = cx + r*cos(a/180*M_PI);
	MovePen(nx+r, ny);
	DrawArc(r,0,360);
	MovePen(cx,cy);

}

// ���ʿ�������:

//����ͼ��ʱ�Ŀ��
void turtle_pensize(double width)		
{
	int s = (int)(width*turtle_to_win_scale);
	SetPenSize(s>0?s:1);
}

// ������ɫ
void turtle_pencolor(char colorname[])	
{
	SetPenColor(colorname);
}

// ���ص�ǰ�Ƿ������״̬
int turtle_filling()
{
	return turtle_filling_flag;
}

// ׼����ʼ���ͼ��
void turtle_begin_fill()
{
	if( ! turtle_filling_flag ) {
		StartFilledRegion(1); 
		turtle_filling_flag = 1;
	}
}

// ������
void turtle_end_fill()
{
	if( turtle_filling_flag ) {
		EndFilledRegion();
		turtle_filling_flag = 0;
	}
}

void turtle_show(double scale)
{
	static struct {	double a, d;} t[] = {
		{0, 1.25}, {120, 1}, {60, 1.5}, {60, 1}, {60, 1}, {60, 1.5}, {60, 1},
		{180,0.1}, {90, 0.5}, {70, 0.2}, {60, 0.2}, {70,0.55}

	};
	int k;
	double old_front = turtle_front;
	turtle_circle(0.3*scale);
	turtle_circle(-0.3*scale);
	for( k=0; k<sizeof(t)/sizeof(t[0]); k++ )
	{
		turtle_left(t[k].a);
		turtle_forward(t[k].d*scale);
	}
	turtle_front = old_front;
}