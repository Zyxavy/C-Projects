/*
Exercise 1.19: There is a clever algorithm for computing
the Fibonacci numbers in a logarithmic number of steps.
Recall the transformation of the state variables a and b in
the fib-iter process of Section 1.2.2:a 
a+b andb a.
Call this transformation T, and observe that applying T
over andoveragainn times, starting with 1 and 0, produces
the pair Fib(n + 1) and Fib(n). In other words, the Fibonacci
numbers are produced by applyingTn, thenth power of the
transformationT,startingwiththepair(1,0).Nowconsider
T to be the special case of p = 0 and q = 1 in a family of
transformations Tpq, where Tpq transforms the pair (a,b)
according to a 
bq + aq + ap and b bp +aq. Show
that if we apply such a transformationTpq twice, the effect
is the same as using a single transformation Tp′q′ of the
same form, and compute p′andq′in terms of p andq. is
gives us an explicit way to square these transformations,
and thus we can computeTn using successive squaring, as
in the fast-expt procedure. Put this all together to com
plete the following procedure, which runs in a logarithmic
number of steps:   

*/

#include <stdio.h>
#include <math.h>

long long fastFib(long long a, long long b, long long p, long long q, long long n)
{
    if(n == 0) return b;


    if (n % 2 == 0)
    {
        long long p1 = (p * p) + (q * q);
        long long q1 = (q * q) + 2 * (p * q);
        return fastFib(a, b, p1, q1, n/2);
    }
    else
    {
        long long new_a = (b*q) + (a * q) + (a * p);
        long long new_b = (b * p) + (a * q);
        return fastFib(new_a, new_b, p, q, n - 1);
    }

}

long long fib(int n)
{
    return fastFib(1, 0, 0, 1, n);
}

int main(void)
{
    long long n = 134; //134 is the limit before overflow

    long long result = fib(n);
    
    printf("F(%d) = %lld\n\n", n, result);
    
    return 0;
}