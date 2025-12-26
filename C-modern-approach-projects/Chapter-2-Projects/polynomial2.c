#include <stdio.h>

/*
Modify the program of Programming Project 5 so that the polynomial is evaluated using the
following formula:
((((3x + 2)x-5)x-1)x + 7).v-6
Note that the modified program performs fewer multiplications. This technique for evaluat
ing polynomials is known as Horner’s Rule.
*/

int main(void)
{
    int x, polyVal;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("The value of the Polynomial: 3.x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 is:\n");
    printf("3(%d)^5 + 2(%d)^4 - 5(%d)^3 - (%d)^2 + 7(%d) - 6\n", x,x,x,x,x);

    polyVal = ((((3*x + 2) * x-5 ) * x-1 ) * x + 7 ) * x-6;

    printf("%d", polyVal);

    return 0;
}