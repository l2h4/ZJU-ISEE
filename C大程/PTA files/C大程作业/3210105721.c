#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int option, value,initialCount;
	scanf("%d",&initialCount);
	struct sortedArray *a = NewDynamicArray(initialCount);
	if(input_array(a) == -1){ /* ���ú��������������� a */
	return 0;
	}
	printf("[1] Insert\n"); /* ����4����ʾ�˵�*/
	printf("[2] Delete\n");
	printf("[3] Query\n");
	printf("[4]GetNumOfCreatedArray\n");
	printf("[Other option] End\n");
	while (1) { 
	printf("Input option: "); /* ��ʾ������ */
	scanf("%d", &option); /* �����û�����ı�� */
	if (option < 1 || option > 4) { /* �������1��2��3��4����ı�ţ�����ѭ�� */
	break;
	}
	if(option==4){
		select(a,option,value);
	}
	else{
	printf("Input an element: "); /* ��ʾ������� */
	scanf("%d", &value); /* �����û�����Ĳ���value */
	select(a, option, value); /* ���ÿ��ƺ��� */
	}
	printf("\n");
	}
	FreeDynamicArray(a);
	printf("Thanks."); /* �������� */
	return 0;
}
