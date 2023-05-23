#include "dynamicarray.h"

int num;
struct sortedArray *NewDynamicArray(int initialCapacity)
{
	num++;
	struct sortedArray *array = (struct sortedArray*)malloc(sizeof(struct sortedArray));
	array->ptr = (int*)malloc(16*sizeof(int)); 
	if (!array->ptr) //�������ʧ�ܣ�������ʾ��ֱ���˳�����
    {
        printf("Failure.");
        exit(0);
    }
    array->count=0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    array->capacity=16;//�ձ�ĳ�ʼ�洢�ռ�
    return array;
}

void FreeDynamicArray(struct sortedArray *array)
{
	
	if(array==NULL){
		return;
	}else{
		free(array->ptr);
		free(array);
	}
}

void InsertElement(struct sortedArray *array, int value)
{

    int i, j;
    if (array->count == array->capacity) { /* ����ռ����꣬�������Ŀռ� */
        int *b = (int *) realloc(array->ptr, array->capacity * 2 * sizeof(int));
        if (b != NULL) {
            array->ptr = b;
            array->capacity = array->capacity * 2;
        }else {
            printf("Memory Allocation Failed.");
            return;
        }
    }
 
    for (i = 0; i < array->count; i++) {
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

void DeleteElement(struct sortedArray *array, int value)
{
	int i, index = -1; /* index��ֵΪ-1��ʾû�ҵ��������ʾ�ҵ� */
 
    for(i = 0; i < array->count; i++){
 	    if(value == (array->ptr)[i]){
 			index = i;
 			break;
 		}
 	}
 	if(index == -1){ /* û�ҵ����������Ӧ����Ϣ */
 		printf("Failed to find the data, deletion failed.");
 		return;
 	}else{ /* �ҵ�����ɾ��a[index] */
 		for(i = index; i < array->count - 1; i++){
 			(array->ptr)[i] = (array->ptr)[i+1];
 		}
 	array->count--; /* ��1������a�д������Ԫ��������1 */
 	PrintDynamicArray(array); /* ����������������ɾ�������������a */
 	}
}

int  QueryElement(struct sortedArray *array, int value)
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
 	printf( "This element does not exist."); 
}

void PrintDynamicArray(struct sortedArray *array)
{
	int i;
 	printf("The ordered array a(%d) is: ", array->capacity);
 	for (i = 0; i < array->count; i ++) { /* ���ʱ�������ּ���һ���ո�ֿ�����ĩ�޿ո� */
 		if(i == 0)
 			printf("%d", (array->ptr)[i]);
 		else
 			printf(" %d", (array->ptr)[i]);
 	}
}

unsigned int GetNumOfCreatedArray()
{
	printf("The number of created array is %d",num);
	return num;
}












