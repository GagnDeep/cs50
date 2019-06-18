//included libraries
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

//structure initialization
typedef struct {
    char arr[SIZE];
    int top;
}stack;

//functions prototyping
void push(stack *,char);
char pop(stack *);
int isEmpty(stack *);
char stackTop(stack *);

int isOpeningMatch(char,char);
int checkExpr(char []);

//main function
int main(){
    char expr[SIZE];
    printf("Enter Expression : ");
    scanf("%s",expr);
    if(checkExpr(expr)){
        printf("The Expression doesnot Contain well Formed Brackets\n");
    }else{
        printf("The Expresion Is well Formed and contains well formed brackets");
    }
    return 0;
}

//functions definations
void push(stack *sp,char value){
    if(sp->top == SIZE-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    sp->arr[++sp->top] = value;
}
char pop(stack *sp){
    if(isEmpty(sp)){
        printf("Stack Underflow\n");
        exit(1);
    }
    return sp->arr[sp->top--];
}
int isEmpty(stack *sp){
    return sp->top == -1;
}
char stackTop(stack *sp){
    return sp->arr[sp->top];
}
int isOpeningMatch(char left,char right){
    int match = 0;
    switch(left){
        case '{':
        if(right == '}')
        match = 1;
        break;
        case '(':
        if(right == ')')
        match = 1;
        break;
        case '[':
        if(right == ']')
        match = 1;
        break;
    }
    return match;
}
int checkExpr(char expr[]){
    stack stack;
    stack.top = -1;
    int error = 0;
    int i = 0;
    while(expr[i] != '\0'){
        char nextChar = expr[i];
        if(nextChar == '{' || nextChar == '[' || nextChar == '('){
            push(&stack,nextChar);
        }else if(nextChar == '}' || nextChar == ')' || nextChar == ']'){
            if(isEmpty(&stack)){
                error = 1;
                break;
            }else if(isOpeningMatch(stackTop(&stack),nextChar)){
                pop(&stack);
            }else{
                error = 1;
                break;
            }
        }
        i++;
    }
    if(!error && !isEmpty(&stack)){
        error = 1;
    }
    return error;
}