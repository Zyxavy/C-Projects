/*
Write a program that asks the user to enter a fraction, then reduces the fraction to lowest
terms:
Enter a fraction: 6/12
In lowest terms: 1/2
Hint: To reduce a fraction to lowest terms, first compute the GCD of the numerator and
denominator. Then divide both the numerator and denominator by the GCD.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    int m, n;
    int denom, nume;

    printf("Enter a fraction: ");
    scanf("%d / %d", &m, &n);

    nume = m;
    denom = n;

    while(n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    nume = nume / m;
    denom = denom / m;

    printf("Lowest terms: %d/%d", nume, denom);
    
    return 0;
}

// TTC: 11:18