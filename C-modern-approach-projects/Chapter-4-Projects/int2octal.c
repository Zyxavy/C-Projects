/*
Write a program that reads an integer entered by the user and displays it in octal (base 8):
E nter a number between 0 and 32767: 1953
' I n o c ta l, your number is: 03641
Thc output should be displayed using five digits, even if fewer digits are sufficient. Hint: To
convert the number to octal, first divide it by 8; the remainder is the last digit of the octal
number (1, in this case). Then divide the original number by 8 and repeat the process to
arrive at the nexl-to-last digit, ( p r in tf is capable of displaying numbers in base 8, as we’ll
see in Chapter 7, so there’s actually an easier way to write this program.)
*/

#include <stdio.h>

int main(void)
{
    int base10, r1,r2,r3,r4,r5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &base10);

    
    r1 = base10 % 8;
    base10 /= 8;
    printf("r1: %d | base10: %d\n", r1, base10);

    r2 = base10 % 8;
    base10 /= 8;
    printf("r1: %d | base10: %d\n", r2, base10);

    r3 = base10 % 8;
    base10 /= 8;
    printf("r1: %d | base10: %d\n", r3, base10);

    r4 = base10 % 8;
    base10 /= 8;
    printf("r1: %d | base10: %d\n", r4, base10);

    r5 = base10 % 8;
    base10 /= 8;
    printf("r1: %d | base10: %d\n", r5, base10);


    printf("Octal form: %d%d%d%d%d", r5,r4,r3,r2,r1);
    

    return 0;
}