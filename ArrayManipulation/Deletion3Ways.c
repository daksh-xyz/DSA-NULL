#include<stdio.h>

void DeletefromStart(int arr[], int *size){
    printf("Deleting element from start...\n");
    for(int i = 0 ; i < *size ; i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
    for (int  i = 0; i < *size ; i++){
        printf("%d ", arr[i]);
    }
    
}

void Remove(int arr[], int *size){
    int pos = 0;
    if(pos > *size || pos < 0){
        printf("Invalid index !");
        return;
    }
    printf("Enter position of element to be deleted: ");
    scanf("%d", &pos);
    for(int i = pos; i < *size ; i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
    for (int  i = 0; i < *size ; i++){
        printf("%d ", arr[i]);
    }
}

void pop(int arr[], int *size){
    printf("Popping elements...");
    (*size)--;  
    for (int  i = 0; i < *size ; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    DeletefromStart(arr, &size);
    Remove(arr, &size);
}