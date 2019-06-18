#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    struct Node *next;
    int data;
}Node;

typedef struct {
    Node *tail;
    int nodeCount;
}linkedList;

void init(linkedList *);
void createListFromRandomNumbers(linkedList *,int);
void insertNode(linkedList *,int);
void printList(linkedList *);
Node * find(linkedList *,int);
int deleteNode(linkedList *);
