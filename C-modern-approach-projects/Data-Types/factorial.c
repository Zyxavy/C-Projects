/*
Write a program that computes the factorial of a positive integer:
Enter a positive integer: 6
Factorial of 6: 720

(a) Use a sh o rt variable to store the value of the factorial. What is the largest value ofn
for which the program correctly prints the factorial of /??
(b) Repeat part (a), using an in t variable instead.
(c) Repeal part (a), using a lo ng variable instead.
(d) Repeat part (a), using a long long variable instead (if your compiler supports the
l o n g long type).
(e) Repeat part (a), using a f lo a t variable instead.
(1) Repeat part (a), using a d o uble variable instead.
(g) Repeat part (a), using a lo ng double variable instead.
In cases (e)-(g), the program will display a close approximation ofthe factorial, not neces
sarily the exact value
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

long long factorial_longlong(int n)
{
    long long product = 1;
    
    for (int i = 1; i <= n; i++) product *= i;
    
    return product;
}

int fact_short()
{
    short factorial = 1;
    int n = 1;
    
    while (1) 
    {
        factorial *= n;
        if (factorial <= 0 || factorial > SHRT_MAX / (n + 1)) 
        {
            printf("n = %d, factorial = %d (overflow occurs at n = %d)\n", n, factorial, n + 1);
            return n;
        }
        n++;
    }
}
  
int fact_int()
{
    int factorial = 1;
    int n = 1;
    
    while (1) 
    {
        factorial *= n;
        if (factorial <= 0 || factorial > INT_MAX / (n + 1)) 
        {
            printf("n = %d, factorial = %d (overflow occurs at n = %d)\n", n, factorial, n + 1);
            return n;
        }
        n++;
    }
}

int fact_long()
{
    long factorial = 1L;
    int n = 1;
    
    while (1) 
    {
        factorial *= n;
        if (factorial <= 0 || factorial > LONG_MAX / (n + 1)) 
        {
            printf("n = %d, factorial = %ld (overflow occurs at n = %d)\n", n, factorial, n + 1);
            return n;
        }
        n++;
    }
}

int fact_longlong()
{
    long long factorial = 1LL;
    int n = 1;
    
    while (1) 
    {
        factorial *= n;
        if (factorial <= 0 || factorial > LLONG_MAX / (n + 1)) 
        {
            printf("n = %d, factorial = %lld (overflow occurs at n = %d)\n", n, factorial, n + 1);
            return n;
        }
        n++;
    }
}

int fact_float()
{
    float factorial = 1.0f;
    int n = 1;
    
    while (1) 
    {
        float prev = factorial;
        factorial *= n;
        
        if(factorial <= 0 || !(factorial < FLT_MAX))
        {
            printf("n = %d, factorial = %e (overflow/infinity occurs next)\n",  n, prev);
            return n;
        }
        n++;
    }
}

int fact_double()
{
    double factorial = 1.0;
    int n = 1;
    
    while (1) 
    {
        double prev = factorial;
        factorial *= n;
        
        if(factorial <= 0 || !(factorial < DBL_MAX))
        {
            printf("n = %d, factorial = %e (overflow/infinity occurs next)\n", n, prev);
            return n;
        }
        n++;
    }
}

int fact_longdouble()
{
    long double factorial = 1.0L;
    int n = 1;
    
    while (1) 
    {
        long double prev = factorial;
        factorial *= n;
        
        if(factorial <= 0 || !(factorial < LDBL_MAX))
        {
            printf("n = %d, factorial = %Le (overflow/infinity occurs next)\n",  n, prev);
            return n;
        }
        n++;
    }
}

int main(void)
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    long long result = factorial_longlong(n);
    printf("Factorial of %d: %lld\n\n", n, result);
    
    printf("Testing limits for different data types:\n");
    printf("=======================================\n\n");
    
    printf("A: Using short variable:\n");
    int max_short = fact_short();
    printf("   Maximum n before overflow: %d\n\n", max_short);
    
    printf("B: Using int variable:\n");
    int max_int = fact_int();
    printf("   Maximum n before overflow: %d\n\n", max_int);
    
    printf("C: Using long variable:\n");
    int max_long = fact_long();
    printf("   Maximum n before overflow: %d\n\n", max_long);
    
    printf("D: Using long long variable:\n");
    int max_longlong = fact_longlong();
    printf("   Maximum n before overflow: %d\n\n", max_longlong);
    
    printf("E: Using float variable:\n");
    int max_float = fact_float();
    printf("   Maximum n before overflow: %d\n\n", max_float);
    
    printf("F: Using double variable:\n");
    int max_double = fact_double();
    printf("   Maximum n before overflow: %d\n\n", max_double);
    
    printf("G: Using long double variable:\n");
    int max_longdouble = fact_longdouble();
    printf("   Maximum n before overflow: %d\n", max_longdouble);
    
    return 0;
}

//TTC: 45:51