#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Variable declaration, definition and initialization */
  int something;   // This is a variable declaration or definition
  something = 10;  // This is a variable assignment or initialization

  /* Basic types */
  char ch = 'a';
  short shortInt = -120;
  unsigned short unsignedShortInt = 120;
  int integer = -123456789;
  unsigned int unsignedInteger = 123456789;
  long veryLongInteger = 91283764378293847;
  long long veryVeryLongInterger = 1234565432345675113;
  float fly = 123.23;
  double toInfinityAndBeyond = 1231241.123123;
  long double milkyWay = 1231231323.1231241;

  printf("char:            %c  - %-2lu bytes\n", ch, sizeof(ch));
  printf("short:           %d  - %-2lu bytes\n", shortInt, sizeof(shortInt));
  printf("unsigned short:  %d  - %-2lu bytes\n", unsignedShortInt,
         sizeof(unsignedShortInt));
  printf("int:             %d  - %-2lu bytes\n", integer, sizeof(integer));
  printf("unsigned int:    %d  - %-2lu bytes\n", unsignedInteger,
         sizeof(unsignedInteger));
  printf("long:            %ld - %-2lu bytes\n", veryLongInteger,
         sizeof(veryLongInteger));
  printf("long long:       %lld - %-2lu bytes\n", veryVeryLongInterger,
         sizeof(veryVeryLongInterger));
  printf("float:           %f  - %-2lu bytes\n", fly, sizeof(fly));
  printf("double:          %lf - %-2lu bytes\n", toInfinityAndBeyond,
         sizeof(toInfinityAndBeyond));
  printf("long double:     %Lf - %-2lu bytes\n", milkyWay, sizeof(milkyWay));

  return EXIT_SUCCESS;
}
