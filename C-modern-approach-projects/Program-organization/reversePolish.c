#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void makeEmpty();
bool isEmpty();
bool isFull();
void push(int i);
int pop(void);

int main(void)
{
  char ch;
  printf("Enter an RPN expression: ");
  
  while (ch != '\n') 
  {
    scanf(" %c", &ch);

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

