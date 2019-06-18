#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct {
    int arr[SIZE];
    int top;
}stack;

void push(stack * , int);

int main(){
    stack s1;
    s1.top = -1;
    int option,element,i;

    while(1){
        printf("\n1.push element to array  2.print array  3.Exit\n");
        printf("Enter option : ");
        scanf("%d",&option);
        switch(option){
            case 1 :
            printf("\nenter element : ");
            scanf("%d",&element);
            push(&s1,element);
            break;

            case 2:
            for(i = 0; i <= s1.top; i++)
            printf("%d ",s1.arr[i]);
            break;

            case 3:
            exit(1);

            default:
            printf("\ninvalid input");
        }
    }
    return 0;
}
void push(stack *sp,int element){
    if(sp->top == SIZE-1){
        printf("\nStack Overflow");
        exit(1);
    }else{
        sp->arr[++sp->top] = element;
    }
}