#include <stdio.h>

int main(){
    int sum = 0,sum2 = 0, diff, limit = 10000;


    sum = (limit * (limit+1))/2;
    sum2 = ((2 * limit) + 1 ) * (limit + 1) * limit / 6;
    
    printf("%d", sum*sum - sum2);
}