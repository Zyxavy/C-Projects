/*
Write a program that takes a first name and last name entered by the user and displays the
last name, a comma, and the first initial, followed by a period:
E nter a f ir s t and la s t name: Lloyd Fosdick
F osdick, L.
The user’s input may contain extra spaces before the first name, between the first and last
names, and after the last name.
*/
#include <stdio.h>

int main(void)
{
    char ch;
    char firstInit = ' ';

    printf("Enter a first and last name: ");

    while((ch = getchar()) == ' ')
        ;

    firstInit = ch;

    while((ch = getchar()) != ' ')
    {
        if(ch == '\n') return 0;
    }
    
    while((ch = getchar()) == ' ')
        ;

    putchar(ch);
    while((ch = getchar()) != '\n' && ch != ' ')
    {
        putchar(ch);
    }

    printf(", %c.", firstInit);
        
    return 0;
}

// TTC: 39:35