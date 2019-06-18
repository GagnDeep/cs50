#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

void init(linkedList *);
void insertAtTail(linkedList *,int);
int deleteFirst(linkedList *);

int main(){
    linkedList list;
    init(&list);
    int choise,data;
    printf("1. Enqueue\n2. Dequeue\n");
    while(1){
        printf("enter your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
            printf("Enter element to be enqueued : ");
            scanf("%d",&data);
            insertAtTail(&list,data);
            break;

            case 2:
            data = deleteFirst(&list);
            if(data == -9999){
                printf("queue underflow\n");

            }else{
                printf("Deleted element : %d\n",data);
            }
            break;
        }
    }
    return 0;
}
void init(linkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}
void insertAtTail(linkedList *listptr,int data){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    if(newNodePointer == NULL){
        printf("Unable to allocate memory for new node\n");
        return;
    }
    newNodePointer->data = data;
    newNodePointer->next = NULL;
    if(listptr->nodeCount == 0){
        listptr->head = newNodePointer;
        listptr->tail = newNodePointer;
    }else{
        listptr->tail->next = newNodePointer;
        listptr->tail = newNodePointer;
    }
    listptr->nodeCount++;
}
int deleteFirst(linkedList *listptr){
    int data;
    Node *first = listptr->head;
    if(listptr->nodeCount == 0){
        return -9999;
    }
    if(listptr->nodeCount == 1){
        data = listptr->head->data;
        listptr->head = NULL;
        listptr->tail = NULL;
    }else{
        data = listptr->head->data;
        listptr->head = listptr->head->next;
    }
    free(first);
    listptr->nodeCount--;
    return data;
}
