#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int option, value,initialCount;
	scanf("%d",&initialCount);
	struct sortedArray *a = NewDynamicArray(initialCount);
	if(input_array(a) == -1){ /* 调用函数输入有序数组 a */
	return 0;
	}
	printf("[1] Insert\n"); /* 以下4行显示菜单*/
	printf("[2] Delete\n");
	printf("[3] Query\n");
	printf("[4]GetNumOfCreatedArray\n");
	printf("[Other option] End\n");
	while (1) { 
	printf("Input option: "); /* 提示输入编号 */
	scanf("%d", &option); /* 接受用户输入的编号 */
	if (option < 1 || option > 4) { /* 如果输入1、2、3、4以外的编号，结束循环 */
	break;
	}
	if(option==4){
		select(a,option,value);
	}
	else{
	printf("Input an element: "); /* 提示输入参数 */
	scanf("%d", &value); /* 接受用户输入的参数value */
	select(a, option, value); /* 调用控制函数 */
	}
	printf("\n");
	}
	FreeDynamicArray(a);
	printf("Thanks."); /* 结束操作 */
	return 0;
}
