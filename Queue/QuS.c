#include<stdio.h>
#define MAX 5

int top1 = -1, top2 = -1, count = 0;

int stack1[MAX], stack2[MAX];

void enqueue(int data){
    if (top1 == MAX - 1) {
        printf("Queue is full, dequeue elements before enqueuing\n");
    } else {
        stack1[++top1] = data;
        count++;
    }
}

void dequeue(){
    if (top1 == -1 && top2 == -1) {
        printf("\nQueue is empty\n\n");
        return;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    printf("Dequeued element: %d\n", stack2[top2--]);
    count--;
    if (top1 == -1) {
        while (top2 != -1) {
            stack1[++top1] = stack2[top2--];
        }
    }
}

void display(){
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    
    // Display elements in stack1
    printf("|");
    for (int i = 0; i <= top1; i++) {
        printf(" %d |", stack1[i]);
    }
    printf("\n");

}

void main(){
    while(1){
        int ch;
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int data;
            printf("Enter the data you want to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("\nInvalid choice !\n");
            break;
        }
    }
}