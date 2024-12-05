
#include <stdio.h>
#include <time.h>

#define ITERATIONS 1000000000

void regular_int_counter() {
  int i;
  for (i = 0; i < ITERATIONS; i++) {
  }
}

void register_int_counter() {
  register int i;
  for (i = 0; i < ITERATIONS; i++) {
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  // Measure time for regular int counter
  start = clock();
  regular_int_counter();
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Regular int counter: %f seconds\n", cpu_time_used);

  // Measure time for register int counter
  start = clock();
  register_int_counter();
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Register int counter: %f seconds\n", cpu_time_used);

  return 0;
}
