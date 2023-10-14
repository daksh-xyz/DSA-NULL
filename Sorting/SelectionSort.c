#include<stdio.h>

void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter integer: ");
        scanf("%d", &arr[i]);
    }
    int min_index;
    for(int i = 0; i<size; i++){
        min_index = i;
        for(int j = i+1; j<size; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}