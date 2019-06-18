#include<stdio.h>
#include<stdlib.h>

void quickSort(int *,int ,int);
int partition(int *,int ,int);
void printArray(int *,int);

int main(){
    int arr[] = {
        7,8,9,4,5,1,7,3
    };
    int n = 8;
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}

int partition(int *arr,int low,int high){
    int i,j,swap;
    int pivot = arr[high];
    i = low-1;
    for(j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap = arr[j];
            arr[j] = arr[i];
            arr[i] = swap;
        }
    }
    swap = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = swap;
    return (i+1);
    }
void quickSort(int *arr,int low,int high){
    if(low<high){
        int i = partition(arr,low,high);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
}
void printArray(int *arr,int n){
    int i ;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}