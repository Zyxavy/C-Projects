#include <stdio.h>

/*
Modify the program of Programming Project 2 so that it prompts the user to enter the radius
of the sphere
*/

#define PI 3.14

int main(void)
{
    float R, v;

    printf("Enter a radius: ");
    scanf("%f", &R);

    v = (4.0f / 3.0f) * PI * (R * R *R);

    printf("%f ", v);

    return 0;
}