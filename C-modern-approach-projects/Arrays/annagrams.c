/*
Write a program that tests whether two words are anagrams (permutations of the same let
ters):
Enter first word: smartest
Enter second word: mattress
The words are anagrams.
Enter first word: dumbest
Enter second word: stumble
The words are not anagrams.
Write a loop that reads the first word, character by character, using an array of26 integers lo
keep track of how many times each letter has been seen. (For example, afier (he word smart
est has been read, the array should contain the values 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 2 2 0
0 0 0 0 0. reflecting the fact that smartest contains one a, one e. one ni, one i\ two .fs and
two r’s.) Use another loop to read the second word, except this time decrementing the corre
sponding array element as each letter is read. Both loops should ignore any characters that
aren’t letters, and both should treat upper-case letters in the same way as lower-case letters.
After the second word has been read, use a third loop to check whether all the elements in
the array are zero. If so. the words are anagrams. Hint: You may wish to use functions from
<ctype .h>, such as isalpha and tolower
*/
#include <stdio.h>
#include <ctype.h>

#define ALPHABET 26
int main(void)
{
    int letters[ALPHABET] = {0 * 26};
    char ch;

    printf("Enter first Word: ");
    while((ch = getchar()) != '\n')
    {  
        if(isalpha(ch))
        {
            int idx = tolower(ch) - 'a';
            letters[idx]++; 
        }   
    }

    printf("Enter second Word: ");
    while((ch = getchar()) != '\n')
    {  
        if(isalpha(ch))
        {
            int idx = tolower(ch) - 'a';
            letters[idx]--; 
        }   
    }

    for(int i = 0; i < ALPHABET; i++)
    {
        if(letters[i] != 0)
        {
            printf("Words are not anagrams.");
            return 0;
        }
    }
    printf("Words are anagrams!");

    return 0;
}