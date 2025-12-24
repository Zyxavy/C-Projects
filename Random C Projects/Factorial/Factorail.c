#include <stdio.h>
int fact(int n);

int main(){
    int n;

    printf("Factorial Calculator!\n");
    printf("Enter Number: ");
    scanf("%d", &n);

    int result = fact(n);
    printf("The factorial of %d is %d", n, result);
    
    return 0;
}

int fact(int n){
    if(n != 1)
        return n * fact(n - 1);
    else
        return n;
    
}