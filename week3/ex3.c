#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node *parent;
    struct Node *node;
    int id;
} Node;
int size;
void insert(Node *node, int newID, int after){
    Node *temp = node;
    int i = 0;
    while((*temp).node != NULL && i<=after){
        temp = (*temp).node;
        i++;
    }
    if(after>size-1){
        (*temp).node = malloc(sizeof(Node));
        (*temp).id = newID;
        (*(*temp).node).parent = temp;
        (*(*temp).node).node = NULL;
    }else{
        Node new;
        new.node = (*temp).node;
        (*(*temp).parent).node = &new;
        new.id = newID;
    }
    size++;
}

void printAll(struct Node *node){
    Node *temp;
    temp = node;
    while(temp != NULL){
        printf("This is value of node id: %d\n", (*temp).id);
        temp = (*temp).node;
    };

}

int main(){
    Node root;
    root.node = NULL;
    insert(&root, 3, 1);
    insert(&root, 7, 1);
    printAll(&root);
    insert(&root, 9, 0);
    printAll(&root);
    return 0;
}