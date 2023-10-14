#include<stdio.h>
#include<string.h>
// IamJaipur
// ai
void main(){
    int lString, lSub;
    char String[150], Sub[50];
    printf("Enter string: ");
    gets(String);
    lString = strlen(String);
    printf("Enter sub-string to be deleted: ");
    gets(Sub);
    lSub = strlen(Sub);
    for(int i = 0; i< lString - lSub ; i++){
        int j = 0;
        for(j=0; j < lSub; j++){
            if(String[i+j] != Sub[j]){
                break;
            }
        }
        if(j == lSub){
            for(int k = i; k <= lString - lSub; k++){
                String[k] = String[k + lSub];
            }
            lString -= lSub;
            i--;
        }
    }
    String[lString] = '\0';
    puts(String);
}