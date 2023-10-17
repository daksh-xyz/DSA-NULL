#include<stdio.h>
#define MAX 10

int top = -1;
int stack[MAX];

void push(){
    int data;
    if(top == MAX - 1){
        printf("Stack Overflow !");
        return;
    }
    top++;
    printf("Enter data: ");
    scanf("%d", &data);
    stack[top] = data;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow !");
        return;
    }
    int data = stack[top];
    printf("Data => %d\n", data);
    top--;
}

void main(){
    push();
    push();
    pop();
    pop();
}