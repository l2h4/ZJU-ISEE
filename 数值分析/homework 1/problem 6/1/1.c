#include<stdio.h>
#include<math.h>

#define pi 3.14159
#define f(x) 1/pi+2*sin(pi*x)/(pi*x)+x

int main()
{
    double x=1, xnext=1;
    int i=1;

    do{
        x=xnext;
        xnext=f(x);
        printf("number: %d    %lf    %lf\n", i, x, xnext);
        i++;
    }while((xnext-x)>pow(10, -2) || (xnext-x)<-pow(10, -2));

    return 0;
}