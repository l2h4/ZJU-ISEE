#ifndef _dynamicarray_h
#define _dynamicarray_h


//动态有序表的创建
struct sortedArray *NewDynamicArray(int initialCount);

//动态有序表的销毁 
void FreeDynamicArray(struct sortedArray *array);
 
 //动态有序表的插入
 void InsertElement(struct sortedArray *array, int value);
 
 //删除
void DeleteElement(struct sortedArray *array, int value);

//查询
void QueryElement(struct sortedArray *array, int value);

//打印
void PrintDynamicArray(struct sortedArray *array);

// 记录使用该类库创建的动态有序表数量，支持查询创建的动态有序表数量
unsigned int GetNumOfCreatedArray(); 
 
 //有序表的输入
int input_array(struct sortedArray *a);

//控制
void select(struct sortedArray *a, int option, int value); 
 
 struct sortedArray {
 int *ptr;         // 指向动态内存的指针 
 int count;        // 当前存储的数组元素个数 
 int capacity;     // 当前数组的元素容量 (capacity >= count) 
};

 #endif 
