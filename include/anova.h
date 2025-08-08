#ifndef ANOVA_H
#define ANOVA_H
#include "groups.h"
#include <stdlib.h>

typedef struct {

    double SS_between; // Sum of Squares Between Groups
    double SS_within;  // Sum of Squares Within Groups
    double SS_total;   // Total Sum of Squares

    int df_between;    // Degrees of Freedom Between Groups
    int df_within;     // Degrees of Freedom Within Groups
    int df_total;      // Total Degrees of Freedom

    double MS_between; // Mean Square Between Groups
    double MS_within;  // Mean Square Within Groups

    double F_statistic; // F-statistic
    double p_value;    // P-value

} Anova;


Anova avova_test( groupPtr* group_array, size_t num_of_groups );
void display_anova(Anova anova , groupPtr* group_array, size_t num_of_groups);
#endif
