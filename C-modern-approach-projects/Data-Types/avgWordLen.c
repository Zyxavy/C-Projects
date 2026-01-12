/*
Write a program that calculates the average word length for a sentence:kjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA
Enter a sentence: It was deja vu all over again.
Average word length: 3.4
For simplicity, your program should consider a punctuation mark to be part of the word lo
which it is attached. Display the average word length to one decimal place
*/
#include <stdio.h>

int main(void)
{
    float avgWordLen;
    char ch;
    int wordCount = 1, letterCount = 0;

    printf("Enter a sentence: ");

    while((ch = getchar()) != '\n')
    {
        if(ch == ' ')
        {
            wordCount++;
            continue;
        }
        letterCount++;
    }

    avgWordLen = (float) letterCount / (float) wordCount;

    printf("Average word length: %.1f", avgWordLen);
    return 0;
}

//TTC: 11:30