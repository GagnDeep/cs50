#include<stdio.h>
#include<stdlib.h>

#define size 100

typedef struct {
    char arr[size];
    int top;
}stack;

void push(stack * , char);
char pop(stack *);
int isOpeningMatch(char,char);

int main(){
    stack s;
    s.top = -1;
    int i = 0;

    int error = 0;
    char str[100];
    printf("enter string : ");
    scanf("%s",str);

    while(str[i] != '\0'){
        char nextChar = str[i];
        if(nextChar == '(' || nextChar == '{' || nextChar == '['){
            push(&s,nextChar);
        }else{
            if(nextChar == '}' || nextChar == ']' || nextChar == ')'){
                if(s.top == -1){
                    error = 1;
                    break;
                }else if(isOpeningMatch(s.arr[s.top],nextChar)){
                    pop(&s);
                }else{
                    error = 1 ;
                    break;
                }
            }
        }
        i++;
    }
    if(!error && s.top == -1){
        printf("good eq");
    }else{
        printf("something wrong");
    }
    return 0;
}

void push(stack *sp,char value){
    if(sp->top == size-1){
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
