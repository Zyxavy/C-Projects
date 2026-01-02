/*
Write a program that finds the largest and smallest offour integers entered by the user:
Enter four integers: 21 43 10 35
Largest: 43
Smallest: 10
Use as few if statements as possible. Hint: Four i f statements are sufficient
*/

#include <stdio.h>

int max(int a, int b)
{
    int diff = a - b;
    int mask = diff >> 31;
    return a - (diff & mask);
}

int min(int a, int b)
{
    int diff = a - b;
    int mask = diff >> 31;
    return b + (diff & mask);
}

int main(void)
{
    int a, b, c, d;

    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf("Largest: %d |", max(max(a,b), max(c,d)));
    printf(" Smallest: %d", min(min(a,b), min(c,d)));
    
    return 0;
}
