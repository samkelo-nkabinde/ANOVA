#include "anova.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Anova avova_test( groupPtr* group_array, size_t num_of_groups )
{
    Anova anova = {0};

    int total_obsevations = 0;
    double grand_sum = 0.0;
    double grand_sum_of_squres = 0.0;
    double ss_between = 0.0;
    double ss_within = 0.0;
    double ss_total = 0.0;

    for(size_t i = 0; i < num_of_groups; ++i)
    {
        total_obsevations += group_array[i] -> count;
        grand_sum += group_array[i] -> sum;
        grand_sum_of_squres += sumsq(group_array[i] -> data, group_array[i] -> count);
        ss_between += (group_array[i] -> sum * group_array[i] -> sum) / group_array[i] -> count;
    }

    ss_within = grand_sum_of_squres - ss_between;
    ss_between = ss_between - ((grand_sum * grand_sum) / total_obsevations);
    ss_total = ss_within + ss_between;

    int df_between = num_of_groups - 1;
    int df_within = total_obsevations - num_of_groups;
    int df_total = df_between + df_within;

    double ms_between = ss_between / df_between;
    double ms_within = ss_within / df_within;

    double f_statistic = ms_between / ms_within;
    double P_value = p_value(f_statistic, df_between, df_within);

    anova = (Anova){
        ss_between, ss_within, ss_total,
        df_between, df_within, df_total,
        ms_between, ms_within,
        f_statistic, P_value
    };
    return anova;
}

void display_anova(Anova anova , groupPtr* group_array, size_t num_of_groups)
{

    printf("%s\n\n", "Anova: Single Factor");
    printf("\x1b[4m");
    printf("%s%s\n", "SUMMARY","                                                ");
    printf("%s\t%s\t%s\t%s\t%s\n","Groups", "Count", "Sum", "Average", "Varience");
    printf("\x1b[0m");
    for(size_t i = 0; i < num_of_groups; ++i)
    {
        printf("%s\t%d\t%.3lf\t%.3lf\t%.3lf\n",group_array[i]->name, group_array[i]->count, group_array[i]->sum, group_array[i]->average, group_array[i]->varience);
    }
    printf("%lf\n",anova.p_value);
    printf("%lf\n",anova.F_statistic);
}

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <math.h>

#define EPSILON 1e-6

double sum(const double* array, size_t array_size)
{
    double sum_result = 0.0;
    for(size_t i = 0; i < array_size; ++i) sum_result += array[i];
    return sum_result;
}

double sumsq(const double* array, size_t array_size)
{
    double sum_squre_result = 0.0;
    for(size_t i = 0; i < array_size; ++i) sum_squre_result += array[i] * array[i];
    return sum_squre_result;
}

double mean(const double* array, size_t array_size)
{
    return sum(array,array_size)/(double)array_size;
}

double varience(const double* array, size_t array_size)
{
    double average = mean(array, array_size);
    double result = 0.0;
    for(size_t i = 0; i < array_size; ++i)
    {
        result += pow((array[i] - average), 2);
    }

    return result / (double)array_size;
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

static double f_of_t(double t, double a, double b)
{
    return (pow(t, a - 1) * pow(1 - t, b - 1));
}

static double simpson(double lower_limit, double upper_limit, double n, double a, double b)
{
    double h = (upper_limit - lower_limit) / n;
    double t = lower_limit;
    double sum = 0.0;

    sum = f_of_t(lower_limit, a, b) + f_of_t(upper_limit, a, b);

    for( int i = 0; i < (n - 1); ++i)
    {
        t += h;

        if( i % 2 == 0 )
        {
            sum += 4 * f_of_t(t, a, b);
        }
        else
        {
            sum += 2 * f_of_t(t, a, b);
        }
    }

    return sum * (h / 3.0);
}

static double integrate(double lower_limit, double upper_limit, double a, double b)
{
    double n = 4;
    double integral;
    double new_integral = simpson(lower_limit, upper_limit, n, a, b);

    do
    {
        integral = new_integral;
        n *= 2;
        new_integral = simpson(lower_limit, upper_limit, n, a, b);
    }
    while( fabs(integral - new_integral) >= EPSILON);

    return new_integral;
}


static double beta(double a, double b)
{
    return (tgamma(a) * tgamma(b)) / (tgamma(a + b));
}

static double I_z(double a, double b, double z)
{
    return (integrate(0, z, a, b) / (double)beta(a, b));
}

double p_value(double F_statistic, int df1, int df2)
{
    double z = (df1 * F_statistic) / (df1 * F_statistic + df2);

    double a = (double)(df1 / 2);
    double b = (double)(df2 / 2);

    return 1 - I_z(a, b, z);
}

