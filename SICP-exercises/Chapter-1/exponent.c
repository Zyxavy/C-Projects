/*
Exercise 1.16: Design a procedure that evolves an itera
tive exponentiation process that uses successive squaring and uses alogarithmic number of steps, as does fast-expt.
(Hint: Using the observation that (bn/2)2 = (b2)n/2, keep,
along with the exponent n and the base b, an additional
state variable a, and define the state transformation in such
a waythattheproductabn isunchangedfromstatetostate.
At the beginning of the process a is taken to be 1, and the
answer is given by the value of a at the end of the process.
In general, the technique of defining an invariant quantity
that remains unchanged from state to state is a powerful
way to think about the design of iterative algorithms.)
*/

#include <stdio.h>
#include <math.h>

long long expo(long long base, long long n)
{
    if (n == 0) return 1;
    if (n == 1) return base;
    long long a = 1, b = base;

    while (n > 0)
    {
       if(n % 2 == 1)
       {
            a = a * b;
       }
       b *= b;
       n = floor(n/2);
    }
    return a;

}

int main(void)
{
    long long exp = expo(4,24);

    printf("4^23: %lld", exp);

    return 0;
}