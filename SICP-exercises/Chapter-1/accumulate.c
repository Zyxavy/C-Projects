/*
Exercise 1.32:
a. Show that sum and product (Exercise 1.31) are both
special casesofastillmoregeneralnotioncalledaccumulate
that combines a collection of terms, using some gen
eral accumulation function:
(accumulate combiner null-value term a next b)

accumulate takes as arguments the same term and
rangespecificationsassumandproduct,togetherwith
a combiner procedure (of two arguments) that speci
f
ies how the current term is to be combined with the
accumulationoftheprecedingtermsandanull-value
that specifies what base value to use when the terms
run out. Write accumulate and show how sum and
productcanbothbedefinedassimplecallstoaccumulate.
b. If your accumulate procedure generates a recursive
process, write one that generates an iterative process.
If it generates an iterative process, write one that gen
erates a recursive process.
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

long accumulate(char combiner, int nullVal, long term, long a, long next, long b)
{
    if (a > b) return nullVal;

    switch (combiner)
    {
        case '+': return eval(term , a) + accumulate(combiner, nullVal, term, eval(next, a), next, b);
        case '*': return eval(term , a) * accumulate(combiner, nullVal, term, eval(next, a), next, b);
        default: return 0;
    }

}

int main(void)
{
    int n = 5;
    printf("Sum of 1 - n: %ld\n", accumulate('+', 0, 1, 1, 2, n));
    printf("Product of 1 - n: %ld", accumulate('*', 1, 1, 1, 2, n));
    return 0;
}