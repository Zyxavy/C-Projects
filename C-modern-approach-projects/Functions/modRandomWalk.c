/*
Modify Programming Project 9 from Chapter 8 so that it includes the following functions:
v o id generate_random _w alk(char w alk[10] [10]);
v o id p rin t_ a rra y (c h a r w alk[10] [10]) ;
main first calls g enerate_random _w alk. which initializes the array to contain ’ . ’
characters and then replaces some of these characters by the letters A through Z. as
described in the original project, m ain then calls p r in t_ a r r a y to display the array on
the screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SQR_HEIGHT 10
#define SQR_WIDTH 10
#define ALPHABET 26

void generateRandomWalk(char walk[10][10]);
void printArray(char walk[10][10]);

int main(void)
{
    char square[SQR_HEIGHT][SQR_WIDTH];

    generateRandomWalk(square);
    printArray(square);

    return 0;
}


void generateRandomWalk(char walk[10][10])
{
    for (size_t i = 0; i < SQR_HEIGHT; i++) 
    {
        for (size_t j = 0; j < SQR_WIDTH; j++) 
        {
            walk[i][j] = '.';
        }
    }

    char letter = 'A';
    int x = 0, y = 0;
    walk[x][y] = letter;
    srand(time(0));

    for(int i = 1; i < ALPHABET; i++)
    {
        bool isValid = false;
        int attempt = 0, maxAttempt = 50;

        do
        {
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
                if(walk[newX][newY] == '.')
                {
                    letter++;
                    walk[newX][newY] = letter;
                    x = newX;
                    y = newY;
                    isValid = true;
                }
            }
            attempt++;
            if(attempt > maxAttempt) break;
        } while (!isValid);
        
    }
}

void printArray(char walk[10][10])
{
    for(int i = 0; i < SQR_HEIGHT; i++)
    {
        for(int j = 0; j < SQR_WIDTH; j++)
        {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}