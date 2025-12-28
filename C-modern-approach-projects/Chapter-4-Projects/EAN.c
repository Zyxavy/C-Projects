/*
European countries use a 13-digit code, known as a European Article Number (EAN)
instead of the 12-digil Universal Product Code (UPC) found in North America. Each EAN
ends with a check digil, just as a UPC does. The technique for calculating the check digit is
also similar:

    Add the second, fourth, sixth,’  eig o hth,’  tenth,w  and twelfth dig cits.
    Add the first, third, fifth, seventh, ninth, and eleventh digits.
    Multiply the first sum by 3 and add it to the second sum.
    Subtract 1 from the total.
    Compute the remainder when the adjusted total is divided by 10.
    Subtract the remainder from 9

Forexample, consider GiiIliioglu Turkish Delight Pistachio & Coconut, which has an EAN
of 8691484260008. The first sum is 6 4- 1 4- 8 + 2 + 0 4- 0 = 17. and the second sum is 8 4- 9 4
4 4- 4 4- 6 4- 0 = 31. Multiplying the first sum by 3 and adding the second yields 82. Subtract
ing 1 gives 81. The remainder upon dividing by 10 is I. When the remainder is subtracted
from 9, the result is 8, which matches the last digit ofthe original code. Yourjob is to mod
ify the upc . c program of Section 4.1 so that it calculates the check digit for an EAN. The
user will enter the first 12 dio g its of the EAN as a sing ole number:k

Enter the first 12 digits of an EAN: 869148426000
Check digit: 8

*/

#include <stdio.h>

int main(void)
{
    int firstSum, secondSum, checkDigit;
    int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
         &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);

    firstSum = d2 + d4 + d6 + d8+ d10 + d12;
    secondSum = d1 + d3 + d5 + d7 + d9+ d11;
    
    firstSum *= 3;
    int total = secondSum += firstSum;
    total -= 1;
    int rtotal = total % 10;
    checkDigit = 9 - rtotal;

    printf("Check digit: %d", checkDigit);

    return 0;
}