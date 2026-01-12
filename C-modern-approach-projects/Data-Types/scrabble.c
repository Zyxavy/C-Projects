/*
In lhe SCRABBLE Crossword Game, players form words using small tiles, each containing
a letter and a face value. The face value varies from one letter to another, based on the let
ter’s rarity. (Here are the face values: l: AEILNORSTU. 2: DG. 3: BCMP, 4: FHVWY. 5: K.
8: JX, l0: QZ.) Write a program that computes the value of a word by summing the values
of its letters:
E nter a word: p itf a ll
S crab b le valu e: 12
Your program should allow any mixture of lower-case and upper-case letters in the word.cbaZYXWVUTSRQPONMLKJIHGFEDCBA
Hint: Use the to u p p er library function
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int value = 0;

    printf("Enter a word: ");

    while((ch = getchar()) != '\n')
    {
        ch = toupper(ch);
        switch (ch)
        {
            case'A':case'E':case'I':case'L':case'N':case'O':case'R':case'S':case'T':case'U': value += 1; break;
            case'D':case'G': value += 2; break;
            case'B':case'C':case'M':case'P': value += 3; break;
            case'F':case'H':case'V':case'W':case'Y': value += 4; break;
            case'K': value += 5; break;
        }
    }

    printf("Scrabble value: %d", value);

    return 0;
}