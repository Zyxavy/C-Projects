#include <stdio.h>

/*
Write a program that calculates the remaining balance on a loan after the first, second, and
third monthly payments:kjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA
Enter amount of loan: 20000.00
Enter interest rate: 6.0
Enter monthly payment: 386.66
Balance remaining after first payment: $19713.34
Balance remaining after second payment: $19425.25
Balance remaining after third payment: $19135.71
Display each balance with two digits after the decimal point. Hint: Each month, the balance
is decreased by the amount of the payment, but increased by lhc balance times the monthly
interest rate. To find the monthly interest rate, convert the interest rate entered by the user to
a percentage and divide it by 12.
*/

int main(void)
{
    float loanAmount, interestRate, mPayment, firstPay = 0, secPay = 0, thirdPay = 0;
    float interestPerM = 0;

    printf("Enter amount of loan: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &mPayment);
    interestPerM = (interestRate / 100) / 12;

    firstPay = (loanAmount + ((loanAmount * interestPerM))) - mPayment; 
    secPay = (firstPay + ((firstPay * interestPerM))) - mPayment;
    thirdPay = (secPay + ((secPay * interestPerM))) - mPayment;  

    printf("firstPay: %.2f\n", firstPay);
    printf("Second Pay: %.2f\n", secPay);
    printf("Third Pay: %.2f\n", thirdPay);

    return 0;
}