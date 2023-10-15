#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct q{
    int data;
    struct q *next;
}*front, *rear;

unsigned int size = 0;

int isEmpty(){
    return (size <= 0);
}

int isFull(){
    return (size > MAX-1);
}

int enqueue(int data){
    if(isFull()){
        return 0;
    }
    struct q *newNode = (struct q *)malloc(sizeof(struct q));
    newNode->next = NULL;
    newNode->data = data;
    if(rear){
        rear->next = newNode;
    }
    rear = newNode;
    if(front == NULL){
        front = rear;
    }
    size++;
    return 1;
}

int dequeue(){
    if(isEmpty()){
        return 0;
    }
    struct q *toDequeue = front;
    int data = toDequeue->data;
    front = front->next;
    size--;
    free(toDequeue);
    return data;
}

int main()
{
    int ch, data;

    while (1)
    {
        printf("--------------------------------------\n  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n--------------------------------------\n1. Enqueue\n2. Dequeue\n3. Size\n0. Exit\n--------------------------------------\nSelect an option: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                if (enqueue(data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = dequeue();
                if (data == 0)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3: 
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Queue size => %d", size);

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