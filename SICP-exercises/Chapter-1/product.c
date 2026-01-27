/*
Exercise 1.31:
a. esumprocedure is only the simplest of a vast number
of similar abstractions that can be captured as highe
orderprocedures.51 Writeananalogousprocedurecalled
product that returns the product of the values of a
functionatpointsoveragivenrange.Showhowtode
f
inefactorialintermsof product.Alsouseproduct
to compute approximations to using the formula52
4 = 2 4 4 6 6 8
3 3 5 5 7 7 .
b. If your product procedure generates a recursive pro
cess, write one that generates an iterative process. If
it generates an iterative process, write one that gen
erates a recursive process
*/
#include <stdio.h>

double eval(int id, double x)
{
    switch (id)
    {
        case 1: return x;
        case 2: return x + 1;
        default: return 0;
    }
}

long product(long term, long a, long next, long b)
{
    if(a > b) return 1;
    
    return eval(term, a) * product(term, eval(next, a), next, b);
}

long factorial(long n)
{
    return product(1, 1, 2, n);
}

int main(void)
{

    int n = 6;
    printf("Factorial of 6: %ld", factorial(n));
    return 0;
}
