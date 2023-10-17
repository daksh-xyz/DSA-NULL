#include<stdio.h>
#define MAX 10

int queue[MAX];
unsigned int size = 0;
int front = -1, rear = -1;

void enqueue(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if ((front == 0 && rear == MAX-1) || ((rear+1) % MAX == front)){
        printf("\nQueue is Full");
        return;
    }else if (front == -1){
        front = rear = 0;
        queue[rear] = data;
    }else if (rear == MAX-1 && front != 0){
        rear = 0;
        queue[rear] = data;
    }else{
        rear++;
        queue[rear] = data;
    }     
}

void dequeue(){
    if(front == -1){
        printf("queue is empty !");
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
    size--;
}

void display(){
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",queue[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", queue[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

void main(){
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}