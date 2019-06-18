#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node *next;
}Node;

typedef struct {
struct Node *head;
struct Node *tail;
int nodeCount;
}LinkedList;

// function prototypes
void initList(LinkedList *);
void insertOrder(LinkedList *, int);
void printList(LinkedList *);
// Precondition: LinkedList object pointed by listptr must be existing.
// Return Value: Nothing
void initList(LinkedList *lstPtr){
lstPtr->head = NULL;
lstPtr->tail = NULL;
lstPtr->nodeCount = 0;
}

void printList(LinkedList *lstPtr){
if (lstPtr->nodeCount == 0){
printf("Linked list is empty\n");
return;
}
Node *current = lstPtr->head;
while(current != NULL){
printf("%d\n", current->data);
current = current->next;
}

} // end of printList

void insertOrder(LinkedList *listptr, int v){
printf("started\n");
// You code should go here
Node *newNodePointer = (Node *)malloc(sizeof(Node));

if(newNodePointer == NULL){
    printf("Unable to allocate memory for new node\n");
    return;
}
    newNodePointer->data = v;
    newNodePointer->next = NULL;
Node *current = listptr->head;
if(listptr->head == NULL || newNodePointer->data < current->data){
    newNodePointer->next = listptr->head;
    listptr->head = newNodePointer;
}else{
    while(current->next != NULL && newNodePointer->data>current->next->data){

    current = current->next;
  }
  newNodePointer->next = current->next;
  current->next = newNodePointer;

 }
 listptr->nodeCount++;
 printf("inserted : %d\n",v);
}

int main(){
LinkedList ordList;
initList(&ordList);
insertOrder(&ordList, 100);
insertOrder(&ordList, 10);
insertOrder(&ordList, 200);
insertOrder(&ordList, 70);
insertOrder(&ordList, 80);
insertOrder(&ordList, 50);
printList(&ordList);//should print: 10 50 70 80 100 200
return 0;
}