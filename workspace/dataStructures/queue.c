#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front, rear;
}queue;

void enqueue(queue * , int);
int dequeue(queue *);
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
            printf("\nEnter Element : ");
            scanf("%d",&element);
            enqueue(&q,element);
            break;
            case 2:
            element = dequeue(&q);
            if(element != -9999)
            printf("\nElement : %d\n",element);
            break;
            case 3:
            exit(0);
            default:
            printf("\nYou are bad .... i gave u only 3 options");
            break;

        }
    }
    return 0;
}

void enqueue(queue *qp , int value){
    if((qp->rear + 1 )%SIZE == qp->front ){
        printf("\nQueue Overflow");
        return;
    }
    qp->rear = (qp->rear + 1)%SIZE;
    qp->arr[qp->rear] = value;
    }
int dequeue(queue *qp){
    if(qp->rear == qp->front ){
        printf("\nQueue Underflow");
        return -9999;
    }
    qp->front = (qp->front + 1)%SIZE;
    return qp->arr[qp->front];
}
void init(queue *qp){
    qp->front = SIZE -1;
    qp->rear = SIZE -1;
}
void menu(){
    printf("-----------------------------------------\n");
    printf("1. Enqueue\n2. Dequeue\n3. exit\n");
    printf("-----------------------------------------\n");
}