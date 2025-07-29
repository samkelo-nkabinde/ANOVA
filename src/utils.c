#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>

double sum(const double* array, size_t array_size)
{
    double sum_result = 0.0;
    for(size_t i = 0; i < array_size; ++i) sum_result += array[i];
    return sum_result;
}
double sumsq(const double* array, int array_size)
{
    double sum_squre_result = 0.0;
    for(size_t i = 0; i < array_size; ++i) sum_squre_result += array[i] * array[i];
    return sum_squre_result;
}
char* string_alloc(const char* string)
{
    if (string == NULL) {
        return NULL;
    }
    char* new_string = (char*)malloc(strlen(string) + 1);
    if (new_string == NULL) {
        fprintf(stderr, "Memory allocation failed for string duplication!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_string, string);
    return new_string;
}
double p_value(double F_statistic, int df1, int df2)
{
    return 0.0;
}
