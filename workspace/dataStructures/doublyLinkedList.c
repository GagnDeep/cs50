#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    struct Node *next;
    int data;
    struct Node *previous;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int nodeCount;
}linkedList;

void init(linkedList *);
void addFirst(linkedList *,int);
void addLast(linkedList *,int);
int loadFromFile(linkedList *,char *);
void createListFromRandomNumbers(linkedList *, int);
void printListDetail(linkedList *);
void printListForward(linkedList *);
void printReverse(linkedList *);
Node * find(linkedList *, int);
int insertAfter(linkedList *, int, int);
int insertBefore(linkedList *, int, int);
int deleteFirst(linkedList *);
int deleteLast(linkedList *);
int deleteTarget(linkedList *, int);
void menu();

int main(){
    linkedList list;
    init(&list);
    int choise;
    menu();
    int quit = 0;
    int data,n,target;
    int success;
    Node *current = NULL;
    Node *prev = NULL;
    while(!quit){
        printf("Please input your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
            success = loadFromFile(&list,"data.txt");
            if(success == 1 ){
                printf("File has been successfully loaded\n");
            }else{
                printf("Error loading file\n");
            }
            break;

            case 2:
            printf("enter the number of integers to be added to list : ");
            scanf("%d",&n);
            createListFromRandomNumbers(&list,n);
            break;

            case 3:
            printf("Enter data to insert at head : ");
            scanf("%d",&data);
            addFirst(&list,data);
            break;

            case 4:
            printf("Input data to insert at tail : ");
            scanf("%d",&data);
            addLast(&list,data);
            break;

            // case 5: printListDetail(&list);
            // break;

            case 6:
            printListForward(&list);
            break;

            case 8:
            //call find
            printf("Enter target: ");
            scanf("%d", &target);
            current = find(&list, target);
            if(current == NULL)
              printf("LinkedList doen not contain the target specified\n");
            else
              printf("Target exists in the linkedlist\n");
            break;
      case 9:
            printf("Enter target: ");
            scanf("%d", &target);
            printf("Input data: ");
            scanf("%d", &data);
            if (insertAfter(&list, target, data) == 1){
              printf("Insert after was successful\n");
            }
            else{
              printf("Insert after failed\n");
            }

            break;
      case 10:
            // call insertBefore.
            printf("Enter target: ");
            scanf("%d", &target);
            printf("Input data: ");
            scanf("%d", &data);
            if (insertBefore(&list, target, data) == 1){
              printf("Insert before was successful\n");
            }
            else{
              printf("Insert before failed\n");
            }
            break;
      case 11:
            if (deleteFirst(&list))
              printf("First node deleted successfully\n");
            else
              printf("Unable to delete first node\n");
            break;
      case 12:
            if (deleteLast(&list))
              printf("Last node deleted successfully\n");
            else
              printf("Unable to delete last node\n");
            break;
      case 13:
            printf("Enter target: ");
            scanf("%d", &target);
            if (deleteTarget(&list, target))
              printf("Target node deleted successfully\n");
            else
              printf("Unable to delete the target node, target may not be available\n");
            break;
      case 14:
            quit = 1;
            break;

            default:
            printf("Invalid option choosen\n");
        }
    }
    return 0;
}

int deleteTarget(linkedList *listptr,int target){
    Node *p = find(listptr,target);
    if(p == NULL){
        return 0;
    }
    if(p == listptr->head){
        deleteFirst(listptr);
    }else if(p == listptr->tail){
        deleteLast(listptr);
    }else{
        p->previous->next = p->next;
        p->next->previous = p->previous;
        listptr->nodeCount--;
        free(p);
        return 1;
    }
    return 1;
}

int deleteLast(linkedList *listptr){
    if(listptr->nodeCount == 0){
        return 0 ;
    }
    Node *p = listptr->tail;
    if(listptr->nodeCount == 1){
        listptr->head = listptr->tail = NULL;
    }else{
        listptr->tail = listptr->tail->previous;
        listptr->tail->next = NULL;
    }
    free(p);
    listptr->nodeCount--;
    return 1;
}

int deleteFirst(linkedList *listptr){
    if(listptr->nodeCount == 0){
        return 0 ;
    }
    Node *p = listptr->head;
    if(listptr->nodeCount == 1){
        listptr->head = listptr->tail = NULL;
    }else{
        listptr->head = listptr->head->next;
        listptr->head->previous = NULL;
    }
    free(p);
    listptr->nodeCount--;
    return 1;
}

int insertAfter(linkedList *listptr,int target,int data){
    Node *p = find(listptr,target);
    if(p == NULL){
        return 0;
    }
    if(p == listptr->tail){
        addLast(listptr,data);
    }else{
        Node *newNodePointer =(Node *)malloc(sizeof(Node));
        if(newNodePointer == NULL){
            printf("error allocating memory for new node \n");
            return 0;
        }
        newNodePointer->next = p->next;
        newNodePointer->previous = p;
        p->next = newNodePointer;
        p->next->previous = newNodePointer;
        newNodePointer->data = data;
    }
    listptr->nodeCount++;
    return 1;
}
int insertBefore(linkedList *listptr, int target,int data){
    Node *p = find(listptr,target);
    if(p == NULL){
        return 0;
    }
    if(p == listptr->head){
        addFirst(listptr,data);
    }else{
        Node *newNodePointer =(Node *)malloc(sizeof(Node));
        if(newNodePointer == NULL){
            printf("error allocating memory for new node \n");
            return 0;
        }
        newNodePointer->previous = p->previous;
        newNodePointer->next = p;
        p->previous->next = newNodePointer;
        p->previous = newNodePointer;
        newNodePointer->data = data;
    }
    listptr->nodeCount++;
    return 1;
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

void printReverse(linkedList *listptr){
   Node *p = listptr->tail;
    if(p == NULL){
        printf("list is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%4d",p->data);
        p = p->previous;
    }
}

void printListForward(linkedList *listptr){
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

void addFirst(linkedList *listptr,int data){
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
        listptr->head->previous = newNodePointer;
        newNodePointer->next = listptr->head;
        listptr->head = newNodePointer;
    }
    listptr->nodeCount++;
}

void createListFromRandomNumbers(linkedList *listptr , int n){
    int data,i;
    srand(time(NULL));
    for(i = 0; i<n; i++){
        data = rand()%1000;
        addLast(listptr, data);
    }
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


void menu(){
  printf("    Doubly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("1. Load from file\n");          // load integer data from file and will create the list
                                          // by using insert_at_tail operation (menu option 3)
  printf("2. Create list with random numbers\n");
  printf("3. Add First\n");          // inserting a new node as the first node
  printf("4. Add Last\n");           // inserting a new node as the last node
  printf("5. Print List (detail)\n");     // printing the linked list in details,
                                          // including the data and pointer in each node
  printf("6. Print List first to last (data only)\n");  // prints the integer data in each node from the first node to last
  printf("7. Print List last to first (data only)\n");  // prints data fro last to the first node
  printf("8. Find\n");                    // finds if an integer exisits in a node from
                                          // the start in the list
  printf("9. Insert After\n");
  printf("10. Insert Before\n");
  printf("11. Delete first\n");            // deletes the first node
  printf("12. Delete last\n");             // deletes the last node
  printf("13. Delete a target node\n");    // deletes a particular node, if that exists

  printf("14. Quit\n");                    // to terminate each node
}

void init(linkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}