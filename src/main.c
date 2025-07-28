#include <stdio.h>
int main(void)
{
    int method1[5] = { 48, 73, 51, 65, 87 };
    int method2[5] = { 55, 85, 70, 69, 90 };
    int method3[5] = { 84, 68, 95, 74, 61 };

    int n1 = 5, n2 = 5, n3 = 5;
    int n = n1 + n2 + n3;
    
    int sum1 = sum(method1, n1);
    int sum2 = sum(method2, n2);
    int sum3 = sum(method3, n3);

    int sumX = sum2(sum1, sum2, sum3);

    int sumsq = sumSQ()

}
