/*
Exercise 1.23: esmallest-divisorprocedureshownat
the start of this section does lots of needless testing: Aer it
checks toseeif thenumberisdivisibleby2thereisnopoint
in checking to see if it is divisible by any larger even num
bers. This suggests that the values used for test-divisor
should not be 2, 3, 4, 5, 6, ..., but rather 2, 3, 5, 7, 9, ....

To implement this change, define a procedure next that re
turns 3 if its input is equal to 2 and otherwise returns its in
put plus 2. Modify the smallest-divisor procedure to use
(next test-divisor) instead of (+ test-divisor 1).
With timed-prime-test incorporating this modified ver
sion of smallest-divisor, run the test for each of the 12
primesfoundinExercise1.22.Sincethismodificationhalves
the number of test steps, you should expect it to run about
twice as fast. Is this expectation confirmed? If not, what is
the observed ratio of the speeds of the two algorithms, and
how do you explain the fact that it is different from 2?
*/

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

long long divides(long long a, long long b)
{
    return b % a == 0;
}

long long square(long long x)
{
    return x * x;
}

long long next(long long n)
{
    return (n == 2) ? 3 : n + 2;
}

long long find_divisor(long long n, long long test)
{
    if (square(test) > n) return n;

    if(divides(test, n)) return test;
    else return find_divisor(n, next(test));
}

long long smallest_divisor(long long n)
{
    return find_divisor(n, 2);
}

bool is_prime(long long n)
{
    return (n > 1) && (smallest_divisor(n) == n);
}

void timed_prime_test(long long n) 
{
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);

    is_prime(n);
    
    QueryPerformanceCounter(&start);
    
    
    is_prime(n);
    
    
    QueryPerformanceCounter(&end);
    double elapsed_total = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    
    if (is_prime(n)) 
    {
        printf("%lld *** %.10f seconds \n", n, elapsed_total);
    }
}

int main(void)
{
    int primes[] = {
        1009, 1013, 1019,
        10007, 10009, 10037,
        100003, 100019, 100043,
        1000003, 1000033, 1000037
    };
    
    for (int i = 0; i < 12; i++) 
    {
        timed_prime_test(primes[i]);
    }
    
    return 0;
}