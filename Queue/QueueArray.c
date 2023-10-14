#include<stdio.h>
#define MAX 10

int queue[MAX];
unsigned int size = 0;
unsigned int rear = MAX - 1;
unsigned int front = 0;

int isFull(){
    return(size == MAX);
}

int isEmpty(){
    return(size == 0);
}

int enqueue(int data){
    if(isFull()){
        return 0;
    }
    size++;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
    return 1;
}

int dequeue(){
    if(isEmpty()){
        return 0;
    }
    int data = queue[front];
    front = (front+1) % MAX;
    size--;
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