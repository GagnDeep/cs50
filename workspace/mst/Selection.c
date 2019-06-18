#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j , item , swap , n;
    int arr[] = {
        9,8,7,6,5,4,3,2
    };
    n = sizeof(arr)/sizeof(arr[0]);
    for(i = 0; i < n; i++){
        for(j = i +1 ; j < n; j++){
            if(arr[j]<arr[i]){
                swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
             }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n",arr[i]);
    }
}