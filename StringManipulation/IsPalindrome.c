#include<stdio.h>
#include<string.h>

void main(){
    char String[100], temp[0];
    printf("Enter a string: ");
    gets(String);
    int lString = strlen(String), Tlen = strlen(String) - 1;
    for(int i = 0; i < lString/2; i++){
        if(String[i] != String[Tlen]){
            printf("Entered string is not a palindrome...");
            return;
        }
        Tlen--;
    }
    printf("It is a palindrome");
}