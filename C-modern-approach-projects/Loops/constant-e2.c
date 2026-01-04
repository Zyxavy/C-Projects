/*
Modify Programming Project 11 so that the program continues adding terms until the cur
rent term becomes less than E. where e is a small (Hoating-point) number entered by the
user
*/
#include <stdio.h>

int factIter(int product, int counter, int maxCount)
{
    if(counter > maxCount) return product;
    else
    {
        return factIter((counter * product), (counter + 1), maxCount);
    }
}

int factorial(int n)
{
    return factIter(1, 1, n);
}

int main(void)
{
    double e = 1.0, num = 5.2;
    float E;
    printf("Enter E (ex. 0.00001) : ");
    scanf("%f", &E);

    int i = 1;
    do
    {
        num = 1.0 / (factorial(i));
        e += num;
        i++;
    } while(num > E);

    printf("e = %.15lf", e);

    return 0;
}

//TTC: 7:33