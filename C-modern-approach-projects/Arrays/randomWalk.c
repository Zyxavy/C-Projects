/*
Write a program that generates a “random walk" across a 10 x 10 array. The array will con
tain characters (all ’ . ’ initially). The program must randomly “walk” from element to ele
ment; always going up, down. left, or right by one element. The elements visited by thc
program will be labeled with the letters A through Z, in the order visited. Here's an example
oflhe desired output:

. F E ..............
H G ................
I ..................
J ............... Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O ..............

Hint: Use the sran d and rand functions (see d e a l. c) to generate random numbers.
After generating a number, look at its remainder when divided by 4. There are four possible
values for the remainder—0. 1.2, and 3—indicating the direction of the next move. Before
performing a move, check that (a) il won’t go outside the array, and (b) it doesn’t take us to
an element that already has a letter assigned. If either condition is violated, try moving in
another direction. If all four directions are blocked, the program must terminate. Here’s an
example of premature termination:
A B G H I . .
. C F . J K .
. D E . M L .
. . . . N 0 .
. . W X Y P Q
. . V U T S R
Y is blocked on all four sides, so there’s no place to put Z
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SQR_HEIGHT 10
#define SQR_WIDTH 10
#define ALPHABET 26

int main(void)
{
    char square[SQR_HEIGHT][SQR_WIDTH];

    for (size_t i = 0; i < SQR_HEIGHT; i++) 
    {
        for (size_t j = 0; j < SQR_WIDTH; j++) 
        {
            square[i][j] = '.';
        }
    }

    char letter = 'A';
    int x=0, y=0;
    square[x][y] = letter;
    srand(time(0));

    for (size_t i = 1; i < ALPHABET; i++)
    {
        bool isValid = false;
        int attempts = 0, maxAttempts = 50;

        do{
            int newX = x, newY = y;
            int direction = rand() % 4;
            switch (direction)
            {
                case 0: newX = x - 1; break; //UP
                case 1: newX = x + 1; break; //DOWN
                case 2: newY = y - 1; break; //LEFT
                case 3: newY = y + 1; break; //RIGHT
            }

            if((newX >= 0 && newX < SQR_HEIGHT) && (newY >= 0 && newY < SQR_WIDTH))
            {
                if(square[newX][newY] == '.')
                {
                    letter++;
                    square[newX][newY] = letter;
                    y = newY;
                    x = newX;
                    isValid = true;
                }
            }
            attempts++;
            if(attempts > maxAttempts) break;

        } while(!isValid);

    }  

    for(size_t i = 0; i < SQR_HEIGHT; i++)
    {
        for (size_t j = 0; j < SQR_WIDTH; j++)
        {
            printf(" %c", square[i][j]);
        }
        printf("\n");
        
    }


    return 0;
}