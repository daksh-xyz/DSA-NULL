#include<stdio.h>

void main(){
    int arr1[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, arr2[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, result[3][3];
    for(int i = 0; i < 3; i++){
        for(int j =0; j < 3; j++){
            result[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp = 0, k = 0;
            while(k<3){
                temp += arr1[i][k]*arr2[k][j];
                k++;
            }
            result[i][j] = temp;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}