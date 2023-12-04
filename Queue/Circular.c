#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data){
    if ((front == 0 && rear == MAX-1) || ((rear+1) % MAX == front)){
        printf("\nQueue is Full");
        return;
    }else if (front == -1){
        front = rear = 0;
    }else if (rear == MAX-1 && front != 0){
        rear = 0;
    }else{
        rear++;
    }     
    queue[rear] = data;
}

void dequeue(){
    if(front == -1){
        printf("\nqueue is empty !");
        return;
    }
    int data = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else if(front == MAX -1){
        front = 0;
    }else{
        front++;
    }
    printf("\nData => %d", data);
}

// void display(){
//     int i = front;
//     while(i != rear){
//         printf("%d ", queue[i]);
//         if(i == MAX -1){
//             i = 0;
//         }
//         i++;
//     }
//     printf("%d ", queue[i]);
// }

void main(){
    enqueue(5);
    enqueue(1);
    enqueue(2);
    enqueue(6);
    enqueue(7);
    enqueue(22);
    enqueue(12);
    enqueue(34);
    enqueue(67);
    enqueue(45);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}