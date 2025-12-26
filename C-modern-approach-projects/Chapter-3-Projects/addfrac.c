/*
Modify the a d d fra c . c program of Section 3.2 so that the uscr enters both fractions at the
same time, separated by a plus sign:
E nter two fra c tio n s separated by a plus sign: 5/64+3/4
The sum is 38/24
*/

/* addfraction.c Adds two fractions */
#include <stdio.h>

int main(void)
{
    int numl, denom1, num2, denom2, result_num, result_denom;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d + %d/%d", &numl, &denom1, &num2, &denom2);
    result_num = numl * denom2 + num2 * denom1;

    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);
    return 0;
}
