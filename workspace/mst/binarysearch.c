#include<stdio.h>
int main(){
    int i,n,first,last,middle;
    int arr[]={10,20,30,40,50,60};
    int search = 60;
    n = 5;
    i = 0;
    first = 0;
    last = n;
    middle = (first+last)/2;
    while(first<=last){
        if(arr[middle] > search){
            last = middle-1;
        }else if(arr[middle] == search){
            printf("element %d is at location %d",search,middle);
            break;
        }else{
            first = middle +1;
        }
        middle = (first + last)/2;
        i++;
    }
    if(first >last){
        printf("element not found");
    }
    return 0;
}