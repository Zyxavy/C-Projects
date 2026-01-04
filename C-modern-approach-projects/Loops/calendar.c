/*
Write a program that prints a one-month calendar. The user specifies the number of days in
the month and the day of the week on which the month begins:
Enter number of days in month: 3JL
Enter starting day of the week (l=Sun, 7=Sat): 2
1 2 3 4 5
6 
7 8 9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31
*/

#include <stdio.h>

int main(void)
{
    int numD, sWeek;

    printf("Enter the number of days in a month: ");
    scanf("%d", &numD);

    printf("Enter starting day of the week (1: Sun, 7: Sat): ");
    scanf("%d", &sWeek);

    printf("S  M  T  W  Th  F  Sa\n");
 
    for(int i = 1, j = 1; i <= numD; i++,j++)
    {
        if(j < sWeek)
        {
            printf("   ");
            i--;
            continue;
        }
        printf("%d  ", i);

        if(j % 7 == 0) printf("\n");
    }

    return 0;
}

// TTC: 26:23