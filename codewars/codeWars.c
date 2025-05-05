#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int *arr;
    arr = (int *) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the Size:(odd number only) ");
    scanf("%d", &size);
    
    printf("Enter the values: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nSorted values in ascending order:\n ");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1] ){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;

            }
        }
    }


    while(size > 1){

        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size-=2;
    }

    if (size == 1) {
        printf("%d\n", arr[0]);
    }

    free(arr);
}