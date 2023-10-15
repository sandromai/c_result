#include <stdio.h>

#include "result.h"

typedef enum Err {
  NONE,
  ERR
} Err;

typedef Result(const Err, const int) int_result;
typedef Result(const Err, const float) float_result;

int_result test_int(const int value) {
  return (int_result){NONE, value};
}

float_result test_float(const float value) {
  return (float_result){ERR, value};
}

int main(void) {
  int_result result_int = test_int(-1);

  if (result_int.error != NONE) {
    printf("result_int error: %d\n", result_int.error);
  } else {
    printf("result_int data: %d\n", result_int.data);
  }

  float_result result_float = test_float(0.1988);

  if (result_float.error != NONE) {
    printf("result_float error: %d\n", result_float.error);
  } else {
    printf("result_float data: %f\n", result_float.data);
  }

  return 0;
}
