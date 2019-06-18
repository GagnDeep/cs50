#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

int deleteAtBeg(linkedList *);
int deleteAtEnd(linkedList *);
int deleteAtLoc(linkedList *,int);
int loadFromFile(linkedList *,char *);
void traverse(linkedList *);
void menu();
Node * find(linkedList *,int, Node **);
void insertAtEnd(linkedList *,int);

int main(){
    linkedList list;
    list.head = list.tail = NULL;
    list.nodeCount = 0;
    menu();
    int choise,data,n,target;
    int quit = 0;
    while(!quit){
        printf("\nPlease input your choise : ");
        scanf("%d",&choise);
      switch(choise){

        case 1:
            quit = 1;
            break;

        case 2:
            if(loadFromFile(&list,"data.txt")){
                printf("file has been loaded successfully\n");
            }else{
                printf("Error!");
            }
            break;

        case 3:
            traverse(&list);
            break;

        case 4:
            n = deleteAtBeg(&list);
            if(n == -9999){
                printf("List Is empty\n");
            }else{
                printf("Element deleted Successfully!!! :) - deleted element : %d\n",n);
            }
            break;

        case 5:
            n = deleteAtEnd(&list);
            if(n == -9999){
                printf("List is empty\n");
            }else{
                printf("Element deleted successfully!!! :) - deleted element : %d\n",n);
            }
            break;

        case 6:
            printf("Enter Target to find and delete : ");
            scanf("%d",&data);
            n = deleteAtLoc(&list, data);
            if(n == -9999){
                printf("Element wasn't found so could not be deleted :(\n");
            }else{
                printf("Target Successfully terminated :)\nDeleted element : %d\n",n);
            }
            break;
        }
    }
}
void menu(){
    printf("Operations\n");
    printf("---------------------------------------\n");
    printf("1. Quit\n");
    printf("2. Load from file\n");
    printf("3. Traverse\n");
    printf("4. Delete At Begining\n");
    printf("5. Delete At End\n");
    printf("6. Delete At Location\n");
    printf("---------------------------------------");
}

// ********************************
//      Delete at Begining
// ********************************

int deleteAtBeg(linkedList *listptr){
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

// ********************************
//      Delete at End
// ********************************

int deleteAtEnd(linkedList *listptr){
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

// ********************************
//      Delete At Location
// ********************************

int deleteAtLoc(linkedList *listptr, int data){
    Node *current = NULL, *prev = NULL;
    current = find(listptr, data, &prev);
    if(current == listptr->head){
        deleteAtBeg(listptr);
    }else if(current == listptr->tail){
        deleteAtEnd(listptr);
    }else{
        data = current->data;
        prev->next = current->next;
        free(current);
        listptr->nodeCount--;
    }
    return data;
}

// ********************************
// ********************************

int loadFromFile(linkedList *listptr, char *fileName){
    FILE *inputFile = fopen(fileName,"r");
    if(inputFile == NULL){
        printf("Unable to open file. Please make shure that file exists :(\n");
        return 0;
    }
    int data;
    fscanf(inputFile,"%d",&data);
    while(!feof(inputFile)){
        insertAtEnd(listptr,data);
        fscanf(inputFile,"%d",&data);
    }
    fclose(inputFile);
    return 1;
}
void traverse(linkedList *listptr){
    if(listptr->nodeCount == 0){
        printf("List is empty\n");
        return;
    }
    Node *current;
    current = listptr->head;
    while(current != NULL){
        printf("%4d",current->data);
        current = current->next;
    }
    printf("\n");
}
void insertAtEnd(linkedList *listptr,int data){
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