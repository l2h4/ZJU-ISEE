#include <windows.h>
#include <winuser.h>
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
#include <math.h>
#include <strlib.h>

double winwidth, winheight;
int current, total, max = 32, anxiacurrent, taiqicurrent, fileTXT1, fileTXT2;
char *results;
extern void menudisplay();
extern int tihuanmodule1, tihuanmodule2, chazhaomodule, HelpTXT, enable_enter_auto;
FILE *fp;
char filename[100];
extern int pointsize; // 字体大小  
extern int font; // 字体样式 
extern int pencolor; //字体颜色 
extern int bgcolor;
extern char *fuzhineirong;
extern double hangju;
extern int firstline;

void display()
{
	int i = 0, j = -1, line = 1, t, k = 0;
	if(results[0]&&!HelpTXT&&!chazhaomodule&&!tihuanmodule1&&!tihuanmodule2)
	{
		for(t = 0; t < total; t++)
	    {
		    if(!((int)results[t] >= 0 && (int)results[t] < 128))k++;
	    }
	    if(k % 2)return;
        p:
	    while(i != total - 1 && results[i] != '\n')
		    i++;
	    if(i == total - 1)
	    {
	        if(TextStringWidth(results + j + 1) > winwidth && enable_enter_auto)
	        {
		        if((int)results[total - 1] >= 0 && (int)results[total - 1] < 128)
		        {
		        	results[total + 1] = 0;
                    results[total] = results[total - 1];
		            results[total - 1] = '\n';
					if(current == total)
					    current++;
                    total++;
		            if(total >= max - 2)
	                {
		            max += 32;
		            results = (char *)realloc(results, max);
	                }
		            display();
                    return;
	            }
	            else
	            {
		        	results[total + 1] = 0;
                    results[total] = results[total - 1];
                    results[total - 1] = results[total - 2];
		            results[total - 2] = '\n';
					if(current == total)
					    current++;
		            total++;
		            if(total >= max - 2)
	                {
		                max += 32;
		                results = (char *)realloc(results, max);
	                }
		            display();
                    return;
		        }
	        }
	        else
	        {
	        	if(line > firstline)
	        	{
	            MovePen(0, winheight*0.85 - (line-firstline) * (GetFontHeight()+hangju));
	            DrawTextString(results + j + 1);
	            }
            }
	    }
	    else
	    {
	        char *temp = (char *)calloc((i - j), sizeof(char));
	        for(t = 1; t < i - j; t++)
	        {
	        	temp[t - 1] = results[j + t];
	        }
			temp[i - j - 1] = 0;
	        if(TextStringWidth(temp) > winwidth && enable_enter_auto)
	        {
		        if((int)results[i - 1] >= 0 && (int)results[i - 1] < 128)
		        {
		        	results[i] = results[i - 1];
		            results[i - 1] = '\n';
					if(current == i)
					    current++;
	                free(temp);
		            display();
                    return;
                }
                else
                {
		        	results[i] = results[i - 1];
		        	results[i - 1] = results[i - 2];
		        	results[i - 2] = '\n';
					if(current == i)
					    current++;
	                free(temp);
		            display();
                    return;
				}
	        }
	        else
	        {
	        	if(line > firstline)
	        	{
	            MovePen(0, winheight*0.85 - (line-firstline) * (GetFontHeight()+hangju));
	            DrawTextString(temp);
	            }
	            free(temp);
	            line++; j = i; i++; goto p;
            }
        }
    }
}

void huajuxing()
{
	double qishiweizhiX, jieshuweizhiX, qishiweizhiY, jieshuweizhiY;
	int i = 1, line = 1, t;
	DisplayClear();
	if(bgcolor==1)SetPenColor("White");
	else if(bgcolor==2)SetPenColor("Light Gray");
	else if(bgcolor==3)SetPenColor("Gray");
	else if(bgcolor==4)SetPenColor("Dark Gray");
    drawRectangle(0.0,0.0,winwidth,winheight,1);
	if(anxiacurrent==taiqicurrent||HelpTXT||chazhaomodule||tihuanmodule1||tihuanmodule2)goto p;
    if(!anxiacurrent)
	    i = 0;
	else
	    while(i < anxiacurrent && results[anxiacurrent - i] != '\n')
		    i++;
	for(t = 0; t < anxiacurrent; t++)
	{
		if(results[t] == '\n')
		    line++;
	}
	qishiweizhiX=TextStringWidth(results + anxiacurrent - i) - TextStringWidth(results + anxiacurrent);
	qishiweizhiY=winheight * 0.85 - (line-firstline) * (GetFontHeight()+hangju);
	i = 1; line = 1; t=0;
	if(!taiqicurrent)
	    i = 0;
	else
	    while(i < taiqicurrent && results[taiqicurrent - i] != '\n')
		    i++;
	for(t = 0; t <taiqicurrent; t++)
	{
		if(results[t] == '\n')
		    line++;
	}
	jieshuweizhiX=TextStringWidth(results + taiqicurrent - i) - TextStringWidth(results + taiqicurrent);
	jieshuweizhiY=winheight * 0.85 - (line-firstline) * (GetFontHeight()+hangju);
	if(pencolor==2)
		SetPenColor("Blue");
	else
		SetPenColor("Red");
	if(qishiweizhiY==jieshuweizhiY)
	{
		if(jieshuweizhiX>qishiweizhiX)
		if(qishiweizhiY<winheight*0.85)drawRectangle(qishiweizhiX,qishiweizhiY,TextStringWidth(results+anxiacurrent)-TextStringWidth(results+taiqicurrent),(GetFontHeight()+hangju),1);
		else
		if(qishiweizhiY<winheight*0.85)drawRectangle(jieshuweizhiX,qishiweizhiY,TextStringWidth(results+taiqicurrent)-TextStringWidth(results+anxiacurrent),(GetFontHeight()+hangju),1);
	}
	else 
	if(qishiweizhiY>jieshuweizhiY)
	{
		if(fabs(qishiweizhiY-jieshuweizhiY-GetFontHeight())<0.5*(GetFontHeight()+hangju))
		{
			if(qishiweizhiY<winheight*0.85)drawRectangle(qishiweizhiX,qishiweizhiY,winwidth-qishiweizhiX,(GetFontHeight()+hangju),1);
			if(jieshuweizhiY<winheight*0.85)drawRectangle(0,jieshuweizhiY,jieshuweizhiX,(GetFontHeight()+hangju),1);
		}
		else
		{
			if(qishiweizhiY<winheight*0.85)drawRectangle(qishiweizhiX,qishiweizhiY,winwidth-qishiweizhiX,(GetFontHeight()+hangju),1);
			if(jieshuweizhiY+(GetFontHeight()+hangju)<winheight*0.85)drawRectangle(0,jieshuweizhiY+(GetFontHeight()+hangju),winwidth,qishiweizhiY-jieshuweizhiY-(GetFontHeight()+hangju),1);
			if(jieshuweizhiY<winheight*0.85)drawRectangle(0,jieshuweizhiY,jieshuweizhiX,(GetFontHeight()+hangju),1);
		}
	}
	else
	{
		if(fabs(-qishiweizhiY+jieshuweizhiY-(GetFontHeight()+hangju))<0.5*(GetFontHeight()+hangju))
		{
			if(jieshuweizhiY<winheight*0.85)drawRectangle(jieshuweizhiX,jieshuweizhiY,winwidth-jieshuweizhiX,(GetFontHeight()+hangju),1);
			if(qishiweizhiY<winheight*0.85)drawRectangle(0,qishiweizhiY,qishiweizhiX,(GetFontHeight()+hangju),1);
		}
		else
		{
			if(jieshuweizhiY<winheight*0.85)drawRectangle(jieshuweizhiX,jieshuweizhiY,winwidth-jieshuweizhiX,(GetFontHeight()+hangju),1);
			if(qishiweizhiY+(GetFontHeight()+hangju)<winheight*0.85)drawRectangle(0,qishiweizhiY+(GetFontHeight()+hangju),winwidth,jieshuweizhiY-qishiweizhiY-(GetFontHeight()+hangju),1);
			if(qishiweizhiY<winheight*0.85)drawRectangle(0,qishiweizhiY,qishiweizhiX,(GetFontHeight()+hangju),1);
		}
	}
	p:
	menudisplay();
    display();
}

void FileOpen()
{
	int i;
	char ch;
	char buffer[32];
	OpenFileDialog(NULL, filename);
	fp=fopen(filename, "r+");
	if(fp!=NULL)
	{
	strcpy(results, "\0");
	total=0;
	current=0;
	
	fscanf(fp, "%d %d %d %d %d ", &hangju, &bgcolor, &pointsize, &font, &pencolor);
	
	while(!feof(fp)){
		fread(&ch, sizeof(char), 1, fp);
		if(ch == '\n'){
	    	for(i = total; i >= current; i--)
	    	{
		    	results[i + 1] = results[i];
	    	}
	    	results[current++] = '\n';
	    	total++;
	    	if(total >= max - 2)
	    	{
		    	max += 32;
		    	results = (char *)realloc(results, max);
	    	}
		}else{
	    	for(i = total; i >= current; i--)
	    	{
		    	results[i + 1] = results[i];
	    	}
	    	results[current++] = ch;
	    	total++;
	    	if(total >= max - 2)
	    	{
		    	max += 32;
		    	results = (char *)realloc(results, max);
	    	}
		}
	}
	fclose(fp);
	results[total-1]='\0';
	current--;
	total--;
	display();
    }
    else
    {
    	fileTXT1=1;
    	HelpTXT=1;
	}
}

void FileSave()
{
	SaveFileDialog(".txt", filename);
	fp=fopen(filename, "w+");
	if(fp==NULL)
	{
		fileTXT2=1;
		HelpTXT=1;
	}
	else
	{
	fprintf(fp, "%d %d %d %d %d ", hangju, bgcolor, pointsize, font, pencolor);
	fprintf(fp, "%s", results);
	fclose(fp);
    }
}

extern void CharEventProcess(char ch);
extern void KeyboardEventProcess(int key, int event);
extern void TimerEventProcess();
extern void menuMouseEventProcess(int x,int y,int button,int event);

void Main()
{
	SetWindowSize(GetFullScreenWidth(),GetFullScreenHeight());
	InitGraphics();
    SetWindowTitle("自定义文本编辑器");
    HelpTXT=1;
    menudisplay();
	results = (char *)calloc(sizeof(char), max);
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();
    MovePen(0, winheight*0.85);
    fuzhineirong = (char*)calloc(sizeof(char),32);
    registerCharEvent(CharEventProcess);        
	registerKeyboardEvent(KeyboardEventProcess);
	registerTimerEvent(TimerEventProcess);
	registerMouseEvent(menuMouseEventProcess);
	startTimer(1, 300);
}
