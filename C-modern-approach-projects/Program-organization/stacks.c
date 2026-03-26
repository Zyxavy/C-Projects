#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void makeEmpty();
bool isEmpty();
bool isFull();
void push(char c);
char pop(void);

int main(void)
{
  char ch;
  printf("Enter parenthesis and/or braces: ");
  while((ch = getchar()) != '\n')
  {
    printf("%c", ch);

    if(ch == '(' || ch == '{')
    {
      push(ch);
    }
    else if(ch == ')' || ch == '}')
    {
      char c = pop();
      printf(" | %c |", contents[top]);
    }
  }
   


  if(isEmpty())
  {
    printf("Properly nested\n");
  }
  else 
  {
    printf("Not nested properly\n");
  }
 
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

void push(char c)
{
  if(isFull())
  {
    printf("Stack Overflow\n");
    return;
  }
  contents[top++] = c;
}

char pop(void)
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    return 1;
  }
  return contents[--top];
}
