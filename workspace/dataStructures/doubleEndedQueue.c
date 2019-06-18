#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front, rear;
}queue;

void insAtRear(queue * , int);
int delFromRear(queue *);
void insAtFront(queue * , int);
int delFromFront(queue *);
void init(queue *);
void menu();

int main(){
    int element;
    queue q;
    init(&q);
    menu();
    while(1){
        int choise;
        printf("Enter your Option : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
            printf("\nEnter Element to insert at rear : ");
            scanf("%d",&element);
            insAtRear(&q,element);
            break;
            case 2:
            printf("\nEnter Element to insert at front : ");
            scanf("%d",&element);
            insAtFront(&q,element);
            break;
            case 3:
            element = delFromRear(&q);
            if(element == -9999)
            printf("\nqueue underflow");
            else
            printf("\nElement : %d\n",element);
            break;
            case 4:
            element = delFromFront(&q);
            if(element == -9999)
            printf("\nqueue underflow");
            else
            printf("\nElement : %d\n",element);
            break;
            case 5:
            exit(0);
            default:
            printf("\nYou are bad .... i gave u only 3 options");
            break;

        }
    }
    return 0;
}

void insAtRear(queue *qp ,int value){
    if(qp->rear == SIZE-1){
        printf("\nUnable to Insert at rear");
        return;
    }
    qp->rear = qp->rear + 1;
    qp->arr[qp->rear] = value;
}
void insAtFront(queue *qp ,int value){
    if(qp->front == 0){
        printf("\nUnable to insert at front");
        return ;
    }
    qp->front--;
    qp->arr[qp->front] = value;
}
int delFromRear(queue *qp){
    if(qp->front > qp->rear){
        printf("\nunable to delete");
        return -9999;
    }
    return qp->arr[qp->rear--];
}
int delFromFront(queue *qp){
    if(qp->front > qp->rear){
        printf("\nunable to delete");
        return -9999;
    }
    return qp->arr[qp->front++];
}
void init(queue *qp){
    qp->front = 0;
    qp->rear = -1;
}
void menu(){
    printf("-----------------------------------------\n");
    printf("1. InsAtRear\n2. InsAtFront\n3. DelFromRear\n4. DelFromFront\n5. Exit\n");
    printf("-----------------------------------------\n");
}