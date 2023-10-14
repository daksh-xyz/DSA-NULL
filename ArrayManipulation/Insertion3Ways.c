#include<stdio.h>

void InsertatBeg(int arr[], int *size){
    printf("Inserting element at beginning of the array...\n");
    int num;
    printf("Enter number to be inserted: ");
    scanf("%d", &num);
    (*size)++;
    for(int i = *size; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = num;
    for(int i = 0; i < *size; i++){
        printf("%d ", arr[i]);
    }
}

void Insertion(int arr[], int *size){
    printf("\nInserting element in the array...\n");
    int num, pos = 0;
    printf("Enter position at which number is to be inserted: ");
    scanf("%d", &pos);
    printf("Enter number to be inserted: ");
    scanf("%d", &num);
    (*size)++;
    for(int i = *size; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = num;
    for(int i = 0; i < *size; i++){
        printf("%d ", arr[i]);
    }
}

void append(int arr[], int *size){
    printf("\nInsert elements at the end...\n");
    int num;
    printf("Enter number to append: ");
    scanf("%d", &num);
    (*size)++;
    arr[*size-1] = num;
    for(int i = 0; i < *size; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    InsertatBeg(arr, &size);
    Insertion(arr, &size);
    append(arr, &size);
}