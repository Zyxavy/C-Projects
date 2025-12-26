/*
Write a program that asks the user to enter the numbers from I to 16 (in any order) and then
displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, columns,
and diaws>onals:
Enter the numbers from 1 to 16 in any order:
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1

16 3 2 13
5 10 11 8
9 6 7 12
4 15 14 1
Row sums: 34 34 34 34
Column sum s: 34 34 34 34
D iagonal sums: 34 34
If the row, column, and diagonal sums are all the same (as they are in this example), the
numbers are said to form a 
m agic square. The magic square shuwn here appears in a 1514
engraving by artist and mathematician Albrecht Durer. (Note that the middle numbers in the
last row give the date of the engraving.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numArr[90]; //Using an array instead of multiple int vars for convenience.

    printf("Enter the numbers from 1 to 16 in any order:\n");
    for(int i = 0; i < 16; i++)
    {
        scanf("%d", &numArr[i]);
    }

    int idx = 0;
    for(int i = 0; i < 4; i++)
    {
        printf("%2d %2d %2d %2d\n", numArr[idx], numArr[idx+1], numArr[idx+2], numArr[idx+3]);
        idx += 4;
    }

    printf("\nRow Sums: ");
    int row = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", numArr[row] + numArr[row+1] + numArr[row+2] + numArr[row+3]);
    }

    printf("\nColumn Sums: ");
    int col = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", numArr[col] + numArr[col+4] + numArr[col+8] + numArr[col+12]);
    }

    printf("\nDiagonal Sums: ");
    int diag = 0;
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", numArr[diag] + numArr[diag+5] + numArr[diag+10] + numArr[diag+15]);
    }
    
    return 0;
}