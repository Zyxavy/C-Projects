/*
Exercise 1.28: One variant of the Fermat test that cannot
be fooled is called the Miller-Rabin test (Miller 1976; Rabin
1980). This starts from an alternate form of Fermat’s Little

Theorem, which states that if n is a prime number and a is
anypositiveintegerless thann,thena raisedtothe(n 1)-st
poweris congruent to 1 modulon. Totest the primality of a
numbern bythe Miller-Rabin test, we pick a random num
ber a < n andraisea tothe(n 1)-stpowermodulon using
the expmod procedure. However, whenever we perform the
squaring step in expmod, we check to see if we have discov
ered a“nontrivial square root of 1 modulon,” that is, a num
ber notequalto1orn 1whosesquareisequalto1modulo
n. It is possible to prove that if such a nontrivial square root
of 1 exists, then n is not prime. It is also possible to prove
that ifn is anoddnumberthatisnotprime,then,foratleast
half the numbers a < n, computing an 1 in this way will
reveal a nontrivial square root of 1 modulo n. (is is why
the Miller-Rabin test cannot be fooled.) Modify the expmod
procedure to signal if it discovers a nontrivial square root
of 1, and use this to implement the Miller-Rabin test with
a procedure analogous to fermat-test. Check your pro
cedure by testing various known primes and non-primes.
Hint: One convenient way to makeexpmodsignalis to have
it return 0.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CARMICHAEL_NUMS (int) (sizeof(car_nums) / sizeof(car_nums[0]))

long long expmodIterative(long long base, long long exp, long long m) 
{
    long long a = 1;
    base = base % m;

    while (exp > 0)
    {
        if(exp % 2 != 0)
        {
            a = (a * base) % m;
            exp = exp - 1;
        }
        else
        {
            long long nextBase = (base * base ) % m;

            if(nextBase == 1 && base != 1 && base != (m-1)) return 0;

            base = nextBase;
            exp = exp / 2;
        }

        if (a == 0) return 0;
    }
    return a;
    
}

bool millerRabinTest(long long n)
{
    long long a = 1 + (rand() % (n - 1));

    return (expmodIterative(a, n-1, n) == 1);
}

int is_prime(long long n, int times) 
{
    if (times == 0) return 1;
    if (millerRabinTest(n)) return is_prime(n, times - 1);
    else return 0;
    
}

int main(void)
{
    int car_nums[] = {561, 1105, 1729, 2465, 2821, 6601, 223};

    for(int i = 0; i < CARMICHAEL_NUMS; i++)
    {
        printf("%d: %d\n", car_nums[i], is_prime(car_nums[i], 10));
    }
}

