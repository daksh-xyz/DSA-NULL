#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list* next;
}*head;

void Create(){
    int size;
    head = (struct list *)malloc(sizeof(struct list));
    if(head == NULL){
        printf("No mem !");
        return;
    }
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter data: ");
    scanf("%d", &head->data);
    head->next = NULL;
    struct list *curr = head;
    for(int i = 1; i < size; i++){
        struct list *NewNode = (struct list *)malloc(sizeof(struct list));
        printf("Enter data: ");
        scanf("%d", &NewNode->data);
        NewNode->next = NULL;
        curr->next = NewNode;
        curr = NewNode;        
    }
    curr->next = head;
}

void Display(){
    struct list *curr = head;
    do {
        printf("%d --> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("NULL");
}


void main(){
    Create();
    Display();
}