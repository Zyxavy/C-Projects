#include <stdio.h>

int calcPolynomial(int x);

int main(void)
{
  int x;

  printf("Enter the value of x for (3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6): ");
  scanf("%d", &x);

  printf("Value: %d\n", calcPolynomial(x));
  return 0;
}

int calcPolynomial(int x)
{ 
  return (3 * (x * x * x * x * x)) + (2 * (x * x * x * x) ) - (5 *(x * x * x)) - (1 * (x * x)) + (7 * x) - 6;
}
