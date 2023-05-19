#include<stdio.h>
#include<math.h>
#define f(x) (x*cos(x)-2*pow(x, 2)+3*x-1)

int main()
{
    double x1=0.2, x2=0.3, m=0, fm=0, i=1;

    printf("between 0.2 and 0.3");
    do{
        m=(x1+x2)/2;
        fm=f(m);
        if(fm>0){
            x2=m;
        }else if(fm<0){
            x1=m;
        }else{
            printf("x=%lf", m);
            break;
        }
        printf("%lf\t", m);
        printf("%lf\n", fm);
        i++;
    } while(i<20);

    printf("between 1.2 and 1.3");

    x1=1.2;
    x2=1.3;
    m=0;
    fm=0;
    i=1;
    do{
        m=(x1+x2)/2;
        fm=f(m);
        if(fm>0){
            x2=m;
        }else if(fm<0){
            x1=m;
        }else{
            printf("x=%lf", m);
            break;
        }
        printf("%lf\t", m);
        printf("%lf\n", fm);
        i++;
    } while(i<20);

    return 0;
}