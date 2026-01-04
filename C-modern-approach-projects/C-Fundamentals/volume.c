#include <stdio.h>

/*
Write a program that computes the volume of a sphere with a 10-meter radius, using the for
mula v = 4/3jr/^. Write the fraction 4/3 as 4 .0 f /3 . 0f. (Try writing it as 4 /3 . What hap
pens?)
Hint: C doesn't have an exponentiation operaton so you'll need to multiply r by itself
twice to compute A
*/

#define PI 3.14
#define R 10

int main(void)
{
    float v = (4.0f / 3.0f) * PI * (R * R *R);

    printf("%f ", v);

    return 0;
}