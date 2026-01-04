/*
The value of the mathematical constant
e can be expressed as an infinite series:
e = 1 4- 1/11+ 1/2! 4- 1/3! 4-...
Write a program that approximates e by computing the value of
14- 1/114- 1/2! 4- 1/3! 4- ... + l/n!
where n is an integer entered by the user.
*/

#include <stdio.h>

int factIter(int product, int counter, int maxCount)
{
    if(counter > maxCount) return product;
    else
    {
        return factIter((counter * product), (counter + 1), maxCount);
    }
}

int factorial(int n)
{
    return factIter(1, 1, n);
}

int main(void)
{
    int n;
    double e = 1.0L;
    printf("Enter n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        double num = 1.0 / (factorial(i));
        e += num;
    }
    printf("e = %.40lf", e);

    return 0;
}


//TTC: 27:48
