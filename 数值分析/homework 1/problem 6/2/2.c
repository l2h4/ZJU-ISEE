#include<stdio.h>
#include<math.h>

#define f1(x) ((1/pow(3, 0.5))*exp(x/2))
#define f2(x) (-(1/pow(3, 0.5))*exp(x/2))

int main()
{
    double x=0, xnext=0;
    int i=1;
    
    printf("[0,1]\n");
    do{
        x=xnext;
        xnext=f1(x);
        printf("number: %d  %lf %lf\n", i, x, xnext);
        i++;
    }while((xnext-x)>xnext*pow(10, -2) || (xnext-x)<-xnext*pow(10, -2));

    printf("[-1,0]\n");
    x=0;
    xnext=0;
    i=1;
    do{
        x=xnext;
        xnext=f2(x);
        printf("number: %d  %lf %lf\n", i, x, xnext);
        i++;
    }while((xnext-x)>-xnext*pow(10, -2) || (xnext-x)<xnext*pow(10, -2));

    return 0;
}