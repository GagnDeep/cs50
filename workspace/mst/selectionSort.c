#include<stdio.h>
int main(){
    int position, i ,j ,swap , n;
    int arr[]={
        25,3,6,8,22,74
    };
    n = 6;
    for(i = 0 ; i<n -1;i++){
        position = i;
        for(j = i ;j<n;j++){
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
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

}