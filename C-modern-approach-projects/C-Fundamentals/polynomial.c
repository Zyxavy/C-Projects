#include <stdio.h>

/*
Write a program that asks the user to enter a value for x and then displays the value of the
following polynomial:
3.v5 + 2x4 - 5.v3 - x2 + 7r - 6
Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply .v by itself
repeatedly in order lo compute the powers ofi. (For example, x * x * x is x cubed.
*/

int main(void)
{
    int x, polyVal;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("The value of the Polynomial: 3.x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 is:\n");
    printf("3(%d)^5 + 2(%d)^4 - 5(%d)^3 - (%d)^2 + 7(%d) - 6\n", x,x,x,x,x);

    polyVal = 3 * (x*x*x*x*x) + 2 * (x*x*x*x) - 5 * (x*x*x) - (x*x) + 7 * (x) - 6 ;

    printf("%d", polyVal);

    return 0;
}