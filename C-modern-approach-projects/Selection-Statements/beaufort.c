/*
Here’s a simplified version of the Beaufort scale, which is used to estimate wind force:
Description
Calm
Li^ a'hl air
Breeze
Galc
Storm
Hurricanc
48^53
Above 63

Write a program that asks the user to enter a wind speed (in knots), then displays the corre
sponding description.
*/

#include <stdio.h>

int main(void)
{
    int windspeed;

    char* desc;

    printf("Enter wind speed in knots: ");
    scanf("%d", &windspeed);

    if(windspeed < 1) desc = "Calm";
    else if(windspeed >= 1 && windspeed <= 3) desc = "Light air";
    else if (windspeed >= 4 && windspeed <= 27) desc = "Breeze";
    else if (windspeed >= 28 && windspeed <= 47) desc = "Gale";
    else if (windspeed >= 48 && windspeed <= 63) desc = "Storm";
    else if (windspeed > 63) desc = "Hurricane";

    printf("Description: %s", desc);

    return 0;
}