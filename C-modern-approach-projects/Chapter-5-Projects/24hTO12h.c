/*
Write a program that asks lhc user for a 24-hour lime, then displays the time in 12-hour
form:kjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM
Be careful not to display 12:00 as 0:00.
*/

#include <stdio.h>

int main(void)
{
    int hour, min;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);
    printf("Equivalent 12-hour time: %d:%d %s", hour < 13 ? hour : hour - 12, min, hour < 13 ? "AM" : "PM");

    return 0;
}