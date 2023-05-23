//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  
//  ���δ�����2018��4��8�գ�����<<�������ר��>>�γ̽�ѧ
//            ��ʾ���ݣ�
//            1. ��ŵ���������
//            2. libgraphics����
//            3. ���ڶ�ջ�ĵݹ�ʵ��
//            
//
//===========================================================================
#include <stdio.h>
#include <stdlib.h>


#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"

#include "hanoi.h"

static double tower_x[3];       // ��x����
static double tower_y;          // ��y����
static double pod_size;         // ���ӵİ뾶
static double pod_height;       // ���Ӹ߶�
static double support_size;     // ���������
static double support_height;   // �������
static double disc_size;        // �������̰뾶
static double disc_height;      // ���̺��

static void set_scales(double winwidth, double winheight)
{
	tower_x[0] = winwidth / 8 * 2;
	tower_x[1] = winwidth / 8 * 4;
	tower_x[2] = winwidth / 8 * 6;
	tower_y    = winheight / 2;
	support_size = winwidth / 5;
	support_height = winheight / 90;
	pod_height = winheight / 3;

	disc_size = support_size * 0.9;
	disc_height = pod_height/(g_disc_count+5);
	pod_size = disc_size/(MAX_DISC_COUNT+9);
}

// ��d�����̵İ뾶�����̴��µ��ϵı������Ϊ��0��1��2��������
static double DiscSize(int d)
{
	return disc_size / g_disc_count * (g_disc_count-d);
}


// draw a rectangle
//    (cx,cy) - center
//       w    - width
//       h    - height
static void draw_rect(double cx, double cy, double w, double h, int fill)
{
	drawRectangle(cx-w/2, cy-h/2, w, h, fill);
}

// draw ����
static void draw_towers()
{
	int k;
	SetPenColor("Blue");
	for( k = 0; k<3; k++ ) {
		// tower pod
		draw_rect(tower_x[k], tower_y+pod_height/2, pod_size*2, pod_height, 1);
		// tower support
		draw_rect(tower_x[k], tower_y-support_height/2,  support_size, support_height, 1);
	}
}


static void draw_disc(double cx, double cy, int d)
{
	double w = DiscSize(d);
	SetPenColor("Red");
	draw_rect(cx, cy, w, disc_height, 1);
	SetPenColor("Blue");
	draw_rect(cx, cy, w, disc_height, 0);
}

// draw ����
static void draw_discs()
{
	int k, j;
	for( k = 0; k<3; k++ ) {
		for( j = 0; j<g_towers[k].discNum; j++ )
		{
			int d = g_towers[k].discList[j];
			double cx = tower_x[k];
			double cy = tower_y + disc_height * ( 0.5 + j );
			draw_disc(cx, cy, d);
		}
	}
}

// ���Բ�ֵ����
double linear_interpolation(double a, double b, double t)
{
	return a*(1-t) + b*t;
}

void draw_flying_disc()
{
	int d = g_flying_disc.id;
	int tF = g_flying_disc.towerFrom;
	int tT = g_flying_disc.towerTo;
	double ft = g_flying_disc.time;
	double s, cx, cy;

	if( d < 0 ) 
		return; // no disc is flying
	
	// compute the position of the flying disc
	if( ft<0.33 ) { // going up����ԭ����������������
		s = ft/0.33;
		cx = tower_x[tF];
		cy = tower_y + linear_interpolation( disc_height * (0.5 + g_towers[tF].discNum), pod_height*1.1, s);
	}
	else if ( ft<0.66 ) { // going horizontally�����µ������ƶ�
		s = (ft-0.33)/0.33;
		cx = linear_interpolation(tower_x[tF], tower_x[tT], s);
		cy = tower_y + pod_height*1.1;

	}
	else { // going down ���䵽�µ���������
		s = (ft-0.66)/0.34;
		cx = tower_x[tT];
		cy = tower_y + linear_interpolation( disc_height * (0.5 + g_towers[tT].discNum), pod_height*1.1, 1-s);
	}

	// draw the disc
	SetPenColor("Red");
	draw_disc(cx, cy, d);
}

void DrawHanoi(double winwidth, double winheight)
{
	// ����������λ�ã����������̵Ļ��Ƴߴ�
	set_scales(winwidth, winheight); 
	draw_towers(); // ����
	draw_discs();  // ����
	draw_flying_disc(); // ���е�����
}



