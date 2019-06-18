#include<stdio.h>
int main(){
    int item,loc,i,n;
    int arr[] = {
        1,2,4,5,4,7,6,5,4,3,9,46
    };
    n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter element you want to insert : ");
    scanf("%d",&item);
    printf("Enter loc on which you want to insert : ");
    scanf("%d",&loc);
    loc = loc-1;
    if(loc == n+1){
        arr[n+1] = item;
        printf("Element successfully inserted\n");
        return 0;
    }
    for(i = n+1; i < loc+1 ; i--){
        arr[i] = arr[i-1];
    }
    arr[loc] = item;
    printf("Element successfully inserted\n");
    return 0;
}