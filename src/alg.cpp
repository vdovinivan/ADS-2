// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 1) {
        return value;
    }
    return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    double y = 0;
    y = pown(x, n) / fact(n);
    return y;
}

double expn(double x, uint16_t count) {
    double sum = 0;
    while (count != 0) {
        sum = sum + calcItem(x, count);
        count--;
    }
    sum += 1;
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0;
    while (count != 1) {
        sum = sum + pown(-1, count - 1) * calcItem(x, 2 * count - 1);
        count--;
    }
    sum += x;
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0;
    while (count != 1) {
        sum = sum + pown(-1, count - 1) * calcItem(x, 2 * count - 2);
        count--;
    }
    sum += 1;
    return sum;	 
}
