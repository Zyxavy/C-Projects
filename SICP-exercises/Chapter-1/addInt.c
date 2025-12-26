/*
Exercise 1.9: Each of the following two procedures defines
a method for adding two positive integers in terms of the
procedures inc, which increments its argument by 1, and
dec, which decrements its argument by 1.

(define (+ a b)
(if (= a 0) b (inc (+ (dec a) b))))
(define (+ a b)
(if (= a 0) b (+ (dec a) (inc b))))

Using the substitution model, illustrate the process gener
ated by each procedure in evaluating (+ 4 5). Are these
processes iterative or recursive?
*/


#include <stdio.h>

int add1(int a, int b) 
{
    if (a == 0)
        return b;
    else
        return 1 + add1(a - 1, b);
}

int add2(int a, int b) 
{
    if (a == 0)
        return b;
    else
        return add2(a - 1, b + 1);
}

int main(void)
{
    printf("%d\n", add1(4,5));

    printf("%d\n", add2(4,5));

    return 0;
}

//add1 is Iteratice while add2 is recursive