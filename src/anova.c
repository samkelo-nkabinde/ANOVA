#include "anova.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

Anova avova_test( group_t* group_array, int num_of_groups )
{
    Anova anova = {0};
    int total_obsevations = 0;
    double grand_sum = 0.0;
    double grand_sum_of_squres = 0.0;
    double group_sums[num_of_groups];

    for(size_t i = 0; i < num_of_groups; ++i)
    {
        total_obsevations += group_array[i] -> count;
        grand_sum += sum(group_array[i] -> data, group_array[i] -> count);
        grand_sum_of_squres += sumsq(group_array[i]->data, group_array[i] -> count);
        group_sums[i] = sum(group_array[i] -> data, group_array[i] -> count);
    }

    double ss_between = 0.0;
    double ss_within = 0.0;
    double ss_total = 0.0;

    for(size_t i = 0; i < num_of_groups; ++i)
    {
        ss_between += (group_sums[i] * group_sums[i]) / group_array[i]->count;
    }

    ss_within = grand_sum_of_squres - ss_between;
    ss_between = ss_between - ((grand_sum * grand_sum) / total_obsevations);
    ss_total = ss_within + ss_between;

    int df_between = num_of_groups - 1;
    int df_within = total_obsevations - num_of_groups;
    int df_total = df_between + df_within;


    double ms_between = ss_between / df_between; // Mean Square Between Groups
    double ms_within = ss_within / df_within;  // Mean Square Within Groups

    double f_statistic = ms_between / ms_within; // F-statistic
    double p_value = 0 ;

    anova = (Anova){ss_between , ss_within, ss_total, df_between, df_within, df_total, ms_between, ms_within, f_statistic, p_value};
    return anova;
}

void print_anova(Anova anova)
{
    printf("%s\n","Working");
}

