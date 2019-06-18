#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node * insert(Node *,int);
Node * createNewNode(int);
void traversal(Node *);
void menu();
Node * minValueNode(Node *);
Node * deleteNode(Node *,int);
Node * loadFromFile(Node *,char *);

int main(){
    Node *root;
    root = NULL;
    int choise,data;
    int quit = 0;

    menu();

    while(!quit){
        printf("\nEnter Your Choise : ");
        scanf("%d",&choise);

        switch(choise){
            case 1:
                quit = 1;
                break;

            case 2:
                root = loadFromFile(root,"data.txt");
                if(root != NULL){
                printf("file has been loaded successfully\n");
                }else{
                    printf("Error!");
                }
                break;

            case 3:
                printf("Enter the number you want to insert : ");
                scanf("%d",&data);
                root = insert(root,data);
                break;

            case 4:
                printf("Enter the Data you want to delete : ");
                scanf("%d",&data);
                root = deleteNode(root,data);
                break;

            case 5:
                printf("-----Inorder Traversal------\n");
                traversal(root);
                break;

            default:
                printf("invalid Option choosen\n");
                break;
            }
    }
    return 0;
}

void menu(){
    printf("--------------------------\n");
    printf("1. Quit\n");
    printf("2. Load from File\n");
    printf("3. Insert\n");
    printf("4. Delete Node\n");
    printf("5. Traversal\n");
    printf("--------------------------\n");
}

Node * createNewNode(int data){
    Node *newNodePointer = (Node *)malloc(sizeof(Node));
    newNodePointer->data = data;
    newNodePointer->left = newNodePointer->right = NULL;
    return newNodePointer;
}

Node * insert(Node *p,int data){
    if(p == NULL){
        return createNewNode(data);
    }
    if(p->data <= data){
        p->right = insert(p->right,data);
    }else{
        p->left = insert(p->left,data);
    }
    return p;
}

void traversal(Node *p){
    if(p!=NULL){
        traversal(p->left);
        printf("%4d",p->data);
        traversal(p->right);
    }
}

Node * deleteNode(Node *p,int data){
    if(p == NULL)
    return p;
    if(data < p->data)
    p->left = deleteNode(p->left,data);
    else if( data > p->data)
    p->right = deleteNode(p->right,data);
    else{
        if(p->left == NULL){
            Node *temp = p->right;
            free(p);
            return temp;
        }else if(p->right == NULL){
            Node * temp = p->left;
            free(p);
            return temp;
        }
        Node *temp = minValueNode(p->right);
        p->data = temp->data;
        p->right = deleteNode(p->right,p->data);
    }
    return p;
}


Node * minValueNode(Node *p){
    Node *current = p;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}
Node * loadFromFile(Node *p, char *fileName){
    FILE *inputFile = fopen(fileName,"r");
    if(inputFile == NULL){
        printf("Unable to open file. Please make shure that file exists :(\n");
        return p;
    }
    int data;
    fscanf(inputFile,"%d",&data);
    while(!feof(inputFile)){
        p = insert(p,data);
        fscanf(inputFile,"%d",&data);
    }
    fclose(inputFile);
    return p;
}