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

int kongzhi;
extern int firstline;
extern double winheight, winwidth;
extern int current, total, max, anxiacurrent, taiqicurrent, bgcolor;
extern char *results;
extern int tihuanmodule1, tihuanmodule2,chazhaomodule, HelpTXT, showopen, showsave, showsize, showbg, showlook;
extern char *fuzhineirong;
extern double hangju;
char chazhaoneirong[200];
char tihuanneirong[200];
int chazhaototal, tihuantotal;

extern void chazhao();
extern void tihuan(); 

void CharEventProcess(char ch)
{
	if(kongzhi||HelpTXT)
		return;
	else if(chazhaomodule)
	{
    if(ch != VK_BACK && ch != VK_RETURN)
	{
        chazhaoneirong[chazhaototal++]=ch; 
        chazhaoneirong[chazhaototal]=0;
    }
    else if(ch==VK_BACK)
	{
    	chazhaoneirong[0] = 0;
		chazhaototal = 0; 
	}
	else if(ch == VK_RETURN)
	{
		chazhaomodule = 0;
		chazhao();
	}
    }
    else if(tihuanmodule1)
    {
        if(ch != VK_BACK && ch != VK_RETURN)
	    {
            chazhaoneirong[chazhaototal++]=ch; 
            chazhaoneirong[chazhaototal]=0;
        }
        else if(ch==VK_BACK)
	    {
    	    chazhaoneirong[0] = 0;
		    chazhaototal = 0; 
	    }
	    else if(ch == VK_RETURN)
	    {
		    tihuanmodule1 = 0;
		    tihuanmodule2 = 1;
	    }
	}
	else if(tihuanmodule2)
	{
        if(ch != VK_BACK && ch != VK_RETURN)
	    {
            tihuanneirong[tihuantotal++]=ch; 
            tihuanneirong[tihuantotal]=0;
        }
        else if(ch==VK_BACK)
	    {
    	    tihuanneirong[0] = 0;
		    tihuantotal = 0; 
	    }
	    else if(ch == VK_RETURN)
	    {
		    tihuanmodule2 = 0;
		    tihuan();
	    }
	}
	else
	{
    if(ch != VK_BACK && ch != VK_RETURN)
	{
	    int i;
	    if(anxiacurrent == taiqicurrent)
	    {
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
	    else
	    {
	    	shanchu(anxiacurrent, taiqicurrent);
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
    else if(ch == VK_RETURN)
    {
        int i;
        if(anxiacurrent == taiqicurrent)
        {
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
	    }
	    else
	    {
	    	shanchu(anxiacurrent, taiqicurrent);
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
		}
	}
    }
	huajuxing();
}

void KeyboardEventProcess(int key, int event)
{
	if(HelpTXT||chazhaomodule||tihuanmodule1||tihuanmodule2)return;
	if(key == 65 && event == KEY_DOWN && kongzhi)
	    quanxuan();
	else if(key == 67 && event == KEY_DOWN && kongzhi)
		fuzhi();
	else if(key == 88 && event == KEY_DOWN && kongzhi)
		jianqie();
	else if(key == 86 && event == KEY_DOWN && kongzhi)
		zhantie(fuzhineirong);
	else if(key == 83 && event == KEY_DOWN && kongzhi)
	{
	    FileSave();
        kongzhi = 1 - kongzhi;
	}
	else if(key == 79 && event == KEY_DOWN && kongzhi)
	{
	    FileOpen();
	    kongzhi = 1 - kongzhi;
	}
	else if(key==VK_CONTROL)
	    kongzhi = 1 - kongzhi;
    else if(key == VK_BACK && event == KEY_DOWN)
	{
		if(anxiacurrent == taiqicurrent)
		{
		if(current)
		{
            int i;
            if((int)results[current - 1] > 0 && (int)results[current - 1] < 128)
            {
                for(i = current-1;i < total;i++)
		        {
        	        results[i] = results[i + 1];
		        }
                current--;total--;
            }
            else
            {
                for(i = current - 2; i < total; i++)
		        {
        	        results[i]=results[i + 2];
		        }
                current -= 2; total -= 2;
		    }
        }
        }
        else
        {
            shanchu(anxiacurrent, taiqicurrent);
		}
	}
	else if(key == VK_DELETE && event == KEY_DOWN)
	{
		if(anxiacurrent == taiqicurrent)
		{
		if(current < total)
		{
            int i;
            if((int)results[current] >= 0 && (int)results[current] < 128)
            {
                for(i = current; i<total; i++)
		        {
        	        results[i] = results[i + 1];
		        }
                total--;
            }
            else
            {
                for(i = current; i < total; i++)
		        {
        	        results[i] = results[i + 2];
		        }
                total -= 2;
		    }
        }
        }
        else
        {
            shanchu(anxiacurrent, taiqicurrent);
		}
	}
	else if(key == VK_LEFT && event == KEY_DOWN)
	{
        if(current>0)
        {
            SetEraseMode(1);
            DrawLine(0, GetFontHeight());
            SetEraseMode(0);
            if(results[current - 1] == '\n')
	        {
                current--;
	        }
            else if((int)results[current - 1] >= 0 && (int)results[current - 1] < 128)
	            current--;
	        else
	            current -= 2;
	        anxiacurrent = current;
	        taiqicurrent = current;
        }
    }
	else if(key == VK_RIGHT && event == KEY_DOWN)
	{
        if(current < total)
        {
            SetEraseMode(1);
            DrawLine(0, GetFontHeight());
            SetEraseMode(0);
            if(results[current] == '\n')
	        {
                current++;
	        }
            else if((int)results[current] > 0 && (int)results[current] < 128)
	            current++;
	        else
	            current += 2;
	        anxiacurrent = current;
	        taiqicurrent = current;
	    }
	}
	huajuxing();
}

void TimerEventProcess()
{
	if(HelpTXT||chazhaomodule||tihuanmodule1||tihuanmodule2)return;
	static eraser;
	int i = 1, line = 1, t;
	if(!current)
	    i = 0;
	else
	    while(i < current && results[current - i] != '\n')
		    i++;
	for(t = 0; t < current; t++)
	{
		if(results[t] == '\n')
		    line++;
	}
	if(line>firstline)
	{
	MovePen(TextStringWidth(results + current - i) - TextStringWidth(results + current), 
	winheight * 0.85 - (line-firstline) * (GetFontHeight()+hangju));
    eraser = 1 - eraser;
    if(eraser)
    {
    if(bgcolor==1)SetPenColor("White");
	else if(bgcolor==2)SetPenColor("Light Gray");
	else if(bgcolor==3)SetPenColor("Gray");
	else if(bgcolor==4)SetPenColor("Dark Gray");
	}
	else SetPenColor("Black");
    DrawLine(0, GetFontHeight());
    MovePen(GetCurrentX(), GetCurrentY() - (GetFontHeight()+hangju));
    }
}
