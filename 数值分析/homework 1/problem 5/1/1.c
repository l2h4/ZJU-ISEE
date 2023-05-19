#include<stdio.h>
#include<math.h>

#define e 2.71828
#define f(x) (pow(e,x)-pow(x,2)+3*x-2)
int main()
{
    double x1=0, x2=1, m=0, i=1, fm=0;

    do{
        m=(x1+x2)/2;
        fm=f(m);
        if(fm>0){
            x2=m;
        }else if(fm<0){
            x1=m;
        }else{
            printf("%lf", m);
            break;
        }
        printf("%lf\n", m);
        printf("%lf\t", fm);
        i++;
    }while(i<34);

    return 0;

}