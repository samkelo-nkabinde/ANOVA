#include "groups.h"
#include "anova.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    groupPtr* groups = (groupPtr*)malloc(sizeof(groupPtr)*3);
    double method1[5] = {48, 73, 51, 65, 87};
    double method2[5] = {55, 85, 70, 69, 90};
    double method3[5] = {84, 68, 95, 74, 67};
    groups[0] = create_group(method1, 5, "Methode 1");
    groups[1] = create_group(method2, 5, "Methode 2");
    groups[2] = create_group(method3, 5, "Methode 3");
    Anova anova = avova_test(groups,3);
    display_anova(anova, groups, 3);
}
