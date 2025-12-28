/*
Extend the program in Programming Project 1 to handle three-digit numbers.
*/
#include <stdio.h>

int main(void)
{
    int fDigit, lDigit, mDigit;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &fDigit, &mDigit, &lDigit);
    printf("\nThe reversal is: %d%d%d", lDigit, mDigit ,fDigit);

    return 0;
}