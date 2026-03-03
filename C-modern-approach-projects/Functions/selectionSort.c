/*
Write a program that asks the user to enter a series of integers (which it stores in an array),
then sorts the integers by calling the function s e le c tio n _ s o rt. When given an array
with n elements, s e le c tio n - s o rt must do the followine *~:
1. Search the array to find the largestelemenl. then move it to the last position in the array.
2. Call itself recursively to sort the first n - 1 elements ofthe array
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void selectionSort(int array[], int length);

int main(void)
{
    int arr[MAX];

    printf("Enter series of 10 integers: ");
    for(int i = 0; i < MAX; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);

    printf("\n\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}

void selectionSort(int arr[], int len)
{
    printf("\nLen: %d: ", len);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    if(len == 1) return;

    int maxIdx = arr[0];
    for(int i = 1; i < len; i++)
    {
        if(maxIdx > arr[i])
        {
           arr[i-1] = arr[i];
           arr[i] = maxIdx;
        }
        else
        {
            maxIdx = arr[i];
        }
        
    }

    selectionSort(arr, len-1);
}