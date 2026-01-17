/*
Modify the re p d ig it.c program of Section 8.1 so that it prints a table showing how
many limes each digil appears in the number:
Enter a number: 41271092
Digit: 0 1 2 3 4 5 6 7 8 9
Occurrences: 1 2 2 0 1 0 0 1 0 1
*/

#include <stdio.h>
#include <string.h>

#define OCCUR_LEN sizeof(occurence) / sizeof(occurence[0])

int main(void)
{
    char input[100];
    int occurence[10] = {0};

    printf("Enter a number: ");
    scanf("%s", input);

    for(size_t i = 0; i < strlen(input); i++)
    {
        int digit = input[i] - '0';
        occurence[digit]++;
    }

    printf("Digits:     0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurence:  ");
    for(size_t i = 0; i < OCCUR_LEN; i++)
    {
        printf("%d ", occurence[i]);
    }


    return 0;
}

//TTC: 13:12