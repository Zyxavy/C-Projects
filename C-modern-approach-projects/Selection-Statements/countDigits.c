/*
Write a program that calculates how many digits a number contains:
Enter a number: 374
The number 374 has 3 digits
You may assume that the number has no more than four digits. Hint: Use i f statements to
test the number. For example, if the number is between 0 and 9, it has one digit. If the num
ber is between 10 and 99, it has two digits
*/

#include <stdio.h>

int main(void)
{
    int digit;

    printf("Enter a number: ");
    scanf("%d", &digit);
    printf("The number %d has %d digits.", digit, digit > 0 && digit < 10 ? 1 : digit > 10 && digit < 99 ? 2 : digit > 100 && digit < 999 ? 3 : 4);
    
    return 0;
}