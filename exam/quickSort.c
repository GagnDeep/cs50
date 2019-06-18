#include<stdio.h>

int partition(int [], int, int);
void quickSort(int [], int, int);
void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        printf("%4d",arr[i]);
    }
}

int main(){
    int arr[] = {
        1,4,322,6,7,332,2,1,4
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n);
    printArray(arr,n);
    return 0;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j<=high-1; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if(low <= high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}