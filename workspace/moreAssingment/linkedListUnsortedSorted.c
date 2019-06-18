#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *next;
    struct Node *previous;
    int data;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

void addLast(linkedList *,int);
int loadFromFile(linkedList *,char *);
Node * find(linkedList *, int);
void traverse(linkedList *);
void menu();

int main(){
    linkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.nodeCount = 0;
    int choise,data;
    int quit = 0;
    menu();
    while(!quit){
        printf("\nEnter your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
                quit = 1;
                break;
            case 2:
                data = loadFromFile(&list,"data.txt");
                if(!data)
                printf("File successfully loaded");
                break;
            case 3:
                traverse(&list);
                break;
            case 4:
                printf("enter data you want to find : ");
                scanf("%d",&data);
                Node *p = find(&list,data);
                if(p!=NULL)
                printf("element : %d successfully found in the linked list at address : %p\n",p->data,p);
                else
                printf("Invalid Option choosen\n");
                break;
            default:
                printf("Invalid option choosen\n");

        }
    }
    return 0;
}
void menu(){
        printf("------------------------------\n");
        printf("1. Quit\n");
        printf("2. Load from File\n");
        printf("3. Traverse\n");
        printf("4. find\n");
        printf("------------------------------\n");
}

Node * find(linkedList *listptr,int target){
    Node *p;
    for(p = listptr->head;p!=NULL;p=p->next){
        if(p->data == target){
            return p;
        }
    }
    return NULL;
}
void traverse(linkedList *listptr){
    Node *p = listptr->head;
    if(p == NULL){
        printf("list is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%4d",p->data);
        p = p->next;
    }
}

void addLast(linkedList *listptr, int data){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    if(newNodePointer == NULL){
        printf("error allocating memory for new node\n");
        return;
    }
    newNodePointer->data = data;
    newNodePointer->previous = NULL;
    newNodePointer->next = NULL;
    if(listptr->nodeCount == 0){
        newNodePointer->data = data;
        listptr->head = newNodePointer;
        listptr->tail = newNodePointer;
    }else{
        newNodePointer->previous = listptr->tail;
        listptr->tail->next = newNodePointer;
        listptr->tail = newNodePointer;
    }
    listptr->nodeCount++;
}

int loadFromFile(linkedList *listptr,char *fileName){
    int data;
    FILE *inputFile = fopen(fileName,"r");
    if(inputFile == NULL){
        return 0;
    }
    fscanf(inputFile,"%d",&data);
    while(!feof(inputFile)){
        addLast(listptr,data);
        fscanf(inputFile,"%d",&data);
    }
    fclose(inputFile);
    return 1;
}