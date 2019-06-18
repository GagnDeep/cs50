#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *arr;
    int i;
    int size;
}stack;
void dealloc(stack *);
void init(stack *,int);
void push(stack *,int);
int pop(stack *);
int main(){
    stack s1,s2;
    init(&s1,3);
    while(1){
        int EnteredValue,element;
        printf("1.Push 2.Pop 3.Exit \nEnter Choice : ");
        scanf("%d",&EnteredValue);
        switch(EnteredValue){
            case 1 :
            printf("Enter number to be pushed : ");
            scanf("%d",&element);
            push(&s1,element);
            break;
            case 2:
            element=pop(&s1);
            if(element==-9999)
            break;
            else
            printf("Popped Out is element has a value of %d\n",element);
            break;
            case 3:
            exit(1);
            default:
            printf("please select correct choice");
        }
    }
    return 0;
    dealloc(&s1);
}
void init(stack *sp,int size){
    sp->i = -1;
    sp->arr = (int *)malloc(sizeof(int)*size);
    sp->size = size;
    if(sp->arr == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
}
void dealloc(stack *sp){
    if(sp->arr!=NULL){
        free(sp->arr);
    }
}
void push(stack *sp,int value){
   if(sp->i== sp->size-1){
       int *temp;
       temp = (int *)malloc(sizeof(int)*sp->size*2);
       if(temp==NULL){
           printf("Unable To Allocate memory to the temperory array");
           return;
       }
       for(int y=0;y<sp->i;y++){
           temp[y]=sp->arr[y];
       }
       free(sp->arr);
       sp->arr = temp;
       sp->size *= 2;
       free(temp);
    }
   sp->i++;
   sp->arr[sp->i]=value;
   return ;
   }

int pop(stack *sp){
    if(sp->i == -1){
        printf("stack underflow\n");
        return -9999;
    }else{
        int value;
        value = sp->arr[sp->i];
        sp->i--;
        return value;
    }
}