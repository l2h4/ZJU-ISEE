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
extern double winwidth, winheight; //窗口大小 
int pointsize = 30; // 字体大小  
int font = 1; // 字体样式 
int pencolor = 1; //字体颜色 
int backgroundbt;
int bgcolor=1;
int hangjubt;
int firstline;
double hangju;
double hangjianju;
double ux, uy;
int enable_enter_auto = 1;  // 是否自动换行（默认自动换行）
int enable_state = 1;  
int HelpTXT = 0; //Help菜单内容 
static double xrm, yrm; //右键菜单位置 
static double menulength; //菜单总长度
static double boxl; //工具栏表头长度 
static double xinc, yinc; //button宽度、厚度缩进 
static int pensizebt=0; //字体大小选择按键 
static int pencolorbt=0; //字体颜色选择按键 
static int penfontbt = 0; //字体样式选择按键 
int showopen = 0; //open按钮解释
int showsave = 0; //save按钮解释
int showsize = 0; //size按钮解释
int showbg = 0; //backgroud按钮解释
int showlook = 0; //lookup按钮解释
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

// 用户的鼠标事件响应函数
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
		SetFont("宋体");
		SetPenColor("Blue");
		Drawchazhao();
	}else if(tihuanmodule1==1){
		SetPointSize(20);
		SetFont("宋体");
		SetPenColor("Blue");
		Drawtihuan1();
	}else if(tihuanmodule2==1){
		SetPointSize(20);
		SetFont("宋体");
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
		SetFont("宋体");
	}else if(font==2){
		SetFont("Default");
	}else if(font==3){
		SetFont("Courier");
	}
	else if(font==4){
		SetFont("黑体");
	} 
}

void Drawmenu()
{
	char * menuListFile[] = {"文件",  
		"打开   |  Ctrl-O", 
		"保存   |  Ctrl-S",           
		"退出"};

	char * menuListEdit[] = {"编辑",
		"全选   |  Ctrl-A",
		"剪切   |  Ctrl-X",
		"复制   |  Ctrl-C",
		"粘贴   |  Ctrl-V",
		"删除"}; 
	
	char * menuListLayout[] = {"格式",
		"字体大小",
		"字体颜色",
		"字体样式",
		"取消自动换行",
		"行距"};
	
	char * menuListHelp[] = {"帮助",
		"关于编辑器"};
	
	char * menuListLook[] = {"查看",
		"状态栏",
		"放大字体",
		"缩小字体",
		"查找",
		"替换"}; 
	
	int selectionF, selectionE, selectionL, selectionH, selectionK;
	
	//重新获取窗口大小 
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	
	 
	double x = 0;
	double y = winheight;
	double h = winheight*0.025; // 控件高度
	
	double w = winwidth/16; // 主菜单宽度
	
	double wlist = 1.8*w; //列表宽度
	
	double xindent = winheight/20; // 缩进
	
	menulength=x+4*w+winwidth/4;
	
	// menu bar
	drawMenuBar(x,y-h,5*w,h);
	
	// File 菜单
	selectionF = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, 
	sizeof(menuListFile)/sizeof(menuListFile[0]));
	if(selectionF==3){
		exit(0);
	}else if(selectionF==1){
		FileOpen();
	}else if(selectionF==2){
		FileSave();
	}
	
	//Edit 菜单 
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
	
	//Layout 菜单
	menuListLayout[4]= enable_enter_auto? "取消自动换行" : "自动换行";
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
	
	menuListLook[1]= enable_state? "关闭状态栏" : "状态栏";
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
	
	double h = winheight*0.025; // 控件高度
	double w = winwidth/12; //控件宽度 
	boxl=w; 
	
	drawBox(menulength, winheight-h, w, h, 0, "工具栏", 'M', "Black");
	
	double x = menulength+w;
	double y = winheight;
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
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
		DrawTextString("未打开文件或打开文件失败，fp==NULL(双击返回主界面)");
	}
	else if(fileTXT2)
	{
		MovePen(x,y);
		DrawTextString("未保存文件或保存文件失败,fp==NULL(双击返回主界面)");
	}
	else
	{
	MovePen(x,y);
    //DrawTextString("本编辑器由：cbs完成(cbs即我们团队蔡馨毅、毕研成、谌梓轩的姓氏首字母组合)。");
	MovePen(x,y-yin);
	DrawTextString("功能包括："); 
	MovePen(x, y-yin*2);
	DrawTextString("1. 打开(Ctrl+O)、保存文件(Ctrl+S)，关闭程序；");
	MovePen(x, y-yin*3);
	DrawTextString("2. 复制(Ctrl+C)、粘贴(Ctrl+V)、全选(Ctrl+A)、剪切(Ctrl+X)、删除、查找、替换、拖动选取；");
	MovePen(x, y-yin*4);
	DrawTextString("3. 自动换行、取消自动换行；");
	MovePen(x, y-yin*5);
	DrawTextString("4. 通过键盘左、右键移动光标，通过鼠标单击移动光标；"); 
	MovePen(x, y-yin*6);
	DrawTextString("5. 修改字体大小、颜色、样式，放大、缩小字体大小，修改背景颜色，修改行间距；");
	MovePen(x, y-yin*7);
	DrawTextString("6. 在最下方状态栏显示当前行、列数与总字节数；");
	MovePen(x, y-yin*8);
	DrawTextString("7. 文本竖直方向滚动");
	MovePen(x, y-yin*9);
	DrawTextString("注意事项；");
	MovePen(x, y-yin*10);
	DrawTextString("1. 请不要在程序界面按下Ctrl键后在其他界面抬起，或在其他界面按下Ctrl键后在程序界面抬起；");
	MovePen(x, y-yin*11);
	DrawTextString("建议不要一直按住Ctrl键，应及时松开，否则若发生上一行所描述的情况，将导致对control是否按下的检测失灵；");
	MovePen(x, y-yin*12);
	DrawTextString("若出现此现象，只需在程序界面按下Ctrl键后在其他界面抬起即可纠正；");
	MovePen(x, y-yin*13);
	DrawTextString("2. 拖动选取时，抬起鼠标后方可显示选取部分；");
	MovePen(x, y-yin*14);
	SetPenColor("Red"); 
	DrawTextString("3. 不支持繁体字的输入，若发现文本突然消失，可能是该原因导致;");
	MovePen(x, y-yin*15);
	DrawTextString("4. 鼠标滚动实现文本竖直方向滚动。");
	MovePen(x, y-yin*16);
	DrawTextString("（双击进入主界面）");
    }
}

void Drawchazhao()
{
	char state[200]; 
	sprintf(state, "请输入查找内容:%s", chazhaoneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("     按下enter开始从当前位置往后查找最近的查找内容，按下backspace重新输入");
}

void Drawtihuan1()
{
	char state[200]; 
	sprintf(state, "请输入被替换内容:%s", chazhaoneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("               按下enter确认被替换内容，按下backspace重新输入");
}

void Drawtihuan2()
{
	char state[200]; 
	sprintf(state, "请输入替换内容:%s", tihuanneirong);
	drawBox(winwidth/3, winheight/2, winwidth/3, GetFontHeight(), 0, state, 'L', "Blue"); 
	MovePen(winwidth/5,winheight/3);
	DrawTextString("        按下enter将所有被替换内容替换为替换内容，按下backspace重新输入");
}

void DrawExplain()
{
	
	double h = winheight*0.025; // 控件高度
	double w = winwidth/12; //控件宽度 
	
	SetPenColor("Yellow");
	if(showopen==1){
		drawBox(ux, uy-h, w, h, 1, "打开", 'M', "Black");
	}else if(showsize==1){
		drawBox(ux, uy-h, w, h, 1, "字体大小", 'M', "Black");
	}else if(showsave==1){
		drawBox(ux, uy-h, w, h, 1, "保存", 'M', "Black");
	}else if(showbg==1){
		drawBox(ux, uy-h, w, h, 1, "背景色", 'M', "Black");
	}else if(showlook==1){
		drawBox(ux, uy-h, w, h, 1, "查找", 'M', "Black");
	}
	SetPenColor("Black");
	 
}

void pensizebutton()
{
	double x = winwidth/2-winwidth/16;
	double y = winheight*0.975;
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
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
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
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
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
	double h = winheight*0.025;
	hangjubt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "小行距")){
		hangjubt=0;
		hangju=0;
	}
	
	if(button(GenUIID(0), x-2*wb, y-2*h, wb, hb, "中行距")){
		hangjubt=0;
		hangju=GetFontHeight()*0.2;
	}
	
	if(button(GenUIID(0), x-2*wb, y-3*h, wb, hb, "大行距")){
		hangjubt=0;
		hangju=GetFontHeight()*0.5;
	}
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "超大行距")){
		hangjubt=0;
		hangju=GetFontHeight()*1.0;
	}
}
void penfontbutton()
{
	double x = winwidth/2+winwidth/16;
	double y = winheight*0.975;
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
	double h = winheight*0.025;
	penfontbt=1;
	
	if(button(GenUIID(0), x-2*wb, y-h, wb, hb, "宋体")){
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
	
	if(button(GenUIID(0), x-2*wb, y-4*h, wb, hb, "黑体")){
		penfontbt=0;
		font=4;
	}
}

void backgroundbutton()
{
	double x = winwidth/2+winwidth/16*2;
	double y = winheight*0.975;
	double hb = winheight*0.025; // 控件高度
	double wb = winwidth/16; // 按键宽度 
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
	int rownum = 1; //行数目
    int linenum = 1; //列数目 
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
	sprintf(state, "行：%d        列：%d        总字节数：%d", rownum, linenum, total);
	
	drawBox(0, 0, w, h, 0, state, 'L', "Blue");
}






