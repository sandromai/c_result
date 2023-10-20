#include <stdio.h>

#include "result.h"

typedef RESULT(int) int_result;

int_result test_int(const int value) {
  if (value > 0) {
    return (int_result){value, NULL};
  }

  return (int_result){0, "Int error."};
}

int main(void) {
  int_result result_int_success = test_int(10);

  if (result_int_success.error != NULL) {
    printf("Result error: %s\n", result_int_success.error);
  } else {
    printf("Result data: %d\n", result_int_success.data);
  }

  int_result result_int_error = test_int(-10);

  if (result_int_error.error != NULL) {
    printf("Result error: %s\n", result_int_error.error);
  } else {
    printf("Result data: %d\n", result_int_error.data);
  }

  return 0;
}
