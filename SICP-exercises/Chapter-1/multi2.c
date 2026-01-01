/*
Exercise 1.18: Using the results of Exercise 1.16 and Exer
cise 1.17, devise a procedure that generates an iterative pro
cess for multiplying two integers in terms of adding, dou
bling, andhalvingandusesalogarithmicnumberofsteps.
*/

#include <stdio.h>
#include <math.h>

int mul(int a,int b)
{
    if(b == 0) return 0;

    int product = 0;

    while (b > 0)
    {
        if(b % 2 != 0) product += a;
        
        a = a + a;
        b = b >> 1;
        
    }
    return product;
    
}


int main(void)
{
    int ti = mul(1234,1234);

    printf("1234 x 1234: %ld", ti);

    return 0;  
}