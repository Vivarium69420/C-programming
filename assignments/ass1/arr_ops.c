#include "arr_ops.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ascCompare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int descCompare(const void *a, const void *b) {
  return (*(int *)b - *(int *)a);
}

int getStatus() {
  char input[MAX_INPUT];
  int status;
  char *endptr;

  while (1) {
    printf("[?] Status (1: Continue, 0: Exit): ");
    if (scanf("%99s", input) != 1) {
      printf("[!] ERROR: Invalid input. Please enter 0 or 1.\n");
      continue;
    }

    // Convert input to integer
    status = strtol(input, &endptr, 10);

    // Check if the input is a valid integer and within the expected range
    if (*endptr == '\0' && (status == 0 || status == 1))
      break;
    else
      printf("[!] ERROR: Invalid input. Please enter 0 or 1.\n");
  }

  return status;
}

void createArr(int **arr, size_t *arr_size) {
  // If the array is not empty, free the old array
  if (*arr != NULL) {
    free(*arr);
  }

  // Get the size of the array
  printf("[?] Enter the size of the array: ");
  scanf("%zu", arr_size);

  // Allocate memory for the array
  *arr = (int *)malloc(*arr_size * sizeof(int));
  if (!*arr) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // Initialize array elements to INT_MIN to represent "empty"
  for (size_t i = 0; i < *arr_size; i++) {
    (*arr)[i] = INT_MIN;
  }

  printf("> Array created successfully with size of %zu\n", *arr_size);
}

void printArr(int *arr, size_t arr_size) {
  if (arr == NULL) {
    printf("> Array is empty\n");
    return;
  }

  printf("> [");
  for (size_t i = 0; i < arr_size; i++) {
    if (arr[i] == INT_MIN) {
      printf("empty");
    } else {
      printf("%d", arr[i]);
    }
    if (i < arr_size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void insertArr(int *arr, size_t arr_size) {
  int value;
  int position;
  int isContinue;

  printf("[?] Value: ");
  scanf("%d", &value);
  printf("[?] Position: ");
  scanf("%d", &position);

  while (position < 1 || position > arr_size) {
    printf("[!] Error: Invalid position, please try again.\n");
    isContinue = getStatus();
    if (!isContinue) {
      return;
    }
    printf("[?] Position: ");
    scanf("%d", &position);
  }

  arr[position - 1] = value;
  printf("> Value %d inserted at position %d\n", value, position);
}

void deleteArr(int *arr, size_t arr_size) {
  int position;
  int isContinue;

  printf("[?] Position: ");
  scanf("%d", &position);

  while (position < 1 || position > arr_size) {
    printf("[!] Error: Invalid position, please try again.\n");
    isContinue = getStatus();
    if (!isContinue) {
      return;
    }
    printf("[?] Position: ");
    scanf("%d", &position);
  }

  if (arr[position - 1] == INT_MIN) {
    printf("> The value is empty\n");
  } else {
    printf("> Delete value %d at position %d\n", arr[position - 1], position);
    arr[position - 1] = INT_MIN;
  }
}

void sortArrAsc(int *arr, size_t arr_size) {
  if (arr == NULL) {
    printf("> Array is empty\n");
    return;
  }

  qsort(arr, arr_size, sizeof(int), ascCompare);
  printf("> Array sorted in ascending order\n");
}

void sortArrDesc(int *arr, size_t arr_size) {
  if (arr == NULL) {
    printf("> Array is empty\n");
    return;
  }

  qsort(arr, arr_size, sizeof(int), descCompare);
  printf("> Array sorted in descending order\n");
}

void findElementArr(int *arr, size_t arr_size) {
  if (arr == NULL) {
    printf("Array is empty\n");
    return;
  }

  int value;
  printf("Value: ");
  scanf("%d", &value);

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] == value) {
      printf("> Value %d found at position %d\n", value, i + 1);
      return;
    }
  }
  printf("> Value %d not found\n", value);
}