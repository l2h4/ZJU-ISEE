#include "imgui.h"
#include "graphics.h"
#include "genlib.h"
#include "boolean.h"
#include "exception.h"
#include "gcalloc.h"
#include "linkedlist.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "extgraph.h"

extern int current, total, max, anxiacurrent, taiqicurrent;
extern char *results;
extern double winwidth, winheight; //���ڴ�С 
int pointsize = 30; // �����С  
int font = 1; // ������ʽ 
int pencolor = 1; //������ɫ 
int backgroundbt;
int bgcolor=1;
int hangjubt;
int firstline;
double hangju;
double hangjianju;
double ux, uy;
int enable_enter_auto = 1;  // �Ƿ��Զ����У�Ĭ���Զ����У�
int enable_state = 1;  
int HelpTXT = 0; //Help�˵����� 
static double xrm, yrm; //�Ҽ��˵�λ�� 
static double menulength; //�˵��ܳ���
static double boxl; //��������ͷ���� 
static double xinc, yinc; //button��ȡ�������� 
static int pensizebt=0; //�����Сѡ�񰴼� 
static int pencolorbt=0; //������ɫѡ�񰴼� 
static int penfontbt = 0; //������ʽѡ�񰴼� 
int showopen = 0; //open��ť����
int showsave = 0; //save��ť����
int showsize = 0; //size��ť����
int showbg = 0; //backgroud��ť����
int showlook = 0; //lookup��ť����
extern char *fuzhineirong;
int chazhaomodule; 
int tihuanmodule1, tihuanmodule2;
extern char chazhaoneirong[200];
extern int chazhaototal;
extern int tihuantotal;
extern char tihuanneirong[200];
extern int fileTXT1,fileTXT2;

void Drawmenu();
void menudisplay();
void DrawToolbox();
void DrawHelptxt();
void DrawExplain();
void pensizebutton();
void pencolorbutton();

// �û�������¼���Ӧ����
void menuMouseEventProcess(int x, int y, int button, int event)
{
	static t;
	uiGetMouse(x,y,button,event);
	ux = ScaleXInches(x);
	uy = ScaleYInches(y);
	int i = 0, j = 1, k, m = 0, previous, hanzigeshu = 0;
    static double Xanxiazuobiao, Yanxiazuobiao, Xtaiqizuobiao, Ytaiqizuobiao;
	if(button == LEFT_BUTTON && event == BUTTON_DOWN && !HelpTXT && !chazhaomodule && !tihuanmodule1 && !tihuanmodule2)
	{
		if(uy<winheight*0.85)
		{
			t=1;
		Xanxiazuobiao = ScaleXInches(x);
	    Yanxiazuobiao = ScaleYInches(y)-firstline*(GetFontHeight()+hangju);
		SetEraseMode(1);
    	DrawLine(0, GetFontHeight());
    	SetEraseMode(0);
		while(i < total-1 && winheight*0.85 - j * (GetFontHeight()+hangju) > Yanxiazuobiao)
		{
			if(results[i]=='\n')
				j++;
			i++;
		}
		if(i != total-1)
		{
			while(TextStringWidth(results + i) - TextStringWidth(results + i + m) + (TextStringWidth(results + i + m) - TextStringWidth(results + i + m + 1)) / 2 < Xanxiazuobiao && results[i + m]!='\n' && i + m < total)
				m++;
			previous = i + m;
			while(!((int)(results[previous]) >= 0 && (int)(results[previous]) < 128))
			{
				hanzigeshu++;
				previous++;
			}
			if(hanzigeshu % 2)
			{
                current = i + m + 1;
		    }
			else 
			{
			    current = i + m;
			}
			anxiacurrent = current;
			taiqicurrent = anxiacurrent;
		}
		else
		{
			i = 0; k = 1;
			while(k < j)
		    {
			if(results[i] == '\n')
				k++;
			    i++;
		    }
            while(TextStringWidth(results + i) - TextStringWidth(results + i + m) + (TextStringWidth(results + i + m) - TextStringWidth(results + i + m + 1)) / 2 < Xanxiazuobiao && results[i + m]!='\n' && i + m < total)
				m++;
			previous = i + m;
			while(!((int)(results[previous]) >= 0 && (int)(results[previous])<128))
			{
				hanzigeshu++;
				previous++;
			}
			if(hanzigeshu % 2)
			{
                current = i + m + 1;
		    }
			else 
			{
			    current = i + m;
			}
			anxiacurrent = current;
			taiqicurrent = anxiacurrent;
		}
	    }
	    else
	    {
	    	t=0;
	    	huajuxing();
		}
	}
	if(button == LEFT_BUTTON && event == BUTTON_UP && !HelpTXT && !chazhaomodule && !tihuanmodule1 && !tihuanmodule2)
	{
		if(t==1)
		{
		Xtaiqizuobiao = ScaleXInches(x);
		Ytaiqizuobiao = ScaleYInches(y)-firstline*(GetFontHeight()+hangju);;
		SetEraseMode(1);
    	DrawLine(0, GetFontHeight());
    	SetEraseMode(0);
		while(i < total-1 && winheight * 0.85 - j * (GetFontHeight()+hangju) > Ytaiqizuobiao)
		{
			if(results[i]=='\n')
				j++;
			i++;
		}
		if(i != total-1)
		{
            while(TextStringWidth(results + i) - TextStringWidth(results + i + m) + (TextStringWidth(results + i + m) - TextStringWidth(results + i + m + 1)) / 2 < Xtaiqizuobiao && results[i + m]!='\n' && i + m < total)
				m++;
			previous = i + m;
			while(!((int)(results[previous]) >= 0 && (int)(results[previous]) < 128))
			{
				hanzigeshu++;
				previous++;
			}
			if(hanzigeshu % 2)
			{
                current = i + m + 1;
		    }
			else 
			{
			    current = i + m;
			}
			taiqicurrent = current;	
		}
		else
		{
			i = 0, k = 1;
			while(k < j)
		    {
			if(results[i] == '\n')
				k++;
			i++;
		    }
			while(TextStringWidth(results + i) - TextStringWidth(results + i + m) + (TextStringWidth(results + i + m) - TextStringWidth(results + i + m + 1)) / 2 < Xtaiqizuobiao && results[i + m]!='\n' && i + m < total)
				m++; 
			previous = i + m;
			while(!((int)(results[previous]) >= 0 && (int)(results[previous]) < 128))
			{
				hanzigeshu++;
				previous++;
			}
			if(hanzigeshu % 2)
			{
                current = i + m + 1;
		    }
			else 
			{
			    current = i + m;
			}
			taiqicurrent = current;
		}
	    }
		else
		{
			huajuxing();
		}	
	}
	
	if(button == MIDDLE_BUTTON && event == ROLL_UP && !HelpTXT && !chazhaomodule && !tihuanmodule1 && !tihuanmodule2)
	{
		if(firstline>0)firstline--;
	}
	
	if(button == MIDDLE_BUTTON && event == ROLL_DOWN && !HelpTXT && !chazhaomodule && !tihuanmodule1 && !tihuanmodule2)
	{
		int i = 0, line = 1;
	    for(i = 0; i < total; i++)
	    {
		    if(results[i] == '\n')
		        line++;
	    }
	    if(line*(GetFontHeight()+hangju)>winheight*0.85&&(line-firstline)*(GetFontHeight()+hangju)>winheight*0.85)firstline++;
	}
	
	if(button == LEFT_BUTTON && event == BUTTON_DOUBLECLICK)
	{
		HelpTXT = 0;
		fileTXT1 = 0;
		fileTXT2 = 0;
    }
    
    
    if(button == MOUSEMOVE && event == MOUSEMOVE)
    {
    	    if(ux>menulength+boxl && ux<menulength+boxl+xinc && uy<winheight && uy>winheight-yinc){
				showopen = 1;
				showsize = 0;
				showbg = 0;
				showsave = 0;
				showlook = 0;
			}else if(ux>menulength+xinc+boxl && ux<menulength+2*xinc+boxl && uy<winheight && uy>winheight-yinc){
				showopen = 0;
				showsize = 0;
				showbg = 0;
				showsave = 1;
				showlook = 0;
			}else if(ux>menulength+2*xinc+boxl && ux<menulength+3*xinc+boxl && uy<winheight && uy>winheight-yinc){
				showopen = 0;
				showsize = 1;
				showbg = 0;
				showsave = 0;
				showlook = 0;	
			}else if(ux>menulength+3*xinc+boxl && ux<menulength+4*xinc+boxl && uy<winheight && uy>winheight-yinc){
				showopen = 0;
				showsize = 0;
				showbg = 1;
				showsave = 0;
				showlook = 0;
			}else if(ux>menulength+4*xinc+boxl && ux<menulength+5*xinc+boxl && uy<winheight && uy>winheight-yinc){
				showopen = 0;
				showsize = 0;
				showbg = 0;
				showsave = 0;
				showlook = 1;
			}else{
				showopen = 0;
				showsize = 0;
				showbg = 0;
				showsave = 0;
				showlook = 0;
			}
	}
	huajuxing();
}

void menudisplay()
{
	if(HelpTXT==0&&chazhaomodule==0&&tihuanmodule1==0&&tihuanmodule2==0){
		SetPointSize(20);
		SetPenColor("Black");
		SetFont("Times");
		DrawToolbox();
		Drawmenu();
		DrawExplain();
		
		if(pensizebt==1){
			pensizebutton();
		}
		
		if(pencolorbt==1){
			pencolorbutton();
		}
		
		if(penfontbt==1){
			penfontbutton();
		}
		
		if(enable_state==1){
			statusbar();
		}
		if(backgroundbt==1)
		{
			backgroundbutton();
		}
		if(hangjubt==1)
		{
			hangjubutton();
		}
	}else if(HelpTXT==1){
		SetPointSize(20);
		SetFont("Times");
		SetPenColor("Blue");
		DrawHelptxt();
	}else if(chazhaomodule==1){
		SetPointSize(20);
		SetFont("����");
		SetPenColor("Blue");
		Drawchazhao();
	}else if(tihuanmodule1==1){
		SetPointSize(20);
		SetFont("����");
		SetPenColor("Blue");
		Drawtihuan1();
	}else if(tihuanmodule2==1){
		SetPointSize(20);
		SetFont("����");
		SetPenColor("Blue");
		Drawtihuan2();
	}
    
	SetPointSize(pointsize);
	
	if(pencolor==1){
		SetPenColor("Black");
	}else if(pencolor==2){
		SetPenColor("Red");
	}else if(pencolor==3){
		SetPenColor("Yellow");
	}else if(pencolor==4){
		SetPenColor("Green");
	}else if(pencolor==5){
		SetPenColor("Blue");
	}
	
	if(font==1){
		SetFont("����");
	}else if(font==2){
		SetFont("Default");
	}else if(font==3){
		SetFont("Courier");
	}
	else if(font==4){
		SetFont("����");
	} 
}

void Drawmenu()
{
	char * menuListFile[] = {"�ļ�",  
		"��   |  Ctrl-O", 
		"����   |  Ctrl-S",           
		"�˳�"};

	char * menuListEdit[] = {"�༭",
		"ȫѡ   |  Ctrl-A",
		"����   |  Ctrl-X",
		"����   |  Ctrl-C",
		"ճ��   |  Ctrl-V",
		"ɾ��"}; 
	
	char * menuListLayout[] = {"��ʽ",
		"�����С",
		"������ɫ",
		"������ʽ",
		"ȡ���Զ�����",
		"�о�"};
	
	char * menuListHelp[] = {"����",
		"���ڱ༭��"};
	
	char * menuListLook[] = {"�鿴",
		"״̬��",
		"�Ŵ�����",
		"��С����",
		"����",
		"�滻"}; 
	
	int selectionF, selectionE, selectionL, selectionH, selectionK;
	
	//���»�ȡ���ڴ�С 
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	
	 
	double x = 0;
	double y = winheight;
	double h = winheight*0.025; // �ؼ��߶�
	
	double w = winwidth/16; // ���˵����
	
	double wlist = 1.8*w; //�б���
	
	double xindent = winheight/20; // ����
	
	menulength=x+4*w+winwidth/4;
	
	// menu bar
	drawMenuBar(x,y-h,5*w,h);
	
	// File �˵�
	selectionF = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, 
	sizeof(menuListFile)/sizeof(menuListFile[0]));
	if(selectionF==3){
		exit(0);
	}else if(selectionF==1){
		FileOpen();
	}else if(selectionF==2){
		FileSave();
	}
	
	//Edit �˵� 
	selectionE = menuList(GenUIID(0), x+w, y-h, w, wlist, h, menuListEdit, 
	sizeof(menuListEdit)/sizeof(menuListEdit[0]));
	if(selectionE==1){
        quanxuan();
	}else if(selectionE==2){
		jianqie();
	}else if(selectionE==3){
		fuzhi();
	}else if(selectionE==4){
		zhantie(fuzhineirong);
	}else if(selectionE==5){
		shanchu(anxiacurrent,taiqicurrent);
	}
	
	//Layout �˵�
	menuListLayout[4]= enable_enter_auto? "ȡ���Զ�����" : "�Զ�����";
	selectionL = menuList(GenUIID(0), x+2*w, y-h, w, wlist, h, menuListLayout, 
	sizeof(menuListLayout)/sizeof(menuListLayout[0]));
	if(selectionL==1){
		pensizebutton();
	}else if(selectionL==4){
		enable_enter_auto=!enable_enter_auto;
		
	}else if(selectionL==2){
		pencolorbutton();
	}else if(selectionL==3){
		penfontbutton();
	}else if(selectionL==5){
		hangjubutton();
	}
	
	menuListLook[1]= enable_state? "�ر�״̬��" : "״̬��";
	selectionK = menuList(GenUIID(0), x+3*w, y-h, w, wlist, h, menuListLook, 
	sizeof(menuListLook)/sizeof(menuListLook[0]));
	if(selectionK==1){
		enable_state=!enable_state;
	}else if(selectionK==2){
		if(pointsize<50){
			pointsize=pointsize+10;
		}
	}else if(selectionK==3){
		if(pointsize>10){
			pointsize=pointsize-10;
		}
	}else if(selectionK==4){
		chazhaomodule=1;
		DisplayClear();
		chazhaototal = 0;
		chazhaoneirong[0] = 0;
		Drawchazhao();
	}else if(selectionK==5){
		tihuanmodule1=1;
		DisplayClear();
		chazhaototal = 0;
		chazhaoneirong[0] = 0;
		tihuantotal = 0;
		tihuanneirong[0] = 0;
		Drawchazhao();
	}
	
	selectionH = menuList(GenUIID(0), x+4*w, y-h, w, wlist, h, menuListHelp, 
	sizeof(menuListHelp)/sizeof(menuListHelp[0]));
	if(selectionH==1){
		HelpTXT=1;
		DisplayClear();
		DrawHelptxt();
	}
}

void DrawToolbox()
{
	SetPenSize(2);
	SetPenColor("Black");
	
	double h = winheight*0.025; // �ؼ��߶�
	double w = winwidth/12; //�ؼ���� 
	boxl=w; 
	
	drawBox(menulength, winheight-h, w, h, 0, "������", 'M', "Black");
	
	double x = menulength+w;
	double y = winheight;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	xinc=wb;
	yinc=hb;
		
	if(button(GenUIID(0), x, y-h, wb, hb, "")){
		FileOpen();
	}
	MovePen(x+wb/2+h/2, y-h/2);
	DrawArc(h/2, 0, 360);
	
	if(button(GenUIID(0), x+wb, y-h, wb, hb, "")){
		FileSave();
	}
	drawRectangle(x+wb+wb/2-h/2, y-h, h, h, 1);
	
	if(button(GenUIID(0), x+2*wb, y-h, wb, hb, "A")){
		pensizebutton();
	}
	
	if(button(GenUIID(0), x+3*wb, y-h, wb, hb, "")){
		backgroundbutton();
	}
	drawRectangle(x+wb+wb+wb+wb/2-h/2, y-h, h, h, 0);
	MovePen(x+wb+wb+wb+wb/2-h/2, y-h);
	DrawLine(h, h);
	
	if(button(GenUIID(0), x+4*wb, y-h, wb, hb, "F")){
		chazhaomodule=1;
		DisplayClear();
		chazhaototal=0;
		chazhaoneirong[0] = 0;
		Drawchazhao();
	}
}

void DrawHelptxt()
{
	double x=winwidth/16;
	double y=winheight-winheight/16;
	double yin = winheight/20;
	
	drawRectangle(0, 0, winwidth, winheight, 0);
	if(fileTXT1)
	{
		MovePen(x,y);
		DrawTextString("δ���ļ�����ļ�ʧ�ܣ�fp==NULL(˫������������)");
	}
	else if(fileTXT2)
	{
		MovePen(x,y);
		DrawTextString("δ�����ļ��򱣴��ļ�ʧ��,fp==NULL(˫������������)");
	}
	else
	{
	MovePen(x,y);
    //DrawTextString("���༭���ɣ�cbs���(cbs�������ŶӲ�ܰ�㡢���гɡ�����������������ĸ���)��");
	MovePen(x,y-yin);
	DrawTextString("���ܰ�����"); 
	MovePen(x, y-yin*2);
	DrawTextString("1. ��(Ctrl+O)�������ļ�(Ctrl+S)���رճ���");
	MovePen(x, y-yin*3);
	DrawTextString("2. ����(Ctrl+C)��ճ��(Ctrl+V)��ȫѡ(Ctrl+A)������(Ctrl+X)��ɾ�������ҡ��滻���϶�ѡȡ��");
	MovePen(x, y-yin*4);
	DrawTextString("3. �Զ����С�ȡ���Զ����У�");
	MovePen(x, y-yin*5);
	DrawTextString("4. ͨ���������Ҽ��ƶ���꣬ͨ����굥���ƶ���ꣻ"); 
	MovePen(x, y-yin*6);
	DrawTextString("5. �޸������С����ɫ����ʽ���Ŵ���С�����С���޸ı�����ɫ���޸��м�ࣻ");
	MovePen(x, y-yin*7);
	DrawTextString("6. �����·�״̬����ʾ��ǰ�С����������ֽ�����");
	MovePen(x, y-yin*8);
	DrawTextString("7. �ı���ֱ�������");
	MovePen(x, y-yin*9);
	DrawTextString("ע�����");
	MovePen(x, y-yin*10);
	DrawTextString("1. �벻Ҫ�ڳ�����水��Ctrl��������������̧�𣬻����������水��Ctrl�����ڳ������̧��");
	MovePen(x, y-yin*11);
	DrawTextString("���鲻Ҫһֱ��סCtrl����Ӧ��ʱ�ɿ���������������һ��������������������¶�control�Ƿ��µļ��ʧ�飻");
	MovePen(x, y-yin*12);
	DrawTextString("�����ִ�����ֻ���ڳ�����水��Ctrl��������������̧�𼴿ɾ�����");
	MovePen(x, y-yin*13);
	DrawTextString("2. �϶�ѡȡʱ��̧�����󷽿���ʾѡȡ���֣�");
	MovePen(x, y-yin*14);
	SetPenColor("Red"); 
	DrawTextString("3. ��֧�ַ����ֵ����룬�������ı�ͻȻ��ʧ�������Ǹ�ԭ����;");
	MovePen(x, y-yin*15);
	DrawTextString("4. ������ʵ���ı���ֱ���������");
	MovePen(x, y-yin*16);
	DrawTextString("��˫�����������棩");
    }
}

void Drawchazhao()
{
	char state[200]; 
	sprintf(state, "�������������:%s", chazhaoneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("     ����enter��ʼ�ӵ�ǰλ�������������Ĳ������ݣ�����backspace��������");
}

void Drawtihuan1()
{
	char state[200]; 
	sprintf(state, "�����뱻�滻����:%s", chazhaoneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("               ����enterȷ�ϱ��滻���ݣ�����backspace��������");
}

void Drawtihuan2()
{
	char state[200]; 
	sprintf(state, "�������滻����:%s", tihuanneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("        ����enter�����б��滻�����滻Ϊ�滻���ݣ�����backspace��������");
}

void DrawExplain()
{
	
	double h = winheight*0.025; // �ؼ��߶�
	double w = winwidth/12; //�ؼ���� 
	
	SetPenColor("Yellow");
	if(showopen==1){
		drawBox(ux, uy-h, w, h, 1, "��", 'M', "Black");
	}else if(showsize==1){
		drawBox(ux, uy-h, w, h, 1, "�����С", 'M', "Black");
	}else if(showsave==1){
		drawBox(ux, uy-h, w, h, 1, "����", 'M', "Black");
	}else if(showbg==1){
		drawBox(ux, uy-h, w, h, 1, "����ɫ", 'M', "Black");
	}else if(showlook==1){
		drawBox(ux, uy-h, w, h, 1, "����", 'M', "Black");
	}
	SetPenColor("Black");
	 
}

void pensizebutton()
{
	double x = winwidth/2-winwidth/16;
	double y = winheight*0.975;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	double h = winheight*0.025;
	pensizebt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "1")){
		pensizebt=0;
		pointsize=10;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "2")){
		pensizebt=0;
		pointsize=20;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "3")){
		pensizebt=0;
		pointsize=30;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "4")){
		pensizebt=0;
		pointsize=40;
	}
	
	if(button(GenUIID(0), x-2*wb, y-5*h, wb, hb, "5")){
		pensizebt=0;
		pointsize=50;
	}
}

void pencolorbutton()
{
	double x = winwidth/2;
	double y = winheight*0.975;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	double h = winheight*0.025;
	pencolorbt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "Black")){
		pencolorbt=0;
		pencolor=1;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "Red")){
		pencolorbt=0;
		pencolor=2;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "Yellow")){
		pencolorbt=0;
		pencolor=3;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "Green")){
		pencolorbt=0;
		pencolor=4;
	}
	
	if(button(GenUIID(0), x-2*wb, y-5*h, wb, hb, "Blue")){
		pencolorbt=0;
		pencolor=5;
	}
}

void hangjubutton()
{
	double x = winwidth/2+winwidth/16*3;
	double y = winheight*0.975;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	double h = winheight*0.025;
	hangjubt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "С�о�")){
		hangjubt=0;
		hangju=0;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "���о�")){
		hangjubt=0;
		hangju=GetFontHeight()*0.2;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "���о�")){
		hangjubt=0;
		hangju=GetFontHeight()*0.5;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "�����о�")){
		hangjubt=0;
		hangju=GetFontHeight()*1.0;
	}
}
void penfontbutton()
{
	double x = winwidth/2+winwidth/16;
	double y = winheight*0.975;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	double h = winheight*0.025;
	penfontbt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "����")){
		penfontbt=0;
		font=1;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "Default")){
		penfontbt=0;
		font=2;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "Courier")){
		penfontbt=0;
		font=3;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "����")){
		penfontbt=0;
		font=4;
	}
}

void backgroundbutton()
{
	double x = winwidth/2+winwidth/16*2;
	double y = winheight*0.975;
	double hb = winheight*0.025; // �ؼ��߶�
	double wb = winwidth/16; // ������� 
	double h = winheight*0.025;
	backgroundbt=1;
	SetPointSize(15);
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "White")){
		backgroundbt=0;
		bgcolor=1;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "LightGray")){
		backgroundbt=0;
		bgcolor=2;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "Gray")){
		backgroundbt=0;
		bgcolor=3;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "DarkGray")){
		backgroundbt=0;
		bgcolor=4;
	}
	SetPointSize(pointsize);
}

void statusbar()
{
	int rownum = 1; //����Ŀ
    int linenum = 1; //����Ŀ 
	char state[100];
	double h = winheight*0.025;
	double w = winwidth; 
	int i;
	for(i=0;i<current;i++)
	{
		if(results[i]=='\n')rownum++;
	}
	i=0;
	if(total)
	while(1)
	{
		if(current-i-1<0||results[current-i-1]=='\n')break;
		else if((int)results[current-i-1]>0&&(int)results[current-i-1]<128)i++;
		else i+=2;
		linenum++;
	}
	sprintf(state, "�У�%d        �У�%d        ���ֽ�����%d", rownum, linenum, total);
	
	drawBox(0, 0, w, h, 0, state, 'L', "Blue");
}






