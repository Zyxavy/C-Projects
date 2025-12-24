#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void play(int x, int y);
void play_diff(int x, int y, int z);
int main()
{
    int choice;
    srand(time(NULL));
    int max;
    int diff;
    int attempts;

    printf("Select difficulty:\n 1.Easy \n 2.Medium \n 3.Hard \n 4.Computer \n");
    scanf("%d", &diff);
    printf("Enter Max Number: ");
    scanf("%d", &max);
    printf("Generating...\n");
    sleep(1);
    int random = rand() % max + 1;
    printf("Guess the number from 0 to %d.\n", max);

    if(diff == 1){
        play(choice, random);
    } else if(diff == 2){
        attempts = 15;
        printf("You have 15 attempts to guess the number.\n");
        play_diff(choice,random,attempts);
    } else if(diff == 3){
        attempts = 7;
        printf("You have %d attempts to guess the number.\n", attempts);
        play_diff(choice,random,attempts);
    } else if(diff == 4){
        max;
        int low = 1;
        choice;
        int yes;

        printf("The computer will try to guess the number.\n");
        printf("How many attempts does the computer have?\n");
        scanf("%d", &attempts);
        printf("Generate random number?: ");
        printf("1. yes  2. no\n");
        scanf("%d", &yes);

        if(yes == 1){
            random = rand() % max + 1;
        } else {
            printf("Enter random number between 0-%d.\n", max);
            scanf("%d", &random);
        }

        printf("Guessing...\n");
        sleep(1);

        while(attempts > 0){
            choice = (low + max) / 2;
            printf("The computer guesses: %d \n \n", choice);
            sleep(1);

            if(choice == random){
                printf("the Computer Won!!\n");
                printf("the random number was: %d\n", random);
                return 0;
            } else if(choice > random){
                printf("Incorrect guess, too high\n");
                max = choice - 1;
            } else {
                printf("incorrect guess, too low!\n");
                low = choice + 1;
            }

            attempts--;

            if(attempts > 0){
                printf("%d attempts left.\n", attempts);
            } else {
                printf("the computer lost...\n");
                printf("the random number was: %d", random);
            }
        }
    }





    return 0;
}

void play(int x, int y){
     x;
     y;
    do{
          scanf("%d", &x);

          if(x == y){
            printf("You have guessed correctly!\n");
            return 0;
          } else if(x > y){
            printf("Incorrect guess, Too high.\n");
          } else if(x < y){
            printf("Incorrect guess. Too low.\n");
          } else{
            printf("Error Incorrect guess.\n");
          }
          } while(x != y);
}

void play_diff(int x, int y, int z){
    x;
    y;
    z;

    while(z > 0){
            printf("You have %d attempts left.\n", z);
          scanf("%d", &x);

          if(x == y){
            printf("You have guessed correctly!\n");
            return 0;
          } else if(x > y){
            printf("Incorrect guess, Too high.\n");
          } else if(x < y){
            printf("Incorrect guess. Too low.\n");
          } else{
            printf("Error Incorrect guess.\n");
          }
          z--;

    }
    if(z <= 0){
        printf("You failed!!\n");
        return 0;
    }

}

void computer(int random){
    random;


}




