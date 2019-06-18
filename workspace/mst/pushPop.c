#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct {
    int arr[size];
    int top;
}stack;

void push(stack *,int);
int pop(stack *);
void init(stack *);


int main(){
    return 0;
}

void push(stack *sp,int value){
    if(sp->top == size-1){
        printf("stack overflow\n");
        exit(1);
    }else{
        sp->arr[++sp->top] = value;
    }
}
int pop(stack *sp){
    if(sp->top == -1){
        printf("stack underflow\n");
        exit(1);
    }else{
        return sp->arr[sp->top--];
    }
}
