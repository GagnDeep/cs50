#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct {
    char arr[SIZE];
    int top;
}stack;
//Function Decelerations
void push(stack * , char);
char pop(stack *);
int isEmpty(stack *);
char stackTop(stack *);

int isOpeningMatch(char ,char);
int checkExpr(char []);

int main(){
    char expr[SIZE];
    printf("Input Expression : ");
    scanf("%s",expr);
    if(checkExpr(expr)){
        printf("Does Not Contain Well Formed Brackets\n");
    }else{
        printf("Expression Is Well Formed And Does Contains Well Formed Brackets\n");
    }
    return 0 ;
}

void push(stack *sp,char value){
    if(sp->top == SIZE-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    sp->arr[++sp->top] = value;
}
char pop(stack *sp){
    if(sp->top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return sp->arr[sp->top--];
}
int isEmpty(stack *sp){
    return sp->top == -1;
}
char stackTop(stack *sp){
    if(isEmpty(sp)){
        printf("Stack Underflow\n");
    }
    return sp->arr[sp->top];
}
int isOpeningMatch(char left,char right){
    int match = 0;
    switch(left){
        case '[':
        if(right ==']')
        match = 1;
        break;
        case '{':
        if(right =='}')
        match = 1;
        break;
        case '(':
        if(right ==')')
        match = 1;
        break;
        default: printf("Invalid symbol encountered, terminating program\n");
				 exit(1);
    }
    return match;
}
int checkExpr(char arr[]){
    stack stack;
    stack.top=-1;
    int error = 0;
    int i = 0;
    while(arr[i] != '\0'){
        char nextChar = arr[i];
        if(nextChar == '{' || nextChar == '[' || nextChar == '('){
            push(&stack,nextChar);
        }else if(nextChar == '}' || nextChar == ']' || nextChar == ')'){
            if(isEmpty(&stack)){
                error = 1;
                break;
            }else if(isOpeningMatch(stackTop(&stack),nextChar)){
                pop(&stack);
            }else{
                error =1;
                break;
            }
        }
        ++i;
    }
    if(!error && !isEmpty(&stack)){
            error = 1;
        }
    return error;
}