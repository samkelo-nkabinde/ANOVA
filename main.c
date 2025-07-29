#include "groups.h"
#include "anova.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    group_t* groups = (group_t*)malloc(sizeof(group_t)*3);
    double method1[5] = {48, 73, 51, 65, 87};
    double method2[5] = {55, 85, 70, 69, 90};
    double method3[5] = {84, 68, 95, 74, 67};
    printf("Part 1 runs!\n");
    groups[0] = set_group(method1, 5, "Methode 1");
    groups[1] = set_group(method2, 5, "Methode 2");
    groups[2] = set_group(method3, 5, "Methode 3");
    printf("Part 2 runs!\n");
    Anova anova1 = avova_test(groups, 3);
    printf("ss_between: %lf\n",anova1.SS_between);
    printf("f-static: %lf\n",anova1.F_statistic);
}
