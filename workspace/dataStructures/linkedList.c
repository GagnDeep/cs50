#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

void init(linkedList *);
int loadFromFile(linkedList *,char *);
void createListFromRandomNumbers(linkedList *,int );
void insertAtHead(linkedList *,int);
void insertAtTail(linkedList *,int);
void printListDetail(linkedList *);
void printList(linkedList *);
Node * find(linkedList *,int, Node **);
int deleteFirst(linkedList *);
int deleteLast(linkedList *);
int deleteTarget(linkedList *,int);
void reverse(linkedList *);
void menu();
void printListForward(linkedList *);
void printListReverse(linkedList *);
void printRecForward(Node *);
void printRecReverse(Node *);

int main(){
    linkedList list;
    init(&list);
    menu();
    int choise,data,n;
    int quit = 0;
    Node *current = NULL, *prev = NULL;
    while(!quit){
        printf("Please input your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
            if(loadFromFile(&list,"data.txt")){
            printf("file has been loaded successfully\n");}else{printf("Error!");}
            break;
            case 2:
            printf("Enter the number of random numbers to be generated : ");
            scanf("%d",&n);
            createListFromRandomNumbers(&list, n);
            break;
            case 3:
            printf("Input Data to insert at Head : ");
            scanf("%d",&data);
            insertAtHead(&list,data);
            break;
            case 4:
            printf("Input Data to insert at Tail : ");
            scanf("%d",&data);
            insertAtTail(&list,data);
            break;
            case 5:
            printListDetail(&list);
            break;
            case 6:
            printList(&list);
            break;
            case 7:
            printf("Enter the element you want to find : ");
            scanf("%d",&data);
            current = find(&list,data,&prev);
            if(current == NULL){
                printf("\nSorry!! :(\nElement was not found\n");
            }else{
                printf("adddress of current node : %p and address of previous node : %p\n",current,prev);
            }
            break;
            case 8:
            n = deleteFirst(&list);
            if(n == -9999){
                printf("List Is empty\n");
            }else{
                printf("Element deleted Successfully!!! :) - deleted element : %d\n",n);
            }
            break;
            case 9:
            n = deleteLast(&list);
            if(n == -9999){
                printf("List is empty\n");
            }else{
                printf("Element deleted successfully!!! :) - deleted element : %d\n",n);
            }
            break;
            case 10:
            printf("Enter Target to find and delete : ");
            scanf("%d",&data);
            n = deleteTarget(&list, data);
            if(n == -9999){
                printf("Element wasn't found so could not be deleted :(\n");
            }else{
                printf("Target Successfully terminated :)\nDeleted element : %d\n",n);
            }
            break;
            case 11:
            reverse(&list);
            break;
            case 12:
            printListForward(&list);
            break;
            case 13:
            printListReverse(&list);
            break;
            default:
            printf("The option You selected is invalid!!! :(");
            exit(0);
        }
    }
}

void menu(){
    printf("Singly Linked List Operations\n");
    printf("---------------------------------------\n");
    printf("1. Load from file\n");
    printf("2. Generate Random numbers\n");
    printf("3. Insert at head\n");
    printf("4. Insert at tail\n");
    printf("5. Print List (Detail)\n");
    printf("6. Print list (Data only)\n");
    printf("7. Find\n");
    printf("8. Delete first\n");
    printf("9. Delete Last\n");
    printf("10. Delete a target node\n");
    printf("11. Reverse\n");
    printf("12. Traverse List(Forward)\n");
    printf("13. Traverse List(Reverse)\n");
    printf("14. Quit\n");
}

void init(linkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}
void insertAtTail(linkedList *listptr,int data){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    if(newNodePointer == NULL){
        printf("Unable to allocate Memory for new node\n");
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

void insertAtHead(linkedList *listptr,int data){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    if(newNodePointer == NULL){
        printf("Unable to allocate Memory for new node\n");
        return;
    }
    newNodePointer->data = data;
    newNodePointer->next = NULL;
    if(listptr->nodeCount == 0){
        listptr->tail = newNodePointer;
        listptr->head = newNodePointer;
    }else{
        newNodePointer->next = listptr->head;
        listptr->head = newNodePointer;
    }
    listptr->nodeCount++;
}
void printListDetail(linkedList *listptr){
    if(listptr->nodeCount == 0){
        printf("List is empty\n");
        return;
    }
    printf("printing the linked list in detail : \n");
    printf("HEAD : %p\n",listptr->head);
    Node *current;
    current = listptr->head;
    int counter=1;
    while(current != NULL){
        printf("%d. (%p)[%d|%p]\n",counter,current,current->data,current->next);
        current = current->next;
        counter++;
    }
    printf("TAIL : %p\n",listptr->tail);
}
void printList(linkedList *listptr){
    if(listptr->nodeCount == 0){
        printf("List is empty\n");
        return;
    }
    Node *current;
    current = listptr->head;
    while(current != NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}
Node * find(linkedList *listptr,int target, Node **prvptr){
    Node *current = listptr->head;
    *prvptr = NULL;
    while(current != NULL){
        if(current->data == target){
            break;
        }
        *prvptr = current;
        current = current->next;
    }
    return current;
}
int loadFromFile(linkedList *listptr, char *fileName){
    FILE *inputFile = fopen(fileName,"r");
    if(inputFile == NULL){
        printf("Unable to open file. Please make shure that file exists :(\n");
        return 0;
    }
    int data;
    fscanf(inputFile,"%d",&data);
    while(!feof(inputFile)){
        insertAtTail(listptr,data);
        fscanf(inputFile,"%d",&data);
    }
    fclose(inputFile);
    return 1;
}
void createListFromRandomNumbers(linkedList *listptr,int n){
    int i,k;
    srand(time(NULL));
    for(i=0;i<n;i++){
        k = rand()%1000;
        insertAtTail(listptr,k);
    }
}
int deleteFirst(linkedList *listptr){
    int data;
    Node *first = listptr->head;
    if(listptr->nodeCount == 0){
        return -9999;
    }
    if(listptr->nodeCount == 1){
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
int deleteLast(linkedList *listptr){
    if(listptr->nodeCount == 0){
        return -9999;
    }
    Node *current;
    Node *last = listptr->tail;
    int data = listptr->tail->data;
    if(listptr->nodeCount == 1){
        listptr->head = NULL;
        listptr->tail = NULL;
    }else{
        current = listptr->head;
        while(current->next != listptr->tail){
            current = current->next;
        }
        listptr->tail = current;
        current->next = NULL;
    }
    free(last);
    listptr->nodeCount--;
    return data;
}
int deleteTarget(linkedList *listptr, int data){
    Node *current = NULL, *prev = NULL;
    current = find(listptr, data, &prev);
    if(current == listptr->head){
        deleteFirst(listptr);
    }else if(current == listptr->tail){
        deleteLast(listptr);
    }else{
        data = current->data;
        prev->next = current->next;
        free(current);
        listptr->nodeCount--;
    }
    return data;
}
void reverse(linkedList *listptr){
    if(listptr->nodeCount <= 1)
    return;
    Node *p, *q, *r;
    q = NULL;
    p = listptr->head;
    r = p->next;
    while(1){
        p->next = q;
        if(p == listptr->tail)
        break;
        q = p;
        p = r;
        r = r->next;
    }
    listptr->tail = listptr->head;
    listptr->head = p;
}
void printListForward(linkedList *listptr){
    printRecForward(listptr->head);
}
void printListReverse(linkedList *listptr){
    printRecReverse(listptr->head);
}
void printRecForward(Node *p){
    if( p == NULL ){
        return;
    }
    printf("%4d",p->data);
    printRecForward(p->next);
}
void printRecReverse(Node *p){
    if( p == NULL ){
        return;
    }
    printRecReverse(p->next);
    printf("%4d",p->data);
}