#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *next;
    struct DLL *prev;
}*head, *last;

void Create(){
    head = (struct DLL *)malloc(sizeof(struct DLL));
    if(head == NULL){
        printf("No memory");
        return;
    }
    int n;
    printf("Enter number of nodes to be created: ");
    scanf("%d", &n);
    printf("Enter data: ");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    last = head;
    for(int i =1; i <n; i++){
        struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
        if(NewNode == NULL){
            printf("No memory");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &NewNode->data);
        NewNode->prev = last;
        NewNode->next = NULL;
        last->next = NewNode;
        last = NewNode;
    }
}

void InsertAtBeg(){
    struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    printf("Enter data: ");
    scanf("%d", &NewNode->data);
    NewNode->next = head;
    NewNode->prev = NULL;
    head->prev = NewNode;
    head = NewNode;
}

void Insertion(){
    struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    int pos, i = 0;
    if(NewNode == NULL){
        printf("No memory");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &NewNode->data);
    printf("Enter position of node: ");
    scanf("%d", &pos);
    if(pos == 0){
        InsertAtBeg();
    }
    else{
        struct DLL *current = head;
        struct DLL *previous = head;
        while(i < pos-1){
            previous = previous->next;
            current = current->next;
            i++;
        }
        current = current->next;
        NewNode->next = previous->next;
        NewNode->prev = previous;
        previous->next = NewNode;
        current->prev = NewNode;
    }
}

void append(){
    struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    struct DLL *curr = head;
    if(NewNode == NULL){
        printf("No memory");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &NewNode->data);
    while(curr->next != NULL){
        curr = curr->next;
    }
    NewNode->next=  NULL;
    NewNode->prev = curr;
    curr->next = NewNode;
}

void Display(){
    struct DLL *curr = head;
    while(curr != NULL){
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void main(){
    Create();
    Display();
    InsertAtBeg();
    Display();
    Insertion();
    Display();
}