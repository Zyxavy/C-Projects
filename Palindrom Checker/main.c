#include <stdio.h>
#include <math.h>
#include <windows.h>

int checkForPalindrome(int *a);
int main(){
    int palindome, num, remainder, result =0;
    int *Ptrpalindrome = &palindome;
    int *PtrRemainder = &remainder;
    int *PtrResult = &result;
    printf("Enter Palindrome number: ");
    scanf("%d", &*Ptrpalindrome);
    num = *Ptrpalindrome;

    for(int i = 0; i < floor(log10(abs(*Ptrpalindrome))) + 1; i++){
        *PtrRemainder = num % 10; // gets the remainder or the last digit
        printf("remainder: %d\n", *PtrRemainder);
        Sleep(500);
        *PtrResult = *PtrResult*10 + *PtrRemainder; // sets the last digit as the first digit
        printf("result: %d\n", *PtrResult);
        Sleep(500);
        num = num/10; // removes the last digit from the integer
        printf("num: %d\n", num);
        Sleep(500);
    }

    if(result == *Ptrpalindrome){
        printf("It is a Palindrome!!");
    } else{
        printf("it is not a Palindrome");
    }


    return 0;
}



