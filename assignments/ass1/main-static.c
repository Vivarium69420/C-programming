#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arr = NULL;
size_t arr_size = 0;

int ascCompare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int descCompare(const void *a, const void *b) {
  return (*(int *)b - *(int *)a);
}

int getStatus() {
  char input[MAX_INPUT];
  int status;
  char *endptr;

  while (1) {
    printf("Status (1: Continue, 0: Exit): ");
    if (scanf("%99s", input) != 1) {
      printf("ERROR: Invalid input. Please enter 0 or 1.\n");
      continue;
    }

    // Convert input to integer
    status = strtol(input, &endptr, 10);

    // Check if the input is a valid integer and within the expected range
    if (*endptr == '\0' && (status == 0 || status == 1))
      break;
    else
      printf("ERROR: Invalid input. Please enter 0 or 1.\n");
  }

  return status;
}

void createArr() {
  // If the array is not empty, create a new array
  if (arr != NULL) free(arr);

  printf("Enter the size of the array: ");
  scanf("%zd", &arr_size);

  arr = (int *)malloc(arr_size * sizeof(int));
  if (!arr) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  printf("Array created successfully with size of %lu\n", arr_size);
}

void printArr() {
  register size_t idx_arr;

  if (arr == NULL) {
    printf("Array is empty\n");
    exit(EXIT_SUCCESS);
  }

  printf("[");
  for (idx_arr = 0; idx_arr < arr_size - 1; idx_arr++) {
    printf("%d, ", arr[idx_arr]);
  }
  printf("%d]\n", arr[idx_arr]);
};

void insert() {
  if (arr == NULL) {
    printf("Array is empty\n");
    exit(EXIT_SUCCESS);
  }

  int value;
  int position;
  int isContinue;

  printf("Insert mode\n");
  printf("Value: ");
  scanf("%d", &value);
  printf("Position: ");
  scanf("%d", &position);

  while (position < 0 || position > arr_size) {
    printf("Error: Invalid position, please try again.\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("Position: ");
    scanf("%d", &position);
  }
  arr[position - 1] = value;
  printf("Value %d inserted at position %d\n", value, position);
};

void delete() {
  if (arr == NULL) {
    printf("Array is empty\n");
    exit(EXIT_SUCCESS);
  }
  int position;
  int isContinue;

  printf("Position: ");
  scanf("%d", &position);

  while (position < 0 || position > arr_size) {
    printf("Error: Invalid position, please try again.\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("Position: ");
    scanf("%d", &position);
  }

  if (arr[position - 1] == 0)
    printf("The value is 0 and considered as empty");
  else {
    printf("Delete value %d at position %d", arr[position - 1], position);
    arr[position - 1] = 0;
  }
};
void sortAsc() { qsort(arr, arr_size, sizeof(int), ascCompare); };
void sortDesc() { qsort(arr, arr_size, sizeof(int), descCompare); };
void find() {
  int value;
  int isContinue;

  printf("Value: ");
  scanf("%d", &value);

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] == value) {
      printf("Value %d found at position %d\n", value, i + 1);
      return;
    }
  }
  printf("Value %d not found\n", value);
}

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
  printf("   e,  quit\n");
}

char getUserCommand() {
  showOptions();
  int isContinue;
  char user_input[MAX_INPUT];

  printf("Options: ");
  scanf("%s", user_input);

  while (strlen(user_input) > 1) {
    printf("ERROR: Invalid input, please try again\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("Options: ");
    scanf("%s", user_input);
  }

  char user_option = user_input[0];

  while (user_option < 'a' || user_option > 'z') {
    printf("ERROR: Invalid input, please try again\n");
    isContinue = getStatus();
    if (!isContinue) {
      exit(EXIT_SUCCESS);
    }
    printf("Options: ");
    scanf("%s", user_input);
    user_option = user_input[0];
  }

  return user_option;
}

int main(void) {
  printf("----------------------------------\n");
  printf("Welcome to the Array CLI Manager\n");
  printf("----------------------------------\n");

  char user_command;
  while (1) {
    user_command = getUserCommand();
    switch (user_command) {
      case 'c':
        createArr();
        printf("----------------------------------\n");
        break;

      case 'p':
        printArr();
        printf("----------------------------------\n");
        break;

      case 'i':
        insert();
        printf("----------------------------------\n");
        break;

      case 'd':
        delete ();
        printf("----------------------------------\n");
        break;

      case 's':
        sortAsc();
        printf("----------------------------------\n");
        break;

      case 'x':
        sortDesc();
        printf("----------------------------------\n");
        break;

      case 't':
        find();
        printf("----------------------------------\n");
        break;

      case 'e':
        printf("Exiting the program\n");
        if (arr != NULL) free(arr);
        exit(EXIT_SUCCESS);

      default:
        printf("Invalid command\n");
    }
  }
  return EXIT_SUCCESS;
}
