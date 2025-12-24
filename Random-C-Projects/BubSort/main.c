#include <stdlib.h>
#include <stdio.h>


int bubbleSort(int arr[], size_t size);
int printArray(int arr[], size_t size);

int main(){
    int arr[] = {0,4,2,1,5,3,6,7};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, size);
    printArray(arr, size);
    
    return 0;
}

int bubbleSort(int arr[], size_t size){
    int temp;
    
  for(size_t i = 0; i < size ; i++)
    {
         for(size_t j = 0; j < size - i; j++)
         {   
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

            
         }
    }
}

int printArray(int arr[], size_t size){

    for(size_t i = 0; i < size; i++){
        printf("%i ", arr[i]);
    }
}

