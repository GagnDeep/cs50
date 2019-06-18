#include<stdio.h>
int swap(int , int);
int main(void){
    int a,b;
    a=66;
    b=78;
    printf("a = %d b = %d\n",a,b);
    swap(a,b);
    return 0;
}
int swap(int a,int b){
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d b = %d",a,b);
    return 0;
}