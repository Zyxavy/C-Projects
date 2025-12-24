#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int* MergeSort(int *arr, int len);
int* merge(int *leftArr, int leftLen, int *rightArr, int rightLen);
void sliceArray(int *original, int start, int end, int *result);
void push(int *arr, int *size, int value);

int main()
{
    clock_t start = clock();
    int arr[] = {12, 3, 2 ,5 ,7, 24, 4, 23, 55, 33, 6, 8, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int* sorted = MergeSort(arr, len);
    
    //print sorted arr
    for(int i = 0; i < len; i++ )
    {
        printf(" %d", sorted[i]);
    }

    free(sorted);
    
    //time code exec
    clock_t end = clock();
    printf("\n\nTime: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

}

void sliceArray(int *original, int start, int end, int *result) {
    int j = 0;
    for (int i = start; i < end; i++) {
        result[j++] = original[i];
    }
}

void push(int *arr, int *size, int value) {
    arr[*size] = value;
    (*size)++;
}

int* MergeSort(int *arr, int len) {
    if (len < 2) return arr;

    int mid = len / 2;
    int *leftArr = malloc(mid * sizeof(int));
    int *rightArr = malloc((len - mid) * sizeof(int));

    sliceArray(arr, 0, mid, leftArr);
    sliceArray(arr, mid, len, rightArr);

    int *sortedLeft = MergeSort(leftArr, mid);
    int *sortedRight = MergeSort(rightArr, len - mid);

    int *merged = merge(sortedLeft, mid, sortedRight, len - mid);

    free(leftArr);
    free(rightArr);

    return merged;
}

int* merge(int *leftArr, int leftLen, int *rightArr, int rightLen) {
    int *resultArr = malloc((leftLen + rightLen) * sizeof(int));
    int leftIndex = 0, rightIndex = 0, resultLen = 0;

    while (leftIndex < leftLen && rightIndex < rightLen) {
        if (leftArr[leftIndex] < rightArr[rightIndex]) {
            push(resultArr, &resultLen, leftArr[leftIndex++]);
        } else {
            push(resultArr, &resultLen, rightArr[rightIndex++]);
        }
    }

    while (leftIndex < leftLen) {
        push(resultArr, &resultLen, leftArr[leftIndex++]);
    }

    while (rightIndex < rightLen) {
        push(resultArr, &resultLen, rightArr[rightIndex++]);
    }

    return resultArr;
}
