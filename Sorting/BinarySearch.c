#include<stdio.h>

int BinarySearch(int arr[], int low, int high, int target){
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
    }
    return -1;
}

int InsertionSort(int arr[], int size, int x){
    for(int i = 1; i<size; i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    int result = BinarySearch(arr, 0, size-1, x);
    if(result == -1){
        printf("Element not found!");
    }
    else{
        printf("Element found at index: %d", result);
    }
}

void main(){
    int size, x;
    printf("enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size; i++){
        printf("Enter integer: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter integer to be found: ");
    scanf("%d", &x);
    int SortedArray = InsertionSort(arr, size, x);
}