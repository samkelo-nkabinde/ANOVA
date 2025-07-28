#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

double sum(const double* array, size_t array_size)
{
    double SUM = 0.0;
    for(size_t i = 0; i < array_size; ++i) SUM += array[i];
    return SUM;
}
double sumsq(const double* array, int array_size)
{
    double SUMSQ = 0.0;
    for(size_t i = 0; i < array_size; ++i) SUMSQ += array[i] * array[i];
    return SUMSQ;
}
typedef struct {

    double* data;
    int count;

} GROUP;
int main()
{
    int size = 5;
    double array[size];
    for(int i = 0; i <size; i++) array[i] = i;
    GROUP groups[size];
    for(int i = 0; i < size; i++)
    {
        groups[i].count = i;
        printf("%d\n", groups[i].count);
    }
    printf("%lf\n",sum(array, 5));
    printf("%lf\n",sumsq(array, 5));
}
