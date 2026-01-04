/*
Write a program that asks the user to enter a two-digit number, then prints the number with
its digits reversed. A session with thc program should have thc following appearance:
E nter a tw o-digit number: 28
The rev ersal is: 82
Read the number using %d, then break it into two digits. 
Hint: Ifn is an integer, then n % 10
is the last digit in n and n / 10 is n with thc last digit removed.
*/

#include <stdio.h>

int main(void)
{
    int fDigit, lDigit, flDigit;

    printf("Enter a two-digit number: ");
    scanf("%d", &flDigit);

    lDigit = flDigit % 10;
    flDigit = flDigit / 10;
    fDigit = flDigit % 10;
    flDigit = flDigit / 10;

    printf("\nThe reversal is: %d%d", lDigit, fDigit);

    return 0;
}