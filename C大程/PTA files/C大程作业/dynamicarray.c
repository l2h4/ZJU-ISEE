#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

int num = 0;

//动态有序表的创建
struct sortedArray *NewDynamicArray(int initialCount)
{
	num++;
	struct sortedArray *array = (struct sortedArray*)malloc(sizeof(struct sortedArray));
	array->ptr = (int*)malloc(initialCount*sizeof(int)); 
	if (!array->ptr) //如果申请失败，作出提示并直接退出程序
    {
        printf("Failure.");
        exit(0);
    }
    array->count=0;//空表的长度初始化为0
    array->capacity=initialCount;//空表的初始存储空间
    return array;
}

//销毁 
void FreeDynamicArray(struct sortedArray *array)
{
	if(array==NULL){
		return;
	}
	free(array->ptr);
	free(array);
}
 
 //插入
 void InsertElement(struct sortedArray *array, int value)
 {
 	int i, j;
	 if (array->count == array->capacity) { /* 申请空间用完，申请更大的空间 */
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
	for (i = 0; i < array->count; i++) { /* 定位：找到待插入的位置，即退出循环时i的值*/
	if (value == (array->ptr)[i]) {
	printf("The element is already in the array.");
	return;
	}
	if (value < (array->ptr)[i]) {
	break;
	}
	}
	for(j = array->count -1; j >= i; j--){ /* 腾位：将a[i]~a[Count-1]向后顺移一位 */
	(array->ptr)[j+1] = (array->ptr)[j];
	}
	(array->ptr)[i] = value; /* 插入：将value 的值赋给a[i] */
	array->count++; /* 增1：数组a中待处理的元素数量增1 */
	PrintDynamicArray(array); /* 调用输出函数，输出插入后的有序数组a */
 }
 
 //删除
void DeleteElement(struct sortedArray *array, int value)
{
	int i, index = -1; /* index的值为-1表示没找到，否则表示找到 */
	for(i = 0; i < array->count; i++){ /* 定位：如果找到待删除的元素，用index记录其下标*/
	if(value == (array->ptr)[i]){
	index = i;
	break;
	}
	}
	if(index == -1){ /* 没找到，则输出相应的信息 */
	printf("Failed to find the data, deletion failed.");
	return;
	}else{ /* 找到，则删除a[index] */
	for(i = index; i < array->count - 1; i++){ /* 将a[Count-1]~a[index+1]向前顺移一位 */
	(array->ptr)[i] = (array->ptr)[i+1];
	}
	array->count--; /* 减1：数组a中待处理的元素数量减1 */
	PrintDynamicArray(array); /* 调用输出函数，输出删除后的有序数组a */
	}
}

//查询
void QueryElement(struct sortedArray *array, int value)
{
	int mid, left = 0, right = array->count - 1; /* 开始时查找区间为整个数组 */
    while (left <= right){ /* 循环条件 */
    mid = (left + right) / 2; /* 得到中间位置 */
	if (value == (array->ptr)[mid]){ /* 查找成功，输出下标，函数返回 */
	printf("The index is: %d", mid);
	return;
	}else if (value < (array->ptr)[mid]){ /* 缩小查找区间为前半段，right前移 */
	right = mid - 1;
	}else{ /* 缩小查找区间为后半段，left后移 */
	left = mid + 1;
	}
	}
	printf( "This element does not exist."); /* value不在数组a中 */
}

//打印
void PrintDynamicArray(struct sortedArray *array)
{
	int i;
    printf("The ordered array a[%d] is: ", array->capacity);
    for (i = 0; i < array->count; i ++) { /* 输出时相邻数字间用一个空格分开，行末无空格 */
    if(i == 0)
    printf("%d", (array->ptr)[i]);
    else
    printf(" %d", (array->ptr)[i]);
   }
}

// 记录使用该类库创建的动态有序表数量，支持查询创建的动态有序表数量
unsigned int GetNumOfCreatedArray()
{
	printf("The number of created array is %d",num);
	return num;
}

//有序表的输入
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

//控制函数
void select(struct sortedArray *a, int option, int value)
{
	switch (option)
	{
	case 1:
	InsertElement(a, value); /* 调用插入函数在有序数组 a 中插入元素value */
	break;
	case 2:
	DeleteElement(a, value); /* 调用删除函数在有序数组 a 中删除元素value */
	break;
	case 3:
	QueryElement(a, value); /* 调用查询函数在有序数组 a 中查找元素value */
	break;
	case 4:
	GetNumOfCreatedArray();/*查询动态表创建数*/
	break;
}
} 
