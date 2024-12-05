#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arr_ops.h"

#define MAX_INPUT 100

void showOptions() {
  printf("Please choose a command:\n");
  printf("OPTIONS\n");
  printf("   c,  create new (if existed clear old one)\n");
  printf("   p,  print the array\n");
  printf("   i,  insert element x in position k\n");
  printf("   d,  delete element x in position k\n");
  printf("   s,  sort in ascending order\n");
  printf("   x,  sort in descending order\n");
  printf("   t,  find element x\n");
  printf("   h,  show options\n");
  printf("   e,  quit\n");
}

char getUserCommand() {
  int isContinue;
  char user_input[MAX_INPUT];

  printf("[?] Options: ");
  scanf("%s", user_input);

  while (strlen(user_input) > 1) {
    printf("> ERROR: Invalid input, please try again\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("[?] Options: ");
    scanf("%s", user_input);
  }

  char user_option = user_input[0];

  while (user_option < 'a' || user_option > 'z') {
    printf("[!] ERROR: Invalid input, please try again\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("[?] Options: ");
    scanf("%s", user_input);
    user_option = user_input[0];
  }

  return user_option;
}

int main(void) {
  printf("----------------------------------\n");
  printf("Welcome to the Array CLI Manager\n");
  printf("----------------------------------\n");
  showOptions();

  // Initialize the array
  int *arr = NULL;
  size_t arr_size = 0;

  // Start the program
  char user_command;
  while (1) {
    user_command = getUserCommand();
    switch (user_command) {
      case 'c':
        createArr(&arr, &arr_size);
        printf("----------------------------------------------\n");
        break;

      case 'p':
        printArr(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 'i':
        insertArr(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 'd':
        deleteArr(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 's':
        sortArrAsc(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 'x':
        sortArrDesc(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 't':
        findElementArr(arr, arr_size);
        printf("----------------------------------------------\n");
        break;

      case 'h':
        showOptions();
        printf("----------------------------------------------\n");
        break;

      case 'e':
        printf("Exiting the program\n");
        if (arr != NULL) {
          free(arr);
        }
        exit(EXIT_SUCCESS);
    }
  }

  return EXIT_SUCCESS;
}