#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double temp;
    char unit;
    char unit2;
    char ct = 'y';


    printf("TEMPERATURE CONVERTER\n");
    printf("C = Celsius, F = Fahrenheit, K = Kelvin\n");
    while(ct ==  'y' || ct == 'Y'){
        printf("\nEnter your unit: ");
        scanf(" %c", &unit);
        printf("Enter the temperature: ");
        scanf("%lf", &temp);
        printf("Convert into: ");
        scanf(" %c", &unit2);


        if(unit == 'c' || unit == 'C'){
                 if(unit2 == 'f' || unit2 == 'F'){
                    printf("%lf Fahrenheit\n",temp * 2  + 30);
                } else if(unit2 == 'k' || unit2 == 'K'){
                     printf("%lf Kelvin\n", temp + 273.15); }
        } else if (unit == 'f' || unit == 'F'){
                if(unit2 == 'c' || unit2 == 'C'){
                    printf("%lf Celsius\n", (temp - 30) / 2);
                } else if(unit2 == 'k' || unit2 == 'K'){
                    printf("%lf Kelvin",  (temp - 32) * 5 / 9 + 273.15); }
        } else if (unit == 'k' || unit == 'K'){
                if(unit2 == 'c' || unit2 == 'C'){
                    printf("%lf Celsius", temp - 273.15);
                } else if(unit2 == 'f' || unit2 == 'F') {
                    printf("%lf Fahrenheit", (temp - 273.15) * 9 / 5 + 32); }
        } else{
            printf("\nError!!");
        }
        sleep(1);
        printf("\nContinue? Y/N: ");
        scanf(" %c", &ct);
 }




    return 0;
}
