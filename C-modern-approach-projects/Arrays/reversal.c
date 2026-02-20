/*
Wriie a program lhal reverses lhc words in a sentence:
Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?cbaZYXWVUTSRQPONMLKJIHGFEDCBA
Hint: Usc a loop lo read lhe characters one by one and siore them in a one-dimensional
c h ar array. Have the loop slop al a period, queslion mark, orexclamation point (the “termi
nating character*), which is saved in a separate c h a r variable. Then use a second loop lo
scarch backward lhrough the array for the beginning of lhe last word. Prinl the last word,
lhen search backward for the nexi-(o-last word. Repeal until lhe beginning of the array is
reached. Finally, print lhe terminating character
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100

int main(void)
{
    char sentence[MAX_CHARS];
    char ch;
    int len;
    printf("Enter sentence: ");
    fgets(sentence, MAX_CHARS, stdin);

    len = strlen(sentence);
    if(sentence[len-1] == '\n') 
    {
        sentence[len-1] = '\0'; 
        len--;
    }
    
    ch = sentence[len-1];
    sentence[len-1] = '\0';
    len--;

    int i = len - 1, j;
    while(i >= 0)
    {
        j = i;
        while (j >= 0 && sentence[j] != ' ')
        {
            j--;
        }

        for(int k = j + 1; k <= i; k++)
        {
            printf("%c", sentence[k]);
        }
        
        if(j > 0) printf(" ");

        i = j-1;
        
    }
    printf("%c\n", ch);
    return 0;
}

//TTC: 29:38