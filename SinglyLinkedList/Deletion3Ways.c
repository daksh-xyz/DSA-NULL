#include<stdio.h>
#include<stdlib.h>

struct list{
    int data;
    struct list *next;
}*head = NULL; 

void createSLL(){
    printf("Enter 5 elements: ");
    for(int i = 0; i < 5; i++){
        struct list *newNode = (struct list *)malloc(sizeof(struct list));
        if(newNode == NULL){
            printf("Memory not available !");
            return;
        }
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }
}

void print() {
    struct list* current = head;
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deletehead(){
    printf("Deleting head...\n");
    struct list *curr = head;
    head = head->next;
    free(curr);
}

void deleetlast(){
    printf("Deleting from last...\n");
    struct list *toDelete, *SecondLast;
    if(head == NULL){
        printf("List is already empty.");
    }
    else{
        toDelete = head;
        SecondLast = head;
        while(toDelete->next != NULL){
            SecondLast = toDelete;
            toDelete = toDelete->next;
        }
        SecondLast->next = NULL;
        free(toDelete);
    }
}

void deleteNnode(){
    struct list *toDelete = head, *prev = head; 
    int pos;
    printf("Enter position of node to delete: ");
    scanf("%d", &pos);
    if(pos == 1){
        deletehead();
        return;
    }
    for(int i = 2; i <= pos; i++){
        prev = toDelete;
        toDelete = toDelete->next;
        if(toDelete == NULL){
            break;
        }
    }
    if(toDelete != NULL){
        prev->next = toDelete->next;
        toDelete->next = NULL;
        free(toDelete);
    }
    else{
        printf("Invalid position: Index out of bounds");
        deleteNnode();
    }
}

void main(){
    createSLL();
    print();
    deletehead();
    print();
    deleetlast();
    print();
    deleteNnode();
    print();
}