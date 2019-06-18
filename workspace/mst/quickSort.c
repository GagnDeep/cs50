#include<stdio.h>
#include<stdlib.h>

// partition
int partition(int [],int ,int);
// quickSort
void quickSort(int [],int,int);
// print array
void printArray(int [],int);
// swap
void swap(int * ,int *);

// main function
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i , j;
    i = low-1;
    for(j = low; j < high ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[j],&arr[i]);;
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,pi+1,high);
        quickSort(arr,low,pi-1);
    }
}
void printArray(int arr[],int n){
    for(int i = 0; i < n ; i++){
        printf("%d\n",arr[i]);
    }
}
void swap(int *x,int *y){
    int swap;
    swap = *x;
    *x = *y;
    *y = swap;
}