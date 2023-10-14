#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list* next;
}*head = NULL;

void InsertatBeg() {
    struct list* newData = (struct list*)malloc(sizeof(struct list));
    if (newData == NULL) {
        printf("Memory not available!\n");
        return;
    }

    printf("Enter an integer: ");
    scanf("%d", &newData->data);

    newData->next = head;  // Insert at the beginning
    head = newData;  // Update the head to point to the new node
}

void createSLL(){
    struct list *head = (struct list *)malloc(sizeof(struct list));
    if(head == NULL){
        printf("No memory available !");
        return;
    }
    struct list *curr = head;
    printf("Enter data to be entered:");
    scanf("%d", &curr->data);
    curr->next = NULL;
    for(int i = 2; i < 5 ; i++){
        struct list *newNode = (struct list *)malloc(sizeof(struct list));
        if(newNode == NULL){
        printf("No memory available !");
        return;
        }
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        curr->next = newNode;
        curr = newNode;
    }
}

void Insertion(){
    struct list *newNode = (struct list *)malloc(sizeof(struct list));
    int pos, count=0;
    if(newNode == NULL){
        printf("Memory not available !");
        return;
    }
    struct list *curr = head;
    printf("Enter position at which node is to be inserted: ");
    scanf("%d", &pos);
    printf("Enter an integer: ");
    scanf("%d", &newNode->data);
    for(int i = 2; i < pos; i++){
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void append(){
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    if(newNode == NULL){
        printf("Memory not available !");
        return;
    }
    printf("Enter integer to be appended: ");
    scanf("%d", &newNode->data);
    struct list *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = NULL;
}

void print() {
    struct list* current = head;
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void main() {
    // InsertatBeg();
    // InsertatBeg();
    // InsertatBeg();
    // print();
    createSLL();
    print();
    Insertion();
    print();
    append();
    print();
}
