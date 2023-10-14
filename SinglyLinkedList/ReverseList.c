#include<stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list* next;
}*head;

void createList(int n){
    struct list *curr;
    head = (struct list *)malloc(sizeof(struct list));
    if(head == NULL){
        printf("Unable to allocate memory.");
    }
    else{
        printf("Enter the data of node 1: ");
        scanf("%d", &head->data); // Link the data field with data
        head->next = NULL; // Link the address field to NULL
        curr = head;
        for(int i=2; i<=n; i++){
            struct list *newNode = (struct list *)malloc(sizeof(struct list));
            if(newNode == NULL){
                printf("Unable to allocate memory.");
                break;
            }
            else{
                printf("Enter the data of node %d: ", i);
                scanf("%d", &newNode->data); // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL
                curr->next = newNode; // Link previous node i.e. curr to the newNode
                curr = curr->next;
            }
        }
    }
}

void Reverse(){
    struct list *prev, *curr;
    if(head != NULL){
        prev = head;
        curr = head->next;
        head = head->next;

        prev->next = NULL;

        while(head != NULL){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        head = prev;
    }
}

void print() {
    struct list *curr = head;
    while (curr != NULL) {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}


void main(){
    createList(5);
    print();
    Reverse();
    print();
}