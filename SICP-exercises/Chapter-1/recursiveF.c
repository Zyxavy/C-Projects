/*
Exercise 1.11: A function f is defined by the rule that

f (n) = n if n <3,
f (n 1)+2f(n 2)+3f(n 3) if n 3.

Write a procedure that computes f by means of a recursive
process. Write a procedure that computes f by means of an
iterative process
*/

#include <stdio.h>
#include <time.h>

long long int f_recurse(long long int n)
{
    if(n < 3) return n;

    return f_recurse(n-1) + 2 * f_recurse(n-2) + 3 * f_recurse(n-3);
}

long long int f_iterate(long long int n) //ts is blazingly fast
{
    if(n < 3) return n;

    long long int a = 0, b = 1, c = 2, result = 0;

    for(long long int i = 3; i <= n; i++)
    {
        result =  c + 2 * b + 3 * a;

        a=b;
        b=c;
        c=result;
    }
    return result;
}


int main(void)
{
    time_t start, curTime;

    time(&start);
    printf("F(35): %lld\n", f_recurse(35));
    time(&curTime);
    printf("Time: %.5f sec\n\n", difftime(curTime, start));

    time(&start);
    printf("F(400): %lld\n", f_iterate(400));
    time(&curTime);
    printf("Time: %.5f sec\n\n", difftime(curTime, start));

    return 0;
}