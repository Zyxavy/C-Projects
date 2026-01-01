/*
The exponentiation algorithms in this sec
tion are based on performing exponentiation by means of
repeated multiplication. In a similar way, one can perform
integer multiplication by means of repeated addition. e
following multiplication procedure (in which it is assumed
that our language can only add, not multiply) is analogous
to the expt procedure:

(define (* a b)
(if (= b 0)
0
(+ a (* a (- b 1)))))

This algorithm takes a number of steps that is linear in b.
Now suppose we include, together with addition, opera
tions double, which doubles an integer, and halve, which
divides an (even) integer by 2. Using these, design a mul
tiplication procedure analogous to fast-expt that uses a
logarithmic number of steps.
*/

#include <stdio.h>
#include <math.h>

long int multiply(int a, int b)
{
    if(b == 0) return 0;

    long int product = 0;

    while(b > 0)
    {
        if(b % 2 != 0)
        {
            product = product + a;
        }
        a = 2 * a;
        b = floor(b / 2);
    }
    return product;
}

int main(void)
{
    long int mul = multiply(5,10);

    printf("4x23: %ld", mul);

    return 0;
}