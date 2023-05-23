#include<stdio.h>
#include<string.h>
int main(void)
{
   int i;
   const char *color[2] = {"blue", "green"}; 
   
   for(i = 0; i < 2; i++) {
      printf("%s %c\n", color[i], *color[i]);  /* 输出数据之间间隔一个空格 */ 
   }   
   for(i = 0; i < 2; i++) {
      printf("%s %c\n", color[i]+1, *color[i]+1); /* 输出数据之间间隔一个空格 */ 
   }   
       
   return 0;
}















