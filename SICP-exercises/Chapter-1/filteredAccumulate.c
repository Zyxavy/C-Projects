/*
Exercise 1.33: You can obtain an even more general ver
sion of accumulate (Exercise 1.32) by introducing the no
tion of afilter onthetermstobecombined.atis,combine
only those terms derived from values in the range that sat
isfy aspecifiedcondition.eresultingfiltered-accumulate
abstraction takes the same arguments as accumulate, to
gether with an additional predicate of one argument that
specifies the filter. Write filtered-accumulate as a proce
dure. Show how to express the following using filtered
accumulate:
a. the sum of the squares of the prime numbers in the
intervala tob (assumingthatyouhaveaprime?pred
icate already wrien)
b. the product of all the positive integers less thann that
are relatively prime ton (i.e., all positive integersi < n
such that (i,n) = 1)
*/
#include <stdio.h>

int G_n = 1;

int gcd(int x, int n)
{
    while(n != 0)
    {
        int r = x % n;
        x = n;
        n = r;
    }
    return x;
}

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

double eval(int id, double x, double n)
{
    switch (id)
    {
        case 1: return x * x;
        case 2: return x + 1;
        case 3: return is_prime((int)x);
        case 4: return gcd((int) x, (int) n) == 1;
        case 5: return x;
        default: return 0;
    }
}

long filteredAccumulate(char combiner, int nullVal, long term, long a, long next, long b, int filter_id, int filter_n)
{
    if (a > b) return nullVal;

    if(eval(filter_id, a, filter_n) != 0)
    {
        
        switch (combiner)
        {
            case '+': return eval(term, a, filter_n) + 
                    filteredAccumulate(combiner, nullVal, term, 
                    (long)eval(next, a, filter_n), next, b, filter_id, filter_n);

            case '*': return eval(term, a, filter_n) * 
                    filteredAccumulate(combiner, nullVal, term, 
                    (long)eval(next, a, filter_n), next, b, filter_id, filter_n);

            default: return 0;
        }
        
    }
    else
    {
       return filteredAccumulate(combiner, nullVal, term, 
                (long)eval(next, a, filter_n), next, b, filter_id, filter_n);
    }
}
 

int main(void)
{
    printf("Sum of squares of primes from 1 to 10: %ld\n", 
        filteredAccumulate('+', 0, 1, 1, 2, 10, 3, 0));
        
    printf("Product of numbers < 10 that are coprime to 10: %ld\n", 
        filteredAccumulate('*', 1, 5, 1, 2, 9, 4, 10));
    return 0;
}