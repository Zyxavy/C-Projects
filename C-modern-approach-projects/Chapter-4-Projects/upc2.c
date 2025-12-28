/*
Rewrite the u p c . c program of Section 4.1 so that the user enters 11 digits at one time,
instead of entering one digit, then five digits, and then another five digits.
E nter the f ir s t 11 d ig its of a UPC: 01380015173
Check d ig it: 5
*/

#include <stdio.h>

int main(void)
{
    int firstSum, secondSum, checkDigit;
    int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
         &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11 );

    firstSum = d1 + d3 + d5 + d7 + d9+ d11;
    secondSum = d2 + d4 + d6 + d8+ d10;
    
    firstSum *= 3;
    int total = secondSum += firstSum;
    total -= 1;
    int rtotal = total % 10;
    checkDigit = 9 - rtotal;

    printf("Check digit: %d", checkDigit);

    return 0;
}

