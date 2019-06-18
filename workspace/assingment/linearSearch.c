#include<stdio.h>

int main(){
    int array[10] = {1,3,5,2,6,7};
    int i,item,n,loc;
    n = 6;
    printf("Enter element to be searched : ");
    scanf("%d",&item);
    for(i = 0 ; i < n ; i++){
        if(array[i] == item){
            loc = i
            printf("\n%d is at location %d",item,loc+1);
            break;
        }
        if(i == n){
            printf("\nElement Not Found");
        }
    }
}