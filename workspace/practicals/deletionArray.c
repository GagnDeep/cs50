#include<stdio.h>
int main(){
    int arr[] = {
        1,2,43,5,6,3,3,6,6,4
    };
    int loc,item,n,i;
    n = sizeof(arr)/sizeof(arr[0]);
    item = arr[loc];
    printf("enter the location on which you want to perform deletion : ");
    scanf("%d",&loc);
    loc = loc - 1;
    item = arr[loc];
    if(loc == n - 1 ){
        n = n-1;
        printf("Item Deleted Successfully, Item deleted : %d",item);
        return 0;
    }
    for(i = loc + 1 ; i < n; i++){
        arr[i-1] = arr[i];
    }
    n = n-1;
    printf("Item Deleted Successfully, Item deleted : %d",item);
    return 0;
}