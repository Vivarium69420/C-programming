#include <stdio.h>
#include <stdlib.h>

#include "external-variable.h"

static int c_static_global = 30;  // Static, global, within block

void testLifeTime() {
  auto int a_auto_func = 20;  // Different scope
  printf("a_auto_func: %d\n", a_auto_func);
  c_static_global = 40;
}

int main(void) {
  auto int a_auto_main = 10;  // Default, automatic, stack, within block
  register int b =
      20;  // Accessed frequently, automatic, CPU register, within block
  printf("a_auto_main: %d\n", a_auto_main);
  printf("c_static_main: %d\n", c_static_global);
  testLifeTime();
  printf("c_static_main: %d\n", c_static_global);

  printf("external_variable: %d\n", external_variable);

  // int *ptr = &b;  // Error: address of register variable 'b' requested
  return EXIT_SUCCESS;
}
