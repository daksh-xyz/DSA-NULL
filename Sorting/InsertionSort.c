#include<stdio.h>

void main(){
    int size, key;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter an integer: ");
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < size; i++){
        int j = i-1;
        key =  arr[i];
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i = 0; i < size ; i++){
        printf("%d ", arr[i]);
    }
}