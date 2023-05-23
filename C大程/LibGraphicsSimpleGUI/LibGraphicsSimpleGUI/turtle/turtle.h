//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��24�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================

#ifndef ___turtle_h_________________
#define ___turtle_h_________________

// �����˶�����
void turtle_put(double x, double y);	// ����turtleλ��

void turtle_lookat(double angle);		// ����turtle��ǰ������
void turtle_forward(double distance);	// ��ǰ���ʷ����ƶ�distance
void turtle_backward(double distance);	// ��ǰ�����෴�����ƶ�distance
void turtle_right(double degree);		// ˳ʱ���ƶ�degree��
void turtle_left(double degree);		// ��ʱ���ƶ�degree��
void turtle_circle(double radius);		// ��Բ,�뾶Ϊ��(��),��ʾԲ���ڻ��ʵ����(�ұ�)��Բ
void turtle_circlearc(double radius, double angle);

// ���ʿ�������:
void turtle_penup();
void turtle_pendown();
void turtle_pensize(double width);		//����ͼ��ʱ�Ŀ��
void turtle_pencolor(char colorname[]);	// ������ɫ
void turtle_beginfill();				// ׼����ʼ���ͼ��
void turtle_endfill();					// �����ɣ�

// �����任
//   win_x = turtle_x * s + cx
//   win_y = turtle_x * s + cy
void turtle_canvas_scale(double s);
void turtle_cancas_translate(double cx, double cy);

// ��ʾһ���ڹ�
void turtle_show(double scale);

#endif //#ifndef ___turtle_h_________________