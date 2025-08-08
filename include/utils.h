#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>

double sum(const double* array, size_t array_size);
double mean(const double* array, size_t array_size);
double varience(const double* array, size_t array_size);
double sumsq(const double* array, size_t array_size);
char* string_alloc(const char* string);
double p_value(double F_statistic, int df1, int df2);
#endif
