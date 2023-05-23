#ifndef _students_h
#define _students_h

#include<stdio.h>
#include<stdlib.h>

struct sortedArray {
    int *ptr; // ָ��̬�ڴ��ָ��
    int count; // ��ǰ�洢������Ԫ�ظ���
    int capacity; // ��ǰ�����Ԫ������ (capacity >= count) 
};

struct sortedArray *NewDynamicArray(int initialCapacity);

void FreeDynamicArray(struct sortedArray *array);

void InsertElement(struct sortedArray *array, int value);

void DeleteElement(struct sortedArray *array, int value);

int  QueryElement(struct sortedArray *array, int value);

void PrintDynamicArray(struct sortedArray *array);

unsigned int GetNumOfCreatedArray();

#endif
