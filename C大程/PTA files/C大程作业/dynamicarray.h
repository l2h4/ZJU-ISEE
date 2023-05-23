#ifndef _dynamicarray_h
#define _dynamicarray_h


//��̬�����Ĵ���
struct sortedArray *NewDynamicArray(int initialCount);

//��̬���������� 
void FreeDynamicArray(struct sortedArray *array);
 
 //��̬�����Ĳ���
 void InsertElement(struct sortedArray *array, int value);
 
 //ɾ��
void DeleteElement(struct sortedArray *array, int value);

//��ѯ
void QueryElement(struct sortedArray *array, int value);

//��ӡ
void PrintDynamicArray(struct sortedArray *array);

// ��¼ʹ�ø���ⴴ���Ķ�̬�����������֧�ֲ�ѯ�����Ķ�̬���������
unsigned int GetNumOfCreatedArray(); 
 
 //����������
int input_array(struct sortedArray *a);

//����
void select(struct sortedArray *a, int option, int value); 
 
 struct sortedArray {
 int *ptr;         // ָ��̬�ڴ��ָ�� 
 int count;        // ��ǰ�洢������Ԫ�ظ��� 
 int capacity;     // ��ǰ�����Ԫ������ (capacity >= count) 
};

 #endif 
