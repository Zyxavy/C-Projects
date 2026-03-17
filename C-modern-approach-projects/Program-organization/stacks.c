#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100


//Incomplete: 
/*
 *turn the input into a string, read the string by chars, if char == '( {', then push.

  into another loop, read the string by chars, if char == '} )', pop.

  if empty == properly nested
  if not == not properly nested
 *
 */  

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
    
    if(ch == '(' || ch == '{')
    {
      push(ch);
    }
  }

  while(!isEmpty())
  {
    if()
  }

  if(isEmpty())
  {
    printf("Properly nested!\n");
  }
  else 
  {
    printf("Not Properly nested\n");
  }




  return 0;
}

void makeEmpty()
{
  top = ' ';
}

bool isFull()
{
  return top == STACK_SIZE;
}

bool isEmpty()
{
  return top == ' ';
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
    return 0;
  }
  return contents[--top];
}
