#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    //edge cases
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;


    for (int i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int findNthPrime(int n)
{
   if (n <= 0) return -1;
    if (n == 1) return 2; 

    int count = 1; 
    int current = 3; 
    
    while (count < n) 
    {
        if (isPrime(current)) 
        {
            count++;
            if (count == n) 
            {
                return current;
            }
        }
        current += 2; 
    }
    return -1;
}


int main()
{
    int target = 10001;
    int result = findNthPrime(target);

    printf("The %dth prime is: %d ", target, result);
}