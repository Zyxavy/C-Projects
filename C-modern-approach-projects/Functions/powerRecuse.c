#include <stdio.h>
#include <math.h>

int recPower(int variable, int exponent);

int main(void)
{
  int x, n;
  printf("Enter value of x: ");
  scanf("%d", &x);

  printf("Enter value of n: ");
  scanf("%d", &n);

  printf("Value: %d\n", recPower(x, n));
  return 0;
}

int recPower(int x, int n)
{
  if(n == 0) return 1;

  if(n % 2 == 0)
  {
    return (recPower(x,floor(n/2)) * recPower(x,floor(n/2)));
  }
  else {
    return (x * recPower(x, n-1));
  }
  
}
