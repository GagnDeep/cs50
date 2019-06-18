#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 100

typedef struct{
    char arr[size];
    char top;
}stack;

void push(stack *,char);
char pop(stack *);

int main(){
    stack s;
    s.top = 0;
    char str[] = "i am gagandeep singh";
    char str2[strlen(str) + 1];
    for(int i = 0;i<=strlen(str)+1;i++){
        push(&s,str[i]);
    }
    for(int i = 0;i<=strlen(str)+1;i++){
        str2[i] = pop(&s);
        printf("%c",str2[i]);
    }
 printf("%s",str2);
}
void push(stack *p,char ch ){
    if(p->top + 1 == size){
        printf("stack overflow\n");
        exit(1);
    }
    p->arr[++p->top] = ch;
}
char pop(stack *p){
    if(p->top == 0){
        printf("Stack underflow\n");
        exit(1);
    }
    return p->arr[p->top--];
}