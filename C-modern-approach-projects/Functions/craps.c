#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rollDice(void);
bool playGame(void);

int main(void)
{
  srand(time(0));
  playGame();
}

int rollDice(void)
{
  int dice1 = rand() % 6;
  int dice2 = rand() % 6;

  return dice1 + dice2;
}

bool playGame(void)
{
  char choice = 'n';
  int wins = 0, losses = 0;

  printf("Play the game? (Y/n): ");
  scanf(" %c", &choice);
  
  while(choice == 'Y' || choice == 'y')
  {
    int sum = rollDice(), points = 0;
    printf("You rolled: %d\n", sum);
    
    if(sum == 7 || sum == 11)
    {
      wins++;
      printf("You win!\n\nPlay again?(Y/n): ");
      scanf(" %c", &choice);
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
      losses++;
      printf("You lost :(\n\nPlay again(Y/n): ");
      scanf(" %c", &choice);
    }
    else 
    {
      do
      {
        points += sum;
        printf("You point: %d\n", points);
        sum = rollDice();
        
        if(sum == 7)
        {
          printf("You lose!\n");
          losses++;
          break;
        }

      } while (sum != points || sum != 7);
    }
  }
  
  printf("Wins: %d, Losses: %d\n", wins, losses);
}

