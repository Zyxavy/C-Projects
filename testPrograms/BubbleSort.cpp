#include <iostream>
using namespace std;

void bubbleSort(int array[], int size);
int binarySearch(int array[], int size, int element);

int main(){

    int array[] = {10, 9, 2 ,3 ,8 , 5,6, 4, 11, 23, 1,23,234,235,345,2,123,
    25,234,23,425,1,35,56,78,5,2123,4,57,456,678,567,967,4632,34,235,34,53,
    4,14,23,345,2,34,25,23,4245,2,4,45,2,342,3 };
    int size = sizeof(array) / sizeof(array[0]);
    int element, index;

    cout << "current array: ";
    for(int element : array){
        cout << element << ' ';  
    }

    bubbleSort(array, size);
    cout << "\nAfter sort: ";

    for(int element : array){
        cout << element << ' ';  
    }

    cout << "\n\nsearch for an elements? : ";
    cin >> element;

    index = binarySearch(array, size, element);

    if(index != -1){
        cout << "Element is at index: " << index;
    } else {
        cout << "Element not found :< ";
    }


    

    return 0;
}

void bubbleSort(int array[], int size){
    int temp;

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i- 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

}

int binarySearch(int array[], int size, int element){
   int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == element)
            return mid;

        if (array[mid] < element)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
