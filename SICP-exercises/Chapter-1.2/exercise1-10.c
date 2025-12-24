/*
Exercise 1.10: e following procedure computes a math
ematical function called Ackermann’s function.

(define (A x y)
(cond ((= y 0) 0)
((= x 0) (* 2 y))
((= y 1) 2)
(else (A (- x 1) (A x (- y 1))))))

What are the values of the following expressions?

(A 1 10)
(A 2 4)
(A 3 3)
*/

#include <stdio.h>


//This is an Ackermann function, it is a recursive function that grows rapidly.
int A(int x, int y) 
{
    if (y == 0) 
    {
        return 0;
    } 
    else if (x == 0) 
    {
        return 2 * y;
    } 
    else if (y == 1) 
    {
        return 2;
    } 
    else 
    {
        return A(x - 1, A(x, y - 1));
    }
}

int main() 
{
    printf("A(1, 10) = %d\n", A(1, 10));  
    printf("A(2, 4) = %d\n", A(2, 4));  
    printf("A(3, 3) = %d\n", A(3, 3));;
    
    /*
    (A 1 10) = 1024
    (A 2 4) = 65536
    (A 3 3) = 65536
    */
    
    return 0;
}
