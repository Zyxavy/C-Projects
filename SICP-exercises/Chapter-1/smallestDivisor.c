/*
Exercise1.21:Use the smallest-divisor procedure to find
the smallest divisor of each of the following numbers: 199,
1999, 19999
*/

#include <stdio.h>

int divides(int a, int b)
{
    return b % a == 0;
}

int square(int x)
{
    return x * x;
}

int find_divisor(int n, int test)
{
    if (square(test) > n) return n;

    if(divides(test, n)) return test;
    else return find_divisor(n, test + 1);
}

int smallest_divisor(int n)
{
    return find_divisor(n, 2);
}

int main(void)
{
    printf("199: %d\n", smallest_divisor(199));
    printf("1999: %d\n", smallest_divisor(1999));
    printf("19999: %d\n", smallest_divisor(19999));
    return 0;
}