/*
Rewrite the program in Programming Project 2 so that it prints thc reversal of a three-digit
number without using ariUimetic to split the number into digits. Hint: See the upc . c pro
gram of Section 4.1.
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