#include<stdio.h>
#include<string.h>
int main(void)
{
   int i;
   const char *color[2] = {"blue", "green"}; 
   
   for(i = 0; i < 2; i++) {
      printf("%s %c\n", color[i], *color[i]);  /* �������֮����һ���ո� */ 
   }   
   for(i = 0; i < 2; i++) {
      printf("%s %c\n", color[i]+1, *color[i]+1); /* �������֮����һ���ո� */ 
   }   
       
   return 0;
}















