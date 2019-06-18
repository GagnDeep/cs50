#include<stdio.h>
int main(){
    int arr[] = {6,32,66,74,11,1,3};
    int n,i,j,swap,position;
    n=7;
    for(i=0;i<n-1;i++){
        position = i;
        for(j=i+1;j<n;j++){
            if(arr[position]>arr[j]){
                position = j;
            }
        }
        if(position != i){
            swap = arr[position];
            arr[position] = arr[i];
            arr[i] = swap;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}