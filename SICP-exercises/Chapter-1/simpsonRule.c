/*
 Simpson’s Rule is a more accurate method
of numerical integration than the method illustrated above.
Using Simpson’s Rule, the integral of a function f between
a andb is approximated as
h
3
(y0 + 4y1 + 2y2 + 4y3 +2y4 + +2yn 2 +4yn 1 +yn),
where h = (b a)/n, for some even integer n, and yk =
f (a + kh). (Increasing n increases the accuracy of the ap
proximation.) Define a procedure that takes as arguments
f , a, b, and n and returns the value of the integral, com
puted using Simpson’s Rule. Use your procedure to inte
grate cube between 0 and 1 (with n = 100 and n = 1000),
andcomparetheresultstothoseoftheintegralprocedure
shown above.
*/

#include <stdio.h>

double eval(int id, double x)
{
    switch (id)
    {
        case 1: return x * x * x; break;
        default: return 0;
    }
}

double simpson(int id, double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = eval(id, a) + eval(id, b);

    for(int k = 1; k < n; k++)
    {
        double yk = eval(id, a + k * h);
        sum += (k % 2 == 0 ? 2 : 4) * yk;
    }
    return (h / 3.0) * sum;
}

int main(void)
{
    int id = 1;
    double a = 0.0;
    double b = 1.0;

    printf("Result (n=100): %f\n", simpson(id, a, b, 100));
    printf("Result (n=3456): %f\n", simpson(id, a, b, 3456));

    return 0;
}