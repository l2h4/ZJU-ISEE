//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��21�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"

void display()
{
	double x = 1.0; //��λ��Ӣ��
	double y = 1.0; //��λ��Ӣ��
	double w = 1.0; //��λ��Ӣ��
	double h = GetFontHeight() * 2; //��λ��Ӣ��
	// draw a square
	SetPenColor("Blue");
	drawLabel(x, y, "Blue Lable is Here");
	// ȡ�������ע�ͣ�draw ����Ķ���
	drawRectangle(x, y += h*1.2, w, h, 0);
	SetPenColor("Red"); drawBox(x, y += h*1.2, w, h, 0, "Box is here", 'C', "Green");
	SetPenColor("Red"); drawBox(x, y += h*1.2, w, h, 1, "Filled Box is here", 'L', "Green");
}

void Main()
{
	SetWindowTitle("��Щʲô����");
	InitGraphics();

	display();
}