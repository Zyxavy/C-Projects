#include <stdio.h>

/*
Write a program that asks the user to enter a dollars-and-cents amount, then displays the
amount with 5% tax added:
Enter an amount: 100.00
With tax added: $105.00
*/

#define TAX 0.05

int main(void)
{
    float amount, tax, totalAmount;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    tax = amount * TAX;

    totalAmount = amount + tax;

    printf("With tax added: $%.2f", totalAmount);

    return 0;
}