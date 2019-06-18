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

int main(){
    linkedList list;
    list.head = list.tail = NULL;
    list.nodeCount = 0;
    menu();
    int choise,data,n;
    int quit = 0;
    while(!quit){
        printf("Please input your choise : ");
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
        }
    }
}
void menu(){
    printf("Operations\n");
    printf("---------------------------------------\n");
    printf("1. Quit\n");
    printf("2. Load from file\n");
    printf("3. Traverse\n");
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
        Node *newNodePointer = (Node *)malloc(sizeof(Node));
            if(newNodePointer == NULL){
                printf("Unable to allocate Memory for new node\n");
                return 0;
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