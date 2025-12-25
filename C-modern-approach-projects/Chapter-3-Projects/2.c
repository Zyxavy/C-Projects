/*
Write a program that formats product information entered by the user. A session with the
program should look like this:

Enter item number: 583
Enter unit price: 13.5
Enter purchase date (mm/dd/yyyy): 10/24/2010

Item 
583 
Unit 
Price 
$ 13.50 
Purchase
Date
10/24/2010

The item number and date should be leftjustified; the unit price should be rightjustified.
Allow dollar amounts up to S9999.99. Hint: Use tabs to line up the columns.
*/

#include <stdio.h>

int main(void)
{
    int item, dYear, dMonth, dDay;
    float unitPrice;

    printf("Enter item number: ");
    scanf("%d", &item);
    
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);
    
    printf("Enter purchase date: ");
    scanf("%d/%d/%d", &dMonth, &dDay, &dYear);

    printf("Item\t\tUnit\t\t\tPurchase\n");
    printf("\t\tPrice\t\t\tDate\n");
    printf("%d\t\t$%7.2f\t\t%.2d/%.2d/%d\n", item, unitPrice, dMonth, dDay, dYear);

    return 0;
}