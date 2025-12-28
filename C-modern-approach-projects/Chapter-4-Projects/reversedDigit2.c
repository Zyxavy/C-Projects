/*
Extend the program in Programming Project 1 to handle three-digit numbers.
*/
#include <stdio.h>

int main(void)
{
    int fDigit, lDigit, mDigit, flDigit;

    printf("Enter a three-digit number: ");
    scanf("%d", &flDigit);

    lDigit = flDigit % 10;
    flDigit = flDigit / 10;

    mDigit = flDigit % 10;
    flDigit = flDigit / 10;

    fDigit = flDigit % 10;
    flDigit = flDigit / 10;

    printf("\nThe reversal is: %d%d%d", lDigit, mDigit, fDigit);

    return 0;
}