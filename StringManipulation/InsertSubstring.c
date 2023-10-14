#include<stdio.h>
#include<string.h>

void main(){
    int lString, lSub, pos;
    char String[150], Sub[50];
    printf("Enter string: ");
    gets(String);
    lString = strlen(String);
    printf("Enter sub-string to be inserted: ");
    gets(Sub);
    lSub = strlen(Sub);
    printf("Enter position where string is to be inserted: ");
    scanf("%d", &pos);
    lString += lSub;
    for(int i = lString; i > pos; i--){
        String[i] = String[i-lSub];
    }
    for(int i = 0; i < lSub; i++){
        String[i+ pos] = Sub[i];
    }
    puts(String);
}