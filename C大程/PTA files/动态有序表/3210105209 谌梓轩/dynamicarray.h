#ifndef _students_h
#define _students_h

#include<stdio.h>
#include<stdlib.h>

struct sortedArray {
    int *ptr; // 指向动态内存的指针
    int count; // 当前存储的数组元素个数
    int capacity; // 当前数组的元素容量 (capacity >= count) 
};

struct sortedArray *NewDynamicArray(int initialCapacity);

void FreeDynamicArray(struct sortedArray *array);

void InsertElement(struct sortedArray *array, int value);

void DeleteElement(struct sortedArray *array, int value);

int  QueryElement(struct sortedArray *array, int value);

void PrintDynamicArray(struct sortedArray *array);

unsigned int GetNumOfCreatedArray();

#endif
