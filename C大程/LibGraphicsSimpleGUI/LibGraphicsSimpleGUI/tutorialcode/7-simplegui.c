//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2019��3�£�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================

#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

#define DEMO_MENU
#define DEMO_BUTTON
#define DEMO_ROTATE
#define DEMO_EDITBOX


/***************************************************************
 VisualStudio 2010 �û�ע�⣺
    ��Character Set����Ϊ Use Multibyte Character Set
	����������ʾ������
***************************************************************/

// ȫ�ֱ���
static double winwidth, winheight;   // ���ڳߴ�
static float  rot_angle = 0;         // ��������ת�Ƕ�
static int    enable_rotation = 1;   // ������ת
static int    show_more_buttons = 0; // ��ʾ���ఴť

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// �û����ַ��¼���Ӧ����
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	display(); // ˢ����ʾ
}

// ��ת��ʱ��
#define MY_ROTATE_TIMER  1

// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	if( timerID==MY_ROTATE_TIMER && enable_rotation ) 
	{
		rot_angle += 10; // ȫ�ֱ���
		display(); // ˢ����ʾ
	}
}

// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("Graphics User Interface Demo");
	//SetWindowSize(10, 10); // ��λ - Ӣ��
	//SetWindowSize(15, 10);
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
    InitGraphics();

	// ��ô��ڳߴ�
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��

	// ������ʱ��
	startTimer(MY_ROTATE_TIMER, 50);            

	// �򿪿���̨��������printf/scanf���/�������Ϣ���������
	// InitConsole(); 
}

#if defined(DEMO_MENU)
// �˵���ʾ����
void drawMenu()
{ 
	static char * menuListFile[] = {"File",  
		"Open  | Ctrl-O", // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
		"Close",
		"Exit   | Ctrl-E"};
	static char * menuListTool[] = {"Tool",
		"Triangle",
		"Circle",
		"Stop Rotation | Ctrl-T"};
	static char * menuListHelp[] = {"Help",
		"Show More  | Ctrl-M",
		"About"};
	static char * selectedLabel = NULL;

	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH*1.5; // �ؼ��߶�
	double w = TextStringWidth(menuListHelp[0])*2; // �ؼ����
	double wlist = TextStringWidth(menuListTool[3])*1.2;
	double xindent = winheight/20; // ����
	int    selection;
	
	// menu bar
	drawMenuBar(0,y-h,winwidth,h);
	// File �˵�
	selection = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	if( selection>0 ) selectedLabel = menuListFile[selection];
	if( selection==3 )
		exit(-1); // choose to exit
	
	// Tool �˵�
	menuListTool[3] = enable_rotation ? "Stop Rotation | Ctrl-T" : "Start Rotation | Ctrl-T";
	selection = menuList(GenUIID(0),x+w,  y-h, w, wlist,h, menuListTool,sizeof(menuListTool)/sizeof(menuListTool[0]));
	if( selection>0 ) selectedLabel = menuListTool[selection];
	if( selection==3 )
		enable_rotation = ! enable_rotation;
	
	// Help �˵�
	menuListHelp[1] = show_more_buttons ? "Show Less | Ctrl-M" : "Show More | Ctrl-M";
	selection = menuList(GenUIID(0),x+2*w,y-h, w, wlist, h, menuListHelp,sizeof(menuListHelp)/sizeof(menuListHelp[0]));
	if( selection>0 ) selectedLabel = menuListHelp[selection];
	if( selection==1 )
		show_more_buttons = ! show_more_buttons;

	// ��ʾ�˵����н��
	x = winwidth/15;
	y = winheight/8*7;
	SetPenColor("Blue");
	drawLabel(x,    y-=h, "Most recently selected menu is:");
	SetPenColor("Red");
	drawLabel(x+xindent, y-=h, selectedLabel);
	SetPenColor("Blue");
	drawLabel(x,    y-=h, "Control Variable Status");
	SetPenColor("Red");
	drawLabel(x+xindent, y-=h, enable_rotation ? "Rotation Enabled" : "Rotation Disabled");
	drawLabel(x+xindent, y-=h, show_more_buttons ? "More Buttons" : "Less Button");
}
#endif // #if defined(DEMO_MENU)

#if defined(DEMO_ROTATE)
// ��ת��������ʾ����
#include <math.h>

// �������ε����������ת
// cenx, ceny - ��ת���ĵ�����
// angle - ��ת�Ƕ�
// tri[i][0/1] - �����ε� i �������x/y����
void rot_triangle(double cenx, double ceny, double angle, double tri[][2])
{
	double c = cos(angle/180*3.14159265);
	double s = sin(angle/180*3.14159265);
	int k;
	for( k = 0; k<3; k++ )
	{
		double dx = tri[k][0]-cenx;
		double dy = tri[k][1]-ceny;
		tri[k][0] = cenx + dx * c - dy * s;
		tri[k][1] = ceny + dx * s + dy * c;
	}
}

// �������� <t[0], t[1], t[2]>
void draw_triangle(double t[][2])
{
	MovePen(t[0][0], t[0][1]);
	DrawLine(t[1][0]-t[0][0], t[1][1]-t[0][1]);
	DrawLine(t[2][0]-t[1][0], t[2][1]-t[1][1]);
	DrawLine(t[0][0]-t[2][0], t[0][1]-t[2][1]);
}

// ����ת������
void drawRotateTriangle()
{
	double cx = winwidth/5*4;
	double cy = winheight/4*3;
	double dtx = winwidth/15;
	double dty = winheight/8;
	double tri[3][2] = // ����һ��������
	{ {cx, cy}, {cx+dtx, cy}, {cx+dtx/2, cy+dty} };
	double fH = GetFontHeight();
	double h = fH*2; // �ؼ��߶�
	double w = winwidth/5; // �ؼ����
	double x = winwidth/2.5;
	double y = winheight/4*3;

	// ������
	rot_triangle(tri[0][0],tri[0][1],rot_angle,tri);
	SetPenColor("Green");
	draw_triangle(tri);

	// ��ת��ť
	if (button(GenUIID(0), x, y+h, w, h, enable_rotation ? "Stop Rotation" : "Start Rotation"))
		enable_rotation = ! enable_rotation;

	// �����˳���ť
	if( button(GenUIID(0), x, y-h, w, h, "Click to Quit") )
		exit(-1);
}
#endif //#if defined(DEMO_ROTATE)

#if defined(DEMO_BUTTON)
// ��ť��ʾ����
void drawButtons()
{
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double x = winwidth/2.5;  
	double y = winheight/2-h; 
	double w = winwidth/5; // �ؼ����

	if (button(GenUIID(0), x, y, w, h, show_more_buttons ? "Show Less Buttons" : "Show More Buttons"))
		show_more_buttons = ! show_more_buttons;
	
	if( show_more_buttons ) {
		int k;
		for( k = 0; k<3; k++ ) {
			char name[128]; sprintf(name, "Button Array %d", k);
			// use GenUIID(k) to have different ID for multiple buttons by the same code
			button(GenUIID(k), x + w*1.2, y - k*h*2, w, h, name); 
		}

	}

	if( button(GenUIID(0), x, y-1.5*h, w, h, "Use Predefined Colors") )
	{	
		static int times = 0; 
		usePredefinedColors(++times);
	}

	if( button(GenUIID(0), x, y-3*h, w, h, "Random Button Colors") )
	{	
		char * c[] = {"Black","Dark Gray","Gray","Light Gray","White", "Cyan",
			"Brown", "Red", "Orange", "Yellow", "Green","Blue","Violet", "Magenta"};
		int N = sizeof(c)/sizeof(c[0]);
		static int times = 0; times++;
		setButtonColors (c[times%N], c[(times+1)%N], c[(times+2)%N], c[(times+3)%N], 1);
	}

	if( button(GenUIID(0), x, y-4.5*h, w, h, "Random EditBox Colors") )
	{	
		char * c[] = {"Black","Dark Gray","Gray","Light Gray","White", "Cyan",
			"Brown", "Red", "Orange", "Yellow", "Green","Blue","Violet", "Magenta"};
		int N = sizeof(c)/sizeof(c[0]);
		static int times = 0; times++;
		setTextBoxColors (c[times%N], c[(times+1)%N], c[(times+2)%N], c[(times+3)%N], 1);
	}

}
#endif // #if defined(DEMO_BUTTON)

#if defined(DEMO_EDITBOX)
// �ı��༭��ʾ����
void drawEditText()
{
	static char firstName[80] = "Xinguo";
	static char lastName[80] = "Liu";
	static char results[200] = "";
	static char memo[80]="Hello World! Edit me!";
	static char numstr[80] = "3.14159265";
	static char newnum[80] = "";
	double fH = GetFontHeight();
	double h = fH*2; // �ؼ��߶�
	double w = winwidth/4; // �ؼ����
	double x = winwidth/15;
	double y = winheight/2-h;

	textbox(GenUIID(0), winwidth / 10, winheight-h-h, w, h, memo, sizeof(memo));
	textbox(GenUIID(0), x, y, w, h, memo, sizeof(memo));

	SetPenColor("Brown"); 
	drawLabel(x-fH/2-TextStringWidth("��"), (y-=h*1.2)+fH*0.7, "��");
	if( textbox(GenUIID(0), x, y, w, h, firstName, sizeof(firstName)) )
		sprintf(results,"Text edit result is: %s+%s", firstName,lastName);

	SetPenColor("Brown"); 
	drawLabel(x-fH/2-TextStringWidth("��"), (y-=h*1.2)+fH*0.7, "��");
	if( textbox(GenUIID(0), x, y, w, h, lastName, sizeof(lastName)) )
		sprintf(results,"Text edit result is: %s+%s", firstName,lastName);

	SetPenColor("Gray"); 
	drawLabel(x, y-=fH*1.2, results);

	//y = winheight/2;
	if( textbox(GenUIID(0),x,y-=h*1.8,w,h,numstr,sizeof(numstr)) )
	{
		double value; sscanf(numstr,"%lf",&value);
		sprintf(newnum,"Represented value is: %.20f", value);
	}
	SetPenColor("Gray"); 
	drawLabel(x,y-=fH*1.2, newnum);
}
#endif // #if defined(DEMO_EDITBOX)

void display()
{
	// ����
	DisplayClear();

#if defined(DEMO_ROTATE)
	// ��ת��������
	drawRotateTriangle();
#endif
			
#if defined(DEMO_BUTTON)
	// ��ť
	drawButtons();
#endif

#if defined(DEMO_EDITBOX)
	// �༭�ı��ַ���
	drawEditText();
#endif

#if defined(DEMO_MENU)
	// ���ƺʹ���˵�
	drawMenu();
#endif
}
