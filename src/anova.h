#ifndef ANOVA_H
#define ANOVA_H

typedef struct {

    double* data;
    int count;
    char* name;

} GROUP;

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

} ANOVA;

ANOVA anova(GROUP** groups, int groups_count);
void printAnova(ANOVA anova);

#endif
