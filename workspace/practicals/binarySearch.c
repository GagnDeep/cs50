#include<stdio.h>
int main(){
    int arr[] = {
        1,6,7,3,2,9,52,458,45,32
    };
    int n,item,loc,i;
    int beg,end,mid;
    n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the item to be searched : ");
    scanf("%d",&item);
    beg = 0;
    end = n;
    mid = (beg + end)/2;
    while(arr[mid] != item && beg > end){
        if(arr[mid]<item){
            beg = mid + 1;
        }else if(arr[mid]>item){
            end = mid - 1;
        }
    }
    if(beg < end && arr[mid] == item){
        loc = mid;
        printf("element found at loc %d",loc);
    }else{
        printf("Element not found\n");
    }
    return 0;
}