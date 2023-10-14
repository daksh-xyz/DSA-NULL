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
        printf("No memory !");
        return;
    }
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    printf("Enter data: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    last = head;
    for(int i = 1; i < n; i++){
        struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
        if(NewNode == NULL){
            printf("No mem !");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &NewNode->data);
        NewNode->next = NULL;
        NewNode->prev = last;
        last->next = NewNode;
        last = NewNode;
    }
}

void Delete(){
    int pos, i = 1;
    struct DLL *curr = head;
    struct DLL *previous = head;
    printf("Enter position of element: ");
    scanf("%d", &pos);
    while(i < pos-1 || curr != NULL){
        previous = previous->next;
        curr = curr->next;
    }
    curr = curr->next;
    previous->next = curr->next;
    free(curr);

}

void Display(){
    struct DLL *curr =  head;
    while(curr != NULL){
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

void main(){
    Create();
    Display();
    Delete();
    Display();
}