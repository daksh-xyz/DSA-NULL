#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
struct node {
    int key;
    struct node *left, *right;
};

struct stack{
    struct node *data[MAX];
    int top;
};

void push(struct stack *s, struct node *root){
    if(s->top != MAX){
        s->top++;
        s->data[s->top] = root;
    }else{
        printf("Stack full !");
    }
}

struct node *pop(struct stack *s){
    struct node *h;
    if(s->top == -1){
        printf("Stack empty!");
    }else{
        h = s->data[s->top];
        s->top--;
    }
    return h;
}

// Inorder without recursion
struct stack *inorderS(struct node *root){
    struct stack *s;
    struct node *Node = root;
    s->top = -1;
    do{
        while(Node != NULL){
            push(&s, Node);
            Node = Node->left;
        }
        if(s->top != -1){
            Node = pop(&s);
            printf("%d", Node->key);
        }
    }while(Node != NULL || (s->top != -1));
}

// A utility function to create a new BST node
struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to insert
struct node* insert(struct node* node, int key){
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node* search(struct node* root, int key){
    if (root == NULL || root->key == key)
        return root;
    // Key is greater than root's key
    if (key > root->key)
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

struct node* deleteNode(struct node* root, int k){
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (k < root->key) {
        root->left = deleteNode(root->left, k);
    }
    else if (k > root->key) {
        root->right = deleteNode(root->right, k);
    }
 
    // We reach here when root is the node
    // to be deleted.
    if(root->left == NULL){
        return root->right;
    }
    if(root->right == NULL){
        return root->left;
    }

    int minimum = root->right->key;
    while(root->left != NULL){
        minimum = root->left->key;
        root = root->left;  
    }

    root->key = minimum;
    root->right = deleteNode(root->right, root->key);
}
struct node *inorder(struct node *root){
    if(root == NULL){
        return root;
    }
    root->left = inorder(root->left);
    printf("%d ", root->key);
    root->right = inorder(root->right);
}


void main(){
    struct node* root = NULL;

    printf("Enter item for the root: ");
    int rootKey;
    scanf("%d", &rootKey);
    root = insert(root, rootKey);

    insert(root, 20);
    insert(root, 90);
    insert(root, 30);
    inorderS(root);
    printf("Enter key to delete: ");
    int keyToDelete;
    scanf("%d", &keyToDelete);
    deleteNode(root, keyToDelete);
    inorder(root);
}