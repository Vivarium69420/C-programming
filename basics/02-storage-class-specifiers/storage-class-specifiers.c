
/* storage-class-specifiers.c */
#include <stdio.h>
#include <stdlib.h>

#include "external-variable.h"

void increment() {
  static int static_increment = 0;
  auto int auto_increment = 0;
  printf("static_increment: %d\n", static_increment++);
  printf("auto_increment:   %d\n", auto_increment++);
}

int main(void) {
  if (1) {
    auto int auto_main = 10;
    printf("auto_main: %d\n", auto_main);
  }
  // printf("Inside main - auto_main: %d\n", auto_main); // Undeclared
  // identifier

  printf("External_variable: %d\n", external_variable);

  increment();
  increment();
  increment();

  return EXIT_SUCCESS;
}
