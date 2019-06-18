#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

void init(linkedList *);
void insertAtHead(linkedList *,int);
void insertAtTail(linkedList *,int);

int main(){
    return 0;
}

void insertAtTail(linkedList *listptr,int value){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    newNodePointer->data = value;
    newNodePointer->next = newNodePointer->previous = NULL;
    if(listptr->nodeCount == 0){
        listptr->head = listptr->tail = newNodePointer;
    }else{
        listptr->tail->next = newNodePointer;
        newNodePointer->previous = listptr->tail;
        listptr->tail = newNodePointer;
    }
}

void insertAtHead(linkedList *listptr,int value){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    newNodePointer->data = value;
    newNodePointer->next = newNodePointer->previous = NULL;
    if(listptr->nodeCount == 0){
        listptr->head = listptr->tail = newNodePointer;
    }else{
        listptr->head->previous = newNodePointer;
        newNodePointer->next = listptr->head;
        listptr->head = newNodePointer;
    }
    listptr->nodeCount++;
}


void init(linkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}