#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char *arr;
    int i;
    int size;
}stack;
void dealloc(stack *);
void init(stack *,int);
void push(stack *,char);
char pop(stack *);
int reverseIt(char [],char []);






//*******************MAIN FUNCTION**************************
int main(){
    int f = reverseIt("./file.txt","./fileW.txt");
    if(f){
        printf("Sucess\n");
    }else{
        printf("fail\n");
    }
    return 0;

}





void init(stack *sp,int size){
    sp->i = -1;
    sp->arr = (char *)malloc(sizeof(char)*size);
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
void push(stack *sp,char value){
   if(sp->i== sp->size-1){
       char *temp;
       temp = (char *)malloc(sizeof(char)*sp->size*2);
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

char pop(stack *sp){
    if(sp->i == -1){
        printf("stack underflow\n");
        return -9999;
    }else{
        char value;
        value = sp->arr[sp->i];
        sp->i--;
        return value;
    }
}


int reverseIt(char source[],char dest[]){
    FILE *fps,*fpd;
    const int SIZE = 50;
    fps = fopen(source,"r");
    if(fps == NULL){
        printf("error opening file \n");
    }else{
        fpd=fopen(dest,"w");
        if(fpd==NULL){
            printf("error");
        }else{
            stack s;2
            init(&s,100);
            char x;
            x=fgetc(fps);
            while(!feof(fps)){
                push(&s,x);
                x= fgetc(fps);
            }
            while(s.i!=-1){
                fputc(pop(&s),fpd);
            }
            fclose(fpd);
            fclose(fps);
            dealloc(&s);
            return(1);
        }
    }
}