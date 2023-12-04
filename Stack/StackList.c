#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
}*top;

void Push(){
    struct Stack *NewNode = (struct Stack*)malloc(sizeof(struct Stack));
    if(NewNode == NULL){
        printf("no memory!");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &NewNode->data);
    NewNode->next = top;
    top = NewNode;
}

void pop(){
    struct Stack *topNode = top;
    int data = topNode->data;
    printf("Top: %d", data);
    top=top->next;
    free(topNode);
}

void main(){
    Push();
    Push();
    Push();
    pop();
    pop();
    pop();
}