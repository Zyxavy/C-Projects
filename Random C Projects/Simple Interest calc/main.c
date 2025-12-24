#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    double principal;
    int time;
    double interest;
    double rate;
    int retry = 'y';

    do{
        int x;
        printf("\nSimple Interest Calculator!\n");
        printf("What do you want to calculate?\n");
        printf("1. Principal  |  2.Time  |  3. Rate  | 4. Simple Interest \n");
        scanf("%d", &x);

        if(x == 1){
            printf("Enter Simple Interest: \n");
            scanf("%lf", &interest);
            printf("Enter Rate of Interest per annum: \n");
            scanf("%lf", &rate);
            printf("Enter Time(in years): \n");
            scanf("%d", &time);

            principal = (interest * 100) / (rate * time);

            printf("The Principal is %f", principal);
        } else if (x == 2){
            printf("Enter Simple Interest: \n");
            scanf("%lf", &interest);
            printf("Enter Rate of Interest per annum: \n");
            scanf("%lf", &rate);
            printf("Enter Principal: \n");
            scanf("%lf", &principal);

            time = (interest * 100) / (principal * rate);

            printf("The time is %d years", time);
        } else if (x == 3){
            printf("Enter Simple Interest: \n");
            scanf("%lf", &interest);
            printf("Enter Principal amount: \n");
            scanf("%lf", &principal);
            printf("Enter Time(in years): \n");
            scanf("%d", &time);

            rate = (interest * 100) / (principal * time);

            printf("The rate of interest is %lf%%", rate);
        } else if (x == 4){
            printf("Enter Rate of interest per annum: \n");
            scanf("%lf", &rate);
            printf("Enter Principal amount: \n");
            scanf("%lf", &principal);
            printf("Enter Time(in years): \n");
            scanf("%d", &time);

            interest = (principal * rate * time) / 100;

            printf("The simple interest is %f ", interest);
        } else{
            printf("Error\n");
        }

        printf("\nCalculate again?(y/n): \n");
        scanf(" %c", &retry);
        Sleep(1);
    } while(retry == 'y' || retry == 'Y');


    return 0;
}
