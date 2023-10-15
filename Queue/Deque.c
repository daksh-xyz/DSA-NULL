#include<stdio.h>
#define MAX 10

int deque[MAX];
unsigned int size = 0;
int front = -1, rear = -1;

int isEmpty(){
    return front == -1;
}

int isFull(){
    return(front == 0 && rear == MAX-1) || (front == rear +1);
}

void insertFront(int data){
    if (isFull()) {
        printf("Deque is full, cannot insert at the front.\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }else if(front == 0){
        front = MAX -1;
    }else{
        front--;
    }
    deque[front] = data;
    printf("Inserted %d at the front.\n", data);
}

void insertRear(int data){
    if (isFull()) {
        printf("Deque is full, cannot insert at the rear.\n");
        return;
    }
    if(rear == -1){
        front = 0;
        rear = 0;
    }else if(rear == MAX -1){
        rear = 0;
    }else{
        rear++;
    }
    deque[rear] =  data;    
    printf("Inserted %d at the rear.\n", data);
}

int deleteFront(){
    if(isEmpty()){
        printf("Deque is empty, cannot delete\n");
        return 0;
    }
    int data = deque[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else if(front == MAX -1){
        front = 0;
    }else{
        front++;
    }
    return data;
}

int deleteRear(){
    if(isEmpty()){
        printf("Deque is empty, cannot delete\n");
        return 0;
    }
    int data = deque[rear];
    if(rear == front){
        rear = -1;
        front = -1;
    }else if(rear == 0){
        rear = MAX -1;
    }else{
        rear--;
    }
    return data;
}

int main()
{
    int ch, data;

    while (1)
    {
        printf("--------------------------------------\n  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n--------------------------------------\n1. Insert at Front\n2. Insert at Rear\n3. Delete Front\n4. Delete Rear\n0. Exit\n--------------------------------------\nSelect an option: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter data to insert at Front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("\nEnter data to insert at Rear: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3: 
                if (isEmpty())
                    printf("Queue is empty.");
                else{ 
                    data = deleteFront();
                    printf("Data => %d", data);
                }
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty.");
                else{ 
                    data = deleteRear();
                    printf("Data => %d", data);
                }
                break;
            case 0:
                printf("Exiting from app.\n");
                return 0;
        
            default:
                printf("Invalid choice, please input number between (0-3).");
                break;
        }

        printf("\n\n");
    }
    return 0;
}