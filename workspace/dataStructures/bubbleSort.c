#include<stdio.h>
int main(){
    int arr[] = {6,32,66,74,11,1,3};
    int n,i,j,swap,position;
    n=7;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}