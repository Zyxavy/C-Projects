/*
Exercise 1.12: The following paern of numbers is called
Pascal’s triangle.


    1
  1   1
 1  2  1
 1 3 3 1
1 4 6 4 1

the numbers at the edge of the triangle are all 1, and each
number inside the triangle is the sum of the two numbers
above it. Write a procedure that computes elements of
Pascal’s triangle by means of a recursive process.

*/

#include <stdio.h>

int pascal(int row, int col)
{
    if((col == 0) || (col == row)) return 1;
    
    return pascal(row-1, col-1) + pascal(row-1, col);
}

void print_pascal(int n_rows) 
{
    for (int row = 0; row < n_rows; row++) 
    {
        for (int i = 0; i < n_rows - row - 1; i++) 
        {
            printf(" ");
        }

        for (int col = 0; col <= row; col++)
        {
            printf("%d ", pascal(row, col));
        }
        printf("\n");
    }
}

int main(void)
{
    print_pascal(20);
    return 0;
}