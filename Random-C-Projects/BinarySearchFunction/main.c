#include <stdio.h>
#include <math.h>

int BinarySearch(int arr[], int start, int end, int target);

int main()
{
    int arr[] = {2, 4, 6, 7, 8, 10, 23, 25 ,44, 55, 342,444, 5555};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    int target = 5;

    printf("Search for a number:");
    scanf("%d", &target);

    int i = BinarySearch(arr, start, end, target); 

    if(i != 0) printf("Value %d is at index #%d", target, i);
    else printf("Value not found | or value is not present in the array\n");


}

int BinarySearch(int arr[], int start, int end, int target)
{
    if (start > end) return 0;
    int mid = floor(start + end) / 2;
    if(arr[mid] == target) return mid;

    if(arr[mid] > target) 
    {
        return BinarySearch(arr, start, mid-1, target);
    } else
    {
        return BinarySearch(arr, mid + 1, end, target);
    }  
}
