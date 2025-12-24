#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    for(int i = 0; i <= 100; i++){
        if(i % 2 == 0 && i % 5 == 0){
            printf("FizzBuzz\n");
        } else if(i % 5 == 0) {
            printf("Buzz\n");
        } else if (i % 2 == 0){
            printf("Fizz\n");
        }
        else {
            printf("%d\n", i);
        }

    }

    return 0;
}
