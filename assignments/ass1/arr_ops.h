#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#include <stddef.h>

int ascCompare(const void *a, const void *b);
int descCompare(const void *a, const void *b);
int getStatus();
void createArr(int **arr, size_t *arr_size);
void printArr(int *arr, size_t arr_size);
void insertArr(int *arr, size_t arr_size);
void deleteArr(int *arr, size_t arr_size);
void sortArrAsc(int *arr, size_t arr_size);
void sortArrDesc(int *arr, size_t arr_size);
void findElementArr(int *arr, size_t arr_size);

#endif  // ARRAY_OPS_H