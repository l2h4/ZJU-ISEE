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

extern int current, anxiacurrent, taiqicurrent, total;
extern double winheight, winwidth;
extern char *results;
char *fuzhineirong;
extern int max;
extern char chazhaoneirong[200];
extern char tihuanneirong[200];

void quanxuan()
{
	current = total;
	anxiacurrent = 0;
	taiqicurrent = total;
	huajuxing();
}

void shanchu(int a, int b)
{
	if(a > b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	int t;
	for(t = b; t < total; t++)
	{
        results[t - b + a] = results[t];
	}
	total -= (b - a);
	results[total] = 0;
	current = a;
	anxiacurrent = a;
	taiqicurrent = a;
}
void fuzhi()
{
	int daxiao;
	int i=0;
	if(anxiacurrent < taiqicurrent)
	{
		anxiacurrent = anxiacurrent + taiqicurrent;
		taiqicurrent = anxiacurrent - taiqicurrent;
		anxiacurrent = anxiacurrent - taiqicurrent;
	}
	daxiao=anxiacurrent-taiqicurrent;
	fuzhineirong=(char*)realloc(fuzhineirong,sizeof(char)*(daxiao+1));
	for(i=0;i<daxiao;i++)
	{
		fuzhineirong[i]=results[taiqicurrent+i];
	}
	fuzhineirong[daxiao]='\0';
}
void zhantie(char *a)
{
	if(anxiacurrent!=taiqicurrent)
	{
		shanchu(anxiacurrent,taiqicurrent);
	}
	int i;
	int daxiao=strlen(a);
	int yuanshitotal;
	yuanshitotal=total;
	while(total + daxiao >= max - 2)
	    {
		    max += 32;
	    }
	    results = (char *)realloc(results, max);
	    total+=daxiao;
	for(i=yuanshitotal;i>=current;i--)
	{
		results[i+daxiao]=results[i];
	}
	for(i=0;i<daxiao;i++)
	{
		results[current+i]=a[i];
	}
	results[total]='\0';
	current=current+daxiao;
	anxiacurrent=taiqicurrent=current;
	huajuxing();
}

void jianqie()
{
	fuzhi();
	shanchu(anxiacurrent,taiqicurrent);
	total-=abs(anxiacurrent-taiqicurrent);
	huajuxing();
}

void chazhao()
{
	int i = current, j, t;
	while(i < total)
	{
		t = i;
		j = 0;
		while(j < strlen(chazhaoneirong))
		{
			if(results[t] != chazhaoneirong[j])break;
			t++;j++;
		}
		if(j == strlen(chazhaoneirong))break;
		i++;
	}
	if(i != total)
	{
		anxiacurrent=i;
		current=taiqicurrent=i+strlen(chazhaoneirong);
	}
	else
	{
		anxiacurrent=taiqicurrent=current;
	}
	huajuxing();
}

void tihuan()
{
	current = 0;
	while(1)
	{
		chazhao();
		if(anxiacurrent!=taiqicurrent)
		{
			shanchu(anxiacurrent,taiqicurrent);
			zhantie(tihuanneirong);
		}
		else break;
	}
}
