#include<stdio.h>
int main(){
    int arr[] = {
        1,2,4,5,3,2,1,6
    };
    int i, n;
    n = 8;
    printf("Array -------> \n\n");
    printf("*************************\n");
    for(i = 0 ; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n*************************\n");
    return 0;
}