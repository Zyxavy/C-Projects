/*
Write a program that asks the user for a two-digit number, ihen prints the English word for
ihe number:
Enter a two-digit number: 45
You entered the number forty-five.
Hint: Break the number into two digits. Use one sw itc h statement to print the word for the
first digit (“twenty:’ “thirty,” and so forth). Use a second s w itc h statement to print the
word for the sccond digit. Don’t forget that lhc numbers between 11 and 19 require special
treatment.
*/
#include <stdio.h>

int main(void)
{
    int num, dig1, dig2;
    char* word = "";
    char* word2 = "";

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    if(num >= 10 && num <= 19)
    {
        switch (num)
        {
            case 10: word = "Ten"; break; 
            case 11: word = "Eleven"; break;
            case 12: word = "Twelve"; break;
            case 13: word = "Thirteen"; break;
            case 14: word = "Fourteen"; break;
            case 15: word = "Fifteen"; break;
            case 16: word = "Sixteen"; break;
            case 17: word = "Seventeen"; break;
            case 18: word = "Eighteen"; break;
            case 19: word = "Nineteen"; break;
            default: break;
        }
    }
    else
    {
        dig2 = num % 10;
        num /= 10;
        dig1 = num;

        switch (dig1)
        {
            case 2: word = "Twenty"; break;
            case 3: word = "Thirty"; break;
            case 4: word = "Fourty"; break;
            case 5: word = "Fifty"; break;
            case 6: word = "Sixty"; break;
            case 7: word = "Seventy"; break;
            case 8: word = "Eighty"; break;
            case 9: word = "Ninety"; break;
            default: break;
        }
        
        switch (dig2)
        {
            case 1: word2 = "-One"; break;
            case 2: word2 = "-Two"; break;
            case 3: word2 = "-Three"; break;
            case 4: word2 = "-Four"; break;
            case 5: word2 = "-Five"; break;
            case 6: word2 = "-Six"; break;
            case 7: word2 = "-Seven"; break;
            case 8: word2 = "-Eight"; break;
            case 9: word2 = "-Nine"; break;
            default: break;
        }

    }

    printf("You entered the number: %s%s", word, word2);

    return 0;
}