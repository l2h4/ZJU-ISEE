#include "turtle/turtle.h"

/*


*/
void turtle_peggy()
{
	turtle_pensize(4);		 // ���û��ʵĴ�С
	turtle_pencolor("Pink"); // ���û�����ɫ�������ɫ(pink)
	// ����
	turtle_penup(-100,100);	// ����ǰ������(-100,100)
	turtle_lookat(-30);		// �ʵĽǶ�Ϊ-30��
	turtle_begin_fill();	// �������Ŀ�ʼ��־
	{
		double a = 0.4;
		int i;
		for (i=0; i<=120; i++)
		{
			if (0<=i && i<30 || 60<=i && i<90) 
			{
				a += 0.08;
				turtle_left(3);		//����ת3��
			    turtle_forward(a);	//��ǰ��a�Ĳ���
			}
			else
			{
				a -= 0.08;
				turtle_left(3);
				turtle_forward(a);
			}
		} 
		turtle_end_fill();	// �����������
	}
}

/*
		turtle_penup();		// ���
		turtle_lookat(90);  // �ʵĽǶ�Ϊ90��
		turtle_forward(25);	// ��ǰ�ƶ�25
		turtle_lookat(0);	// ת�����ʵĽǶ�Ϊ0
		turtle_forward(10);
		turtle_pendown();
		turtle_pencolor("White");//(255,155,192);// ���û�����ɫ
turtle_lookat(10);
turtle_begin_fill();
turtle_circle(5);// ��һ���뾶Ϊ5��Բ
turtle_pencolor(160,82,45);// ���û��ʺ������ɫ
turtle_end_fill();
turtle_penup();
turtle_lookat(0);
turtle_forward(20);
turtle_pendown();
turtle_pencolor(255,155,192);
turtle_lookat(10);
turtle_begin_fill();
turtle_circle(5);
turtle_pencolor(160,82,45);
turtle_end_fill();
#ͷ
turtle_pencolor((255,155,192),"pink");
turtle_penup();
turtle_lookat(90);
turtle_forward(41);
turtle_lookat(0);
turtle_forward(0);
turtle_pendown();
turtle_begin_fill();
turtle_lookat(180);
turtle_circle(300,-30);// ˳ʱ�뻭һ���뾶Ϊ300,Բ�Ľ�Ϊ30���԰
turtle_circle(100,-60);
turtle_circle(80,-100);
turtle_circle(150,-20);
turtle_circle(60,-95);
turtle_lookat(161);
turtle_circle(-300,15);
turtle_penup();
turtle_goto(-100,100);
turtle_pendown();
turtle_lookat(-30);
a=0.4
for i in range(60):
   if 0<=i<30 or 60<=i<90:
       a=a+0.08
       turtle_lt(3);//����ת3��
       turtle_forward(a);//��ǰ��a�Ĳ���
   else:
       a=a-0.08
       turtle_lt(3)
       turtle_forward(a)
turtle_end_fill()
#����
turtle_pencolor((255,155,192),"pink")
turtle_penup()
turtle_lookat(90)
turtle_forward(-7)
turtle_lookat(0)
turtle_forward(70)
turtle_pendown()
turtle_begin_fill()
turtle_lookat(100)
turtle_circle(-50,50)
turtle_circle(-10,120)
turtle_circle(-50,54)
turtle_end_fill()
turtle_penup()
turtle_lookat(90)
turtle_forward(-12)
turtle_lookat(0)
turtle_forward(30)
turtle_pendown()
turtle_begin_fill()
turtle_lookat(100)
turtle_circle(-50,50)
turtle_circle(-10,120)
turtle_circle(-50,56)
turtle_end_fill()
#�۾�
turtle_pencolor((255,155,192),"white")
turtle_penup()
turtle_lookat(90)
turtle_forward(-20)
turtle_lookat(0)
turtle_forward(-95)
turtle_pendown()
turtle_begin_fill()
turtle_circle(15)
turtle_end_fill()
turtle_pencolor("black")
turtle_penup()
turtle_lookat(90)
turtle_forward(12)
turtle_lookat(0)
turtle_forward(-3)
turtle_pendown()
turtle_begin_fill()
turtle_circle(3)
turtle_end_fill()
turtle_pencolor((255,155,192),"white")
turtle_penup()
turtle_lookat(90)
turtle_forward(-25)
turtle_lookat(0)
turtle_forward(40)
turtle_pendown()
turtle_begin_fill()
turtle_circle(15)
turtle_end_fill()
turtle_pencolor("black")
turtle_penup()
turtle_lookat(90)
turtle_forward(12)
turtle_lookat(0)
turtle_forward(-3)
turtle_pendown()
turtle_begin_fill()
turtle_circle(3)
turtle_end_fill()
#��
turtle_pencolor((255,155,192))
turtle_penup()
turtle_lookat(90)
turtle_forward(-95)
turtle_lookat(0)
turtle_forward(65)
turtle_pendown()
turtle_begin_fill()
turtle_circle(30)
turtle_end_fill()
#��
turtle_pencolor(239,69,19)
turtle_penup()
turtle_lookat(90)
turtle_forward(15)
turtle_lookat(0)
turtle_forward(-100)
turtle_pendown()
turtle_lookat(-80)
turtle_circle(30,40)
turtle_circle(40,80)
#����
turtle_pencolor("red",(255,99,71))
turtle_penup()
turtle_lookat(90)
turtle_forward(-20)
turtle_lookat(0)
turtle_forward(-78)
turtle_pendown()
turtle_begin_fill()
turtle_lookat(-130)
turtle_circle(100,10)
turtle_circle(300,30)
turtle_lookat(0)
turtle_forward(230)
turtle_lookat(90)
turtle_circle(300,30)
turtle_circle(100,3)
turtle_pencolor((255,155,192),(255,100,100))
turtle_lookat(-135)
turtle_circle(-80,63)
turtle_circle(-150,24)
turtle_end_fill()
#��
turtle_pencolor((255,155,192))
turtle_penup()
turtle_lookat(90)
turtle_forward(-40)
turtle_lookat(0)
turtle_forward(-27)
turtle_pendown()
turtle_lookat(-160)
turtle_circle(300,15)
turtle_penup()
turtle_lookat(90)
turtle_forward(15)
turtle_lookat(0)
turtle_forward(0)
turtle_pendown()
turtle_lookat(-10)
turtle_circle(-20,90)
turtle_penup()
turtle_lookat(90)
turtle_forward(30)
turtle_lookat(0)
turtle_forward(237)
turtle_pendown()
turtle_lookat(-20)
turtle_circle(-300,15)
turtle_penup()
turtle_lookat(90)
turtle_forward(20)
turtle_lookat(0)
turtle_forward(0)
turtle_pendown()
turtle_lookat(-170)
turtle_circle(20,90)
#��
turtle_pensize(10)
turtle_pencolor((240,128,128))
turtle_penup()
turtle_lookat(90)
turtle_forward(-75)
turtle_lookat(0)
turtle_forward(-180)
turtle_pendown()
turtle_lookat(-90)
turtle_forward(40)
turtle_lookat(-180)
turtle_pencolor("black")
turtle_pensize(15)
turtle_forward(20)
turtle_pensize(10)
turtle_pencolor((240,128,128))
turtle_penup()
turtle_lookat(90)
turtle_forward(40)
turtle_lookat(0)
turtle_forward(90)
turtle_pendown()
turtle_lookat(-90)
turtle_forward(40)
turtle_lookat(-180)
turtle_pencolor("black")
turtle_pensize(15)
turtle_forward(20)
#β��
turtle_pensize(4)
turtle_pencolor((255,155,192))
turtle_penup()
turtle_lookat(90)
turtle_forward(70)
turtle_lookat(0)
turtle_forward(95)
turtle_pendown()
turtle_lookat(0)
turtle_circle(70,20)
turtle_circle(10,330)
turtle_circle(70,30)
*/