#include <stdio.h>

/*
Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
that amount using the smallest number ofS20, $10, $5, and $1 bills:
Enter a dollar amount: 93
$20 bills: 4
$10 bills: 1
$5 bills: 0
$1 bills: 3
Hint:
Divide the amount by 20 to determine the number of$20 bills needed, and then reduce
the amount by the total value of the $20 bills. Repeat for the other bill sizes. Be sure to use
integer values throughout, not floating-point numbers
*/

int main(void)
{
    int amount, bills20 = 0, bills10 = 0, bills5 = 0, bills1 = 0;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    if(amount >= 20)
    {
        bills20 = amount / 20;
        amount = amount - (20 * bills20);
    }

    if(amount >= 10)
    {
        bills10 = amount / 10;
        amount = amount - (10 * bills10);
    }

    if(amount >= 5)
    {
        bills5 = amount / 5;
        amount = amount - (5 * bills5);
    }
    
    bills1 = amount;

    printf("--------------------------------\n");
    printf("$20 bills:      %d\n", bills20);
    printf("$10 bills:      %d\n", bills10);
    printf("$5 bills:       %d\n", bills5);
    printf("$1 bills:       %d", bills1);

    return 0;
}