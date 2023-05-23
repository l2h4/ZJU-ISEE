#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"
 
int main(void) {
	struct sortedArray *a = NewDynamicArray(16);
    if (a == NULL || a->ptr == NULL || a->count != 0 || a->capacity != 16) {
        printf("Create Dynamic Array Test Failed.\n");
        return;
    }
    if (GetNumOfCreatedArray() != 1) {
        printf("Get Number of Dynamic Array Test Failed.\n");
        return;
    }

    struct sortedArray *b = NewDynamicArray(32);
    if (b == NULL || b->ptr == NULL || b->count != 0 || b->capacity != 32) {
        printf("Create Dynamic Array Test Failed.\n");
        return;
    }
    if (GetNumOfCreatedArray() != 2) {
        printf("Get Number of Dynamic Array Test Failed.\n");
        return;
    }

    InsertElement(a, 1);
    InsertElement(a, 2);
    InsertElement(a, 3);
    if (a->count != 3) {
        printf("Insert Dynamic Array Test Failed.\n");
        return;
    }
    int index = QueryElement(a, 3);
    if (index != 2) {
        printf("Query Dynamic Array Test Failed.\n");
        return;
    }
    DeleteElement(a, 3);
    DeleteElement(a, 4);
    if (a->count != 2) {
        printf("Insert Dynamic Array Test Failed.\n");
        return;
    }

    DeleteElement(a, 1);
    InsertElement(b, 1);
    InsertElement(b, 2);
    InsertElement(b, 3);
    if (a->count != 1 || b->count != 3) {
        printf("Insert Dynamic Array Test Failed.\n");
        return;
    }


    FreeDynamicArray(a);
    FreeDynamicArray(b);
    if (GetNumOfCreatedArray() != 0) {
        printf("Get Number of Dynamic Array Test Failed.\n");
        return;
    }

	
	return 0;
}
