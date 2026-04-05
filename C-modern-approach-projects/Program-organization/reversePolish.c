#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void makeEmpty();
bool isEmpty();
bool isFull();
void push(int i);
int pop(void);
char peek();

int main(void)
{
  char ch = ' ';
  printf("Enter an RPN expression: ");
  
  while (ch != '\n') 
  {
    scanf(" %c", &ch);
    switch (ch)
    {
      case '1':case '2':case '3':case '4':case '5':
      case '6':case '7':case '8':case '9':case '0': push(ch - '0') ; break;  
      
      case '+':
      {
        int first = pop();
        int sec = pop();

        push(first + sec);
        break;
      }
      case '-':
      {
        int first = pop();
        int sec = pop();
        printf("%d %d", first, sec);

        push(sec - first);
        break;
      }
      case '/':
      {
        int first = pop();
        int sec = pop();

        push(floor(sec / first));
        break;
      }
      case '*':
      {
        int first = pop();
        int sec = pop();

        push(first * sec);
        break;
      }

      case '=':
        printf("Value of expression: %d\n", peek()); break;
      default:
        exit(0);
    }
  }


  return 0;
}

void makeEmpty()
{top = 0;}

bool isFull()
{
  return top == STACK_SIZE;
}

bool isEmpty()
{
  return top == 0;
}

void push(int i)
{
  if(isFull())
  {
    printf("Stack Overflow\n");
    return;
  }
  contents[top++] = i;
}

int pop(void)
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    return 1;
  }
  return contents[--top];
}

char peek()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    return 1;
  }
  return contents[top-1];
}


