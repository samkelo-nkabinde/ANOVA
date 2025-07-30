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
    double p_value = 0 ;

    anova = (Anova){
        ss_between, ss_within, ss_total,
        df_between, df_within, df_total,
        ms_between, ms_within,
        f_statistic, 0.0
    };
    return anova;
}

void display_anova(Anova anova , group_t* group_array, int num_of_groups)
{
    char line[] = "_________________________________________________________________________";
    printf("%s\n", "Anova: Single Factor");
    printf("%s\n", "SUMMARY");
    printf("%s\n",line);
    printf("%s\t%s\t%s\t%s\t%s\n","Groups", "Count", "Sum", "Average", "Varience");
    for(size_t i = 0; i < num_of_groups; ++i)
    {
        printf("%s\t%d\t%.3lf\t%.3lf\t%.3lf\n",group_array[i]->name, group_array[i]->count, group_array[i]->sum, group_array[i]->average, group_array[i]->varience);
    }
}

