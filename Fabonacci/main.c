#include <stdio.h>

int main(){
    int n,i;
    long double n1 = 0,n2 = 1,n3;

    printf("Fabonacci Generator\n");
    printf("Generate the first n number of the sequence: ");
    printf("\nEnter '0' to generate indefinately: ");
    scanf("%f", &n);

    if(n != 0){
        for(i = 1; i <= n; i++){
            printf("%le \n", n1);
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
    } else{
        while(n == 0){
            printf("%le \n", n1);
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
    }
    return 0;
}

