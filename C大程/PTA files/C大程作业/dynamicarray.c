#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

int num = 0;

//��̬�����Ĵ���
struct sortedArray *NewDynamicArray(int initialCount)
{
	num++;
	struct sortedArray *array = (struct sortedArray*)malloc(sizeof(struct sortedArray));
	array->ptr = (int*)malloc(initialCount*sizeof(int)); 
	if (!array->ptr) //�������ʧ�ܣ�������ʾ��ֱ���˳�����
    {
        printf("Failure.");
        exit(0);
    }
    array->count=0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    array->capacity=initialCount;//�ձ�ĳ�ʼ�洢�ռ�
    return array;
}

//���� 
void FreeDynamicArray(struct sortedArray *array)
{
	if(array==NULL){
		return;
	}
	free(array->ptr);
	free(array);
}
 
 //����
 void InsertElement(struct sortedArray *array, int value)
 {
 	int i, j;
	 if (array->count == array->capacity) { /* ����ռ����꣬�������Ŀռ� */
	int *b = (int *) realloc(array->ptr, array->capacity * 2 * sizeof(int));
	if (b != NULL) {
	array->ptr = b;
	array->capacity = array->capacity * 2;
	}
	else {
	printf("Memory Allocation Failed.");
	return;
	}
	}
	for (i = 0; i < array->count; i++) { /* ��λ���ҵ��������λ�ã����˳�ѭ��ʱi��ֵ*/
	if (value == (array->ptr)[i]) {
	printf("The element is already in the array.");
	return;
	}
	if (value < (array->ptr)[i]) {
	break;
	}
	}
	for(j = array->count -1; j >= i; j--){ /* ��λ����a[i]~a[Count-1]���˳��һλ */
	(array->ptr)[j+1] = (array->ptr)[j];
	}
	(array->ptr)[i] = value; /* ���룺��value ��ֵ����a[i] */
	array->count++; /* ��1������a�д������Ԫ��������1 */
	PrintDynamicArray(array); /* ������������������������������a */
 }
 
 //ɾ��
void DeleteElement(struct sortedArray *array, int value)
{
	int i, index = -1; /* index��ֵΪ-1��ʾû�ҵ��������ʾ�ҵ� */
	for(i = 0; i < array->count; i++){ /* ��λ������ҵ���ɾ����Ԫ�أ���index��¼���±�*/
	if(value == (array->ptr)[i]){
	index = i;
	break;
	}
	}
	if(index == -1){ /* û�ҵ����������Ӧ����Ϣ */
	printf("Failed to find the data, deletion failed.");
	return;
	}else{ /* �ҵ�����ɾ��a[index] */
	for(i = index; i < array->count - 1; i++){ /* ��a[Count-1]~a[index+1]��ǰ˳��һλ */
	(array->ptr)[i] = (array->ptr)[i+1];
	}
	array->count--; /* ��1������a�д������Ԫ��������1 */
	PrintDynamicArray(array); /* ����������������ɾ�������������a */
	}
}

//��ѯ
void QueryElement(struct sortedArray *array, int value)
{
	int mid, left = 0, right = array->count - 1; /* ��ʼʱ��������Ϊ�������� */
    while (left <= right){ /* ѭ������ */
    mid = (left + right) / 2; /* �õ��м�λ�� */
	if (value == (array->ptr)[mid]){ /* ���ҳɹ�������±꣬�������� */
	printf("The index is: %d", mid);
	return;
	}else if (value < (array->ptr)[mid]){ /* ��С��������Ϊǰ��Σ�rightǰ�� */
	right = mid - 1;
	}else{ /* ��С��������Ϊ���Σ�left���� */
	left = mid + 1;
	}
	}
	printf( "This element does not exist."); /* value��������a�� */
}

//��ӡ
void PrintDynamicArray(struct sortedArray *array)
{
	int i;
    printf("The ordered array a[%d] is: ", array->capacity);
    for (i = 0; i < array->count; i ++) { /* ���ʱ�������ּ���һ���ո�ֿ�����ĩ�޿ո� */
    if(i == 0)
    printf("%d", (array->ptr)[i]);
    else
    printf(" %d", (array->ptr)[i]);
   }
}

// ��¼ʹ�ø���ⴴ���Ķ�̬�����������֧�ֲ�ѯ�����Ķ�̬���������
unsigned int GetNumOfCreatedArray()
{
	printf("The number of created array is %d",num);
	return num;
}

//����������
int input_array(struct sortedArray *array)
{
	int i;
	printf("Input the number of array elements: ");
	scanf("%d", &(array->count));
	if(array->count>array->capacity) array->capacity = 2*array->count;
	array->ptr = (int *) malloc(array->capacity * sizeof(int));
	if (array->ptr == NULL) {
	printf("Error: Not Enough Memory\n");
	return -1;
	}
	printf("Input an ordered array element: ");
	for (i = 0; i < array->count; i ++) {
	scanf("%d", array->ptr + i);
	if(i > 0 && (array->ptr)[i] <= (array->ptr)[i-1]){
	printf("Error");
	return -1;
	}
	}
	return 0;
} 

//���ƺ���
void select(struct sortedArray *a, int option, int value)
{
	switch (option)
	{
	case 1:
	InsertElement(a, value); /* ���ò��뺯������������ a �в���Ԫ��value */
	break;
	case 2:
	DeleteElement(a, value); /* ����ɾ���������������� a ��ɾ��Ԫ��value */
	break;
	case 3:
	QueryElement(a, value); /* ���ò�ѯ�������������� a �в���Ԫ��value */
	break;
	case 4:
	GetNumOfCreatedArray();/*��ѯ��̬������*/
	break;
}
} 
