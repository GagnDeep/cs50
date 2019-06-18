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

int loadFromFile(linkedList *,char *);
void traverse(linkedList *);
void menu();
void insertAtEnd(linkedList *,int );
void insertAtBeg(linkedList *,int);
int insertAtLoc(linkedList *,int,int);
Node * find(linkedList *,int);

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
            printf("Input data you want to insert : ");
            scanf("%d",&data);
            insertAtEnd(&list,data);
            break;

        case 5:
            printf("Input data you want to insert : ");
            scanf("%d",&data);
            insertAtBeg(&list,data);
            break;

        case 6:
            printf("Enter target: ");
            scanf("%d", &target);
            printf("Input data: ");
            scanf("%d", &data);
            if (insertAtLoc(&list, target, data) == 1){
              printf("Insert after was successful\n");
            }
            else{
              printf("Insert after failed\n");
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
    printf("4. Insert At End\n");
    printf("5. Insert At Begining\n");
    printf("6. Insert At Location\n");
    printf("---------------------------------------");
}
// ********************************
//      Insert at End
// ********************************

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

// ********************************
//      Insert at Begining
// ********************************

void insertAtBeg(linkedList *listptr,int data){
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

// ********************************
//      Insert at Location
// ********************************

int insertAtLoc(linkedList *listptr,int target,int data){
    Node *p = find(listptr,target);
    if(p == NULL){
        return 0;
    }
    if(p == listptr->tail){
        insertAtEnd(listptr,data);
    }else{
        Node *newNodePointer = (Node *)malloc(sizeof(Node));
        if(newNodePointer == NULL){
            printf("Error allocating memory for new node\n");
            return 0;
        }
        newNodePointer->next = p->next;
        p->next = newNodePointer;
        newNodePointer->data = data;
        listptr->nodeCount++;
    }
    return 1;
}

// ********************************
//          Traverse
// ********************************

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

Node * find(linkedList *listptr,int target){
    Node *current = listptr->head;
    while(current != NULL){
        if(current->data == target){
            break;
        }
        current = current->next;
    }
    return current;
}