#include<stdio.h>

int partition(int [], int, int);
void quickSort(int [], int, int);
void swap(int *, int *);
void printArray(int [],int);

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high],i = (low - 1);
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}
void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        printf("%4d",arr[i]);
        printf("\n");
    }
}