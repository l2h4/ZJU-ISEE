#include "extgraph.h"

void Main()
{
	/*
	 * Part 1: 窗口相关函数
	 */ 
	//SetWindowSize(10 * 2, 7 * 2);
	
	InitGraphics();
	
	InitConsole();
	
	string title = GetWindowTitle();
	printf("Window Title: %s\n", title);
	SetWindowTitle("My first GUI app");
	title = GetWindowTitle();
	printf("Window Title: %s\n", title);
	
	double width  = GetWindowWidth();
	double height = GetWindowHeight();
	printf("Window Width and Height: %lf %lf\n", width, height);
	//SetWindowSize(width * 2, height * 2);
	
	double widthfull  = GetFullScreenWidth();
	double heightfull = GetFullScreenHeight();
	printf("Full Screen Width and Height: %lf %lf\n", widthfull, heightfull);
	
	double xres = GetXResolution();
	double yres = GetYResolution();
	printf("Resolution (pixels per inch): %lf x %lf\n", xres, yres);
	printf("Window Resolution (pixels): %lf x %lf\n", width * xres, height * yres);
	printf("Full Window Resolution (pixels): %lf x %lf\n", widthfull * xres, heightfull * yres);
	
	int x = 0, y = 0;
	double dx = ScaleXInches(x);
	double dy = ScaleYInches(y);
	printf("Pixel Position to Physical Position: (%d, %d) -> (%lf, %lf)\n", x, y, dx, dy);
	
	x = width * xres;
	y = height * yres;
	dx = ScaleXInches(x);
	dy = ScaleYInches(y);
	printf("Pixel Position to Physical Position: (%d, %d) -> (%lf, %lf)\n\n", x, y, dx, dy);
	
	/*
	 * Part 2: 基本绘图函数：画笔，直线，圆，圆弧，椭圆，椭圆弧，文字
	 */ 
	double cx = GetCurrentX();
	double cy = GetCurrentY();
	printf("Current Pen Position: (%lf, %lf)\n", cx, cy);
	
	MovePen(width, height);
	cx = GetCurrentX();
	cy = GetCurrentY();
	printf("Current Pen Position: (%lf, %lf)\n", cx, cy);
	
	DrawLine(-width + 1, -height + 1);
	cx = GetCurrentX();
	cy = GetCurrentY();
	printf("Current Position: (%lf, %lf)\n\n", cx, cy);
	
	MovePen(width / 2, height / 2);
	DrawArc(2, 40, 90);

	MovePen(width / 2, height / 2);
	DrawArc(2, 0, 180);
	
	MovePen(width / 2, height / 2);
	DrawEllipticalArc(1, 3, 0, 180);
	
	//DisplayClear();
	
	string str = "Hello Win32!";
	MovePen(width / 2, height / 2);
	DrawTextString(str);
	
	double tw = TextStringWidth(str);
	MovePen(width / 2 - tw / 2, height / 2 + 0.2);
	DrawTextString(str);
	
	char buf[128];
	double data = 12345;
	//scanf("%lf", &data); 
	sprintf(buf, "The value is %lf!", data);
	tw = TextStringWidth(buf);
	MovePen(width / 2 - tw / 2, height / 2 + 2.4);
	DrawTextString(buf);
	
	//DisplayClear();
	//UpdateDisplay();
	//Pause(10);
	
	SetEraseMode(TRUE);
	//SetEraseMode(FALSE);
	MovePen(width / 2, height / 2);
	DrawArc(2, 0, 360);
	SetEraseMode(FALSE);
	
	/*
	 * Part 3: 基本绘图属性 
	 */
	
	DefineColor("MyFirstColor", 0.1, 0.6, 0.7);
	
	int pensize  = GetPenSize();
	string color = GetPenColor();
	printf("Pen Size: %d\n", pensize);
	printf("Pen Color: %s\n", color);
	SetPenSize(3);
	SetPenColor("Red");
	MovePen(width / 2, height / 2);
	DrawArc(2, 0, 360);
	SetPenSize(pensize);
	SetPenColor(color);
	
	//DisplayClear();
	int pointSize = GetPointSize();
	printf("Point Size: %d\n", pointSize);
	SetPointSize(3);
	MovePen(width / 2, height / 3);
	DrawArc(2, 0, 360);
	SetPointSize(pointSize);
	
	double w = 1, h = 1;
	SetPenColor("MyFirstColor");
	MovePen(width / 2 - w / 2, height / 3 - h / 2);
    StartFilledRegion(1);
    DrawLine(0, h);
    DrawLine(w, 0);
    DrawLine(0, -h);
    DrawLine(-w, 0);
    EndFilledRegion(); 
	SetPenColor(color);
	
	string font = GetFont();
	printf("Font: %s\n", font);
	
	int style = GetStyle();
	switch(style) {
		case Normal:
			printf("Font Style: Normal\n");
			break;
		case Bold:
			printf("Font Style: Bold\n");
			break;
		case Italic:
			printf("Fon Style: Italic\n");
			break;   
	}
	SetStyle(Italic);
	MovePen(width / 2, height / 3);
	DrawTextString(str);
	SetStyle(style);
	
	double fontAscent  = GetFontAscent();
	double fontDescent = GetFontDescent();
	double fontHeight  = GetFontHeight();
	printf("Font Ascent: %lf\n", fontAscent);
	printf("Font Descent: %lf\n", fontDescent);
	printf("Font Height: %lf\n", fontHeight);
	tw = TextStringWidth(str);
	MovePen(width / 2 - tw / 2, height / 3 - fontAscent / 2);
	DrawTextString(str);
}
