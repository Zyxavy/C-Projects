/*
Exercise 1.22: Most Lisp implementations include a prim
itive called runtime that returns an integer that specifies
the amount of time the system has been running (mea
sured, for example, in microseconds). e following timed
prime-testprocedure,whencalledwithanintegern,prints
n andcheckstoseeifn isprime. Ifn is prime, the procedure
prints three asterisks followed by the amount of time used
in performing the test

(define (timed-prime-test n)
(newline)
(display n)
(start-prime-test n (runtime)))
(define (start-prime-test n start-time)
(if (prime? n)
(report-prime (- (runtime) start-time))))
(define (report-prime elapsed-time)
(display " *** ")
(display elapsed-time))

Using this procedure,write a procedure `search-for-primes`
that checks the primality of consecutive odd integers in a
specified range. Use your procedure to find the three small
est primes larger than 1000; larger than 10,000; larger than
100,000; larger than 1,000,000. Note the time needed to test
each prime. Since the testing algorithm has order of growth
of ( n),youshould expect that testing for primes around
10,000 should take about 10 times as long as testing for
primes around 1000. Do your timing data bear this out?
Howwell dothe data for 100,000 and 1,000,000 support the
( n)prediction?Isyourresultcompatiblewiththenotion
that programs on your machine runintimeproportional to
the number of steps required for the computation?
*/

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

int smallest_divisor(int n) 
{
    if (n < 2) return n;
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) return i;
    }
    return n;
}


int is_prime(int n)
{
    return (n > 1) && (smallest_divisor(n) == n);
}

//Using this function instead of the one provided above so that I can get a more accurate time.
void timed_prime_test(long n) 
{
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    
    bool prime = is_prime(n);
    
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    
    printf("\n%ld", n);
    if (prime) 
    {
        printf(" *** %.10f", elapsed);
    }
}

int main(void)
{
    long int start[] = {1000, 10000, 100000, 1000000};

    for(int i = 0; i <= 3; i++)
    {
        int primes = 0;
        long int n = start[i] + 1;

        while (primes < 3)
        {
            if(is_prime(n))
            {
                timed_prime_test(n);
                primes++;
            }
            n+= 2;
        }
        
    }

    return 0;
}