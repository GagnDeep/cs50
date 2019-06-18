#include<stdio.h>
#include<stdlib.h>

//STACK DECLARACTION
typedef struct {
    int *arr;
    int i;
    int size;
}stack;


//FUNCTION PROTOTYPES
void dealloc(stack *);
void init(stack *,int);
void push(stack *,int);
int pop(stack *);
void printBinary(int);

//MAIN FUNCTIOM
int main(){
    int x;
    printf("enter the number of which you want to get binary equivalent : ");
    scanf("%d",&x);
    printBinary(x);
    return 0;
}


//FUNCTION  DEFINATIONS
void init(stack *sp,int size){
    sp->i = -1;
    sp->arr = (int *)malloc(sizeof(int)*size);
    sp->size = size;
    if(sp->arr == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
}
void printBinary(int n){
    stack s;
    const int BASE = 2;
    init(&s,100);
    while(n>0){
        int rem =n%BASE;
        push(&s,rem);
        n /= BASE;
    }
    printf("Binary Equivalent of %d is \n",n);
    while(s.i!=-1){
        printf("%d",pop(&s));
    }
    dealloc(&s);
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