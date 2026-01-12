/*
Write a program that uses Newton’s method to compute the square root of a positive float
ing-point number:

Enter a positive number: 3
Square root: 1.73205

Let .v be the number entered by the user. Newton’s method requires an initial guess 
y for the square root of.Y (we’ll use y = 1). Successive guesses are found by computing the average of
y and x/y. The following table shows how the square root of 3 would be found:

Note that the values of y get progressively closer to the true square root of .v. For greater
accuracy, your program should use variables oftype d o u b le rather than f lo a t. Have the
program terminate when the absolute value ofthe difference between the old value ofy and
the new value ofy is less than the product of .00001 and y. Hint: Call the fa b s function to
find the absolute value of a double. (You’ll need to include the < m ath. h> header at the
beginning of your program in order to use fabs.)
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int x = 0, i = 0;
    double xy, avg, y = 1.0;
    printf("Enter a positive number: ");
    scanf("%d", &x);

    while(1)
    {
        xy = (double) x / y;
        avg = (y + xy) / 2.0;

        if(fabs(y - avg) < (y * 0.00001)) break;
        y = avg;

        printf("Iteration %d:  xy: %lf | avg: %lf | y = %lf\n",i++, xy, avg, y);

    }
    printf("The square root is: %lf", avg);
}

//TTC: 13:35