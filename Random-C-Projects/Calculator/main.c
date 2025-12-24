#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double num1, double num2){
    return printf("%f", num1 + num2);
}
double sub(double num1, double num2){
    return printf("%f", num1 - num2);
}

double divide(double num1, double num2){
    return printf("%f", num1 / num2);
}

double multi(double num1, double num2){
    return printf("%f", num1 * num2);
}

int main(){
    double num1;
    double num2;
    char op;
    char cont = 'y';

while(cont == 'y') {
    printf("Enter num:");
    scanf("%lf", &num1);
    printf("Enter Operation:");
    scanf(" %c", &op);
    printf("Enter Num:");
    scanf("%lf", &num2);
    sleep(1);

    if (cont == 'y'){
        if(op == '+'){
            add(num1, num2);
        } else if (op == '-'){
            sub(num1, num2);
        } else if(op == '/'){
            divide(num1, num2);
        } else if(op == '*'){
            multi(num1, num2);
        } else{
            printf("ERROR");
    }
    } else {printf("end");}

    printf("\nRe-calculate? y/n:");
    scanf(" %c", &cont);
}


printf("End");
printf("....\n");



return 0;
}
