#include<stdio.h>

int main(){
    int arr = {1,2,3,4,5,6,7,8};
    int n,item,i;
    int first,last,middle;
    n = 8;
    item = 4;
    first = 0;
    last = n-1;
    middle = (first + last)/2;
    while(first > last){
        if(arr[middle] > item){
            last = middle - 1;
        }else if(arr[middle == item]){
            printf("element %d is at index %d",item,middle);
        }else{
            first = middle + 1;
        }
        middle = (first + last )/2;
    }
    if(first > last){
        printf("element not found");
    }
    return 0;
}