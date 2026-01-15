/*
Exercise 1.27: Demonstrate that the Carmichael numbers
listed in Footnote 1.47 really do fool the Fermat test. at is,
write a procedure that takes an integern and tests whether
an is congruent toa modulon for everya < n,andtry your
procedure on the given Carmichael numbers
*/

#include <stdio.h>
#include <stdbool.h>

#define CARMICHAEL_NUMS (int) (sizeof(car_nums) / sizeof(car_nums[0]))

long long expmod_iterative(long long base, long long exp, long long m) 
{
    long long result = 1;
    base = base % m;
    
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result * base) % m;
        }
        
        exp = exp >> 1;  
        base = (base * base) % m; 
    }
    
    return result;
}

bool try_a(long long a, long long n)
{
    if(a == 0) return true;
    else if( (expmod_iterative (a, n, n ) != a)) return false;
    else return try_a(a - 1, n);
}

bool carmichaelTest(long long n)
{
    return try_a(n - 1, n);
}

int main(void)
{
    int car_nums[] = {561, 1105, 1729, 2465, 2821, 6601, 223};

    for(int i = 0; i < CARMICHAEL_NUMS; i++)
    {
        printf("%d: %d\n", car_nums[i], carmichaelTest(car_nums[i]));
    }
}