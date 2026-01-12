/*
Write a program that translates an alphabetic phone number into numeric form:
E nter phone number: CALLATT
2255288
(In case you don’t have a telephone nearby, here are the letters on the keys: 2=ABC, 3=DEF,
4=GHI, 5=JKL. 6=MN0, 7=PRS, 8=TUV. 9=WXY.) Ifthe original phone numbercontains
nonalphabetic characters (digits or punctuation, for example), leave them unchanged:
E nter phone numbe r : l-800-CQL-LECT
1-800-265-5328
You may assume that any letters entered by thc user are upper case
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;

    printf("Enter phone number: ");
    
    while ((ch = getchar())!= '\n')
    {
        ch = toupper(ch);
        switch (ch)
        {
        case 'A': case 'B': case 'C': ch = '2'; break;
        case 'D': case 'E': case 'F': ch = '3'; break;
        case 'G': case 'H': case 'I': ch = '4'; break;
        case 'J': case 'K': case 'L': ch = '5'; break;
        case 'M': case 'N': case 'O': ch = '6'; break;
        case 'P': case 'R': case 'S': ch = '7'; break;
        case 'T': case 'U': case 'V': ch = '8'; break;
        case 'W': case 'X': case 'Y': ch = '9'; break;
        }

        printf("%c", ch);
    }

    return 0;
}

//TTC: < 7:00