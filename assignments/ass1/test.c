#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <limits.h>
#include <stdlib.h>

#include "arr_ops.h"

void test_createArr(void) {
  int *arr = NULL;
  size_t arr_size = 0;
  createArr(&arr, &arr_size);
  CU_ASSERT_PTR_NOT_NULL(arr);
  CU_ASSERT_EQUAL(arr_size, 0);
  free(arr);
}

void test_insertArr(void) {
  int arr[5] = {INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN};
  insertArr(arr, 5);
  CU_ASSERT_NOT_EQUAL(arr[0], INT_MIN);
}

void test_deleteArr(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  deleteArr(arr, 5);
  CU_ASSERT_EQUAL(arr[0], INT_MIN);
}

void test_sortArrAsc(void) {
  int arr[5] = {5, 3, 4, 1, 2};
  sortArrAsc(arr, 5);
  for (int i = 0; i < 4; i++) {
    CU_ASSERT_TRUE(arr[i] <= arr[i + 1]);
  }
}

void test_sortArrDesc(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  sortArrDesc(arr, 5);
  for (int i = 0; i < 4; i++) {
    CU_ASSERT_TRUE(arr[i] >= arr[i + 1]);
  }
}

void test_findElementArr(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  findElementArr(arr, 5);
  CU_ASSERT_EQUAL(arr[0], 1);
}

int main() {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("arr_ops_test_suite", 0, 0);

  CU_add_test(suite, "test_createArr", test_createArr);
  CU_add_test(suite, "test_insertArr", test_insertArr);
  CU_add_test(suite, "test_deleteArr", test_deleteArr);
  CU_add_test(suite, "test_sortArrAsc", test_sortArrAsc);
  CU_add_test(suite, "test_sortArrDesc", test_sortArrDesc);
  CU_add_test(suite, "test_findElementArr", test_findElementArr);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}