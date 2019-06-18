#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *arr;
    int top;
}stack;

int pop(stack *);

int main(){
    stack s1;
    int arr[] = {1,2,3,4,5,6};
    s1.arr = arr;
    int option,element,i,top;
    s1.top = 5;

    while(1){
        printf("\n1.pop element  2.print array  3.Exit\n");
        printf("Enter option : ");
        scanf("%d",&option);
        switch(option){
            case 1 :
            printf("Popped element : %d\n",pop(&s1));
            break;

            case 2:
            printf("\n========================\n");
            for(i = 0; i <= s1.top; i++)
            printf("%d ",*(s1.arr + i));
            printf("\n========================\n");
            break;

            case 3:
            exit(1);

            default:
            printf("\ninvalid input");
        }
    }
    return 0;
}
int pop(stack *sp){
    if(sp->top == -1){
        printf("\nStack Underflow");
        exit(1);
    }else{
        return *(sp->arr + sp->top--);
    }
}