#include "anova.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

ANOVA singleFactorAnova( GROUP** groups, int groups_count )
{
    ANOVA anova = {0};

    int N = 0; //total number of observations in the groups
    double groups_sum[groups_count]; //total number of observations in the groups
    double sumX = 0.0; //
    double sumXsq = 0.0;
    double ss_between = 0.0;
    double ss_within = 0.0;
    double ss_total;
    for(size_t i = 0; i < groups_count; ++i)
    {
        N += groups[i] -> count;
        groups_sum[i] = sum(groups[i]->data, groups[i] -> count);
        sumX += groups_sum[i];
        sumXsq += pow(groups_sum[i], 2);
        ss_between += pow(groups_sum[i], 2) / groups[i] -> count;
    }

    ss_within = sumXsq - ss_between;
    ss_between = ss_between - (pow(sumX,2)/N)

    ss_total = ss_within + ss_between;

    int df_between = groups_count - 1;
    int df_within = N - groups_count;
    int df_total = df_between + df_within;

    double MS_between = ss_between / df_between; // Mean Square Between Groups
    double MS_within = df_within / ss_within;

    double F_statistic = MS_between / MS_within;


}
void printAnova(ANOVA anova);

