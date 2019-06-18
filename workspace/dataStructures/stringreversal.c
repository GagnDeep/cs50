//included libraries
#include<stdio.h>
#include<stdlib.h>

#define SIZE 200

//structure initialization
typedef struct {
    char *arr;
    int top;
    int size;
}stack;


void push(stack *,char);
char pop(stack *);
int isEmpty(stack *);
char stackTop(stack *);

void init(stack *,int);
void dealloc(stack *);
int reverseIt(char [],char []);

void stringReversal(stack);
int main(){
    int f = reverseIt("./file.txt","./fileW.txt");
    if(f){
        printf("Sucess\n");
    }else{
        printf("fail\n");
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
void init(stack *sp,int size){
    sp->top = -1;
    sp->arr = malloc(sizeof(char)*size);
    sp->size = size;
    if(sp->arr == NULL){
        printf("Memory Allocation Failed \n ");
        exit(1);
    }
}
void dealloc(stack *sp){
    if(sp->arr !=NULL){
    free(sp->arr);
    }
}
int reverseIt(char source[],char dest[]){
    FILE *fps,*fpd;
    fps = fopen(source,"r");
    if(fps == NULL){
        printf("Unable To Read Source File\n");
        exit(1);
    }else{
        fpd = fopen(dest,"w");
        if(fpd == NULL){
            printf("Unable To write Destination file\n");
            exit(1);
        }else{
            stack stack;
            init(&stack,200);
            char x;
            x = fgetc(fps);
            while(!feof(fps)){
                push(&stack,x);
                x = fgetc(fps);
            }
            while(!isEmpty(&stack)){
                fputc(pop(&stack),fpd);
            }
            fclose(fpd);
            fclose(fps);
            dealloc(&stack);
            return 1;
            }
        }
    }
