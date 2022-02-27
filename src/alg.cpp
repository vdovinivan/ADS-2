// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 1) {
    return value;
  } else if (n == 0) {
    return 1;
  }
  return value * pown(value, --n);
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 0, n = 0; i <= count; ++i, ++n) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1, n = 1; i <= count; ++i, ++n) {
    sum += pown(-1, n - 1) * calcItem(x, 2 * n - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1, n = 1; i <= count; ++i, ++n) {
    sum += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
  }
  return sum;
