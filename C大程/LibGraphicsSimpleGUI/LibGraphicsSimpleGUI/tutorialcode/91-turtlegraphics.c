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


#include "turtle/turtle.h"

#ifdef M_PI
#error "�����case"
#endif

void display()
{
	MovePen(4, 4);
	turtle_lookat(90);
	turtle_show(0.3);
}

void Main()
{
	SetWindowTitle("�ڹ껭ͼ");
	InitGraphics();

	display();
}