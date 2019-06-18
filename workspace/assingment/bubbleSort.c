#include<stdio.h>

int main(){
    int n,swap,i,j;
    n = 7;
    int arr[] = {
        9,5,13,53,33,22,11
    };
    printf("\nunsorted array : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    for(i = 0; i < n-1 ; i++){
        for(j = 0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    printf("\nsorted array : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}