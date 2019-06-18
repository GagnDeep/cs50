#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[] = {6,32,66,74,11,1,3};
    int n,i,j,swap,position;
    n=7;
    for(i = 1;i<n;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]  = swap;
            j--;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}