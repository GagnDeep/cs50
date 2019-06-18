#include<stdio.h>

void merge(int [], int, int, int);
void mergeSort(int [], int, int);
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
    mergeSort(arr,0,n);
    printArray(arr,n);
    return 0;
}

void mergeSort(int arr[], int left, int right){
    if(right > left){
        int mid = left + (right - left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

void merge(int arr[], int left, int mid, int right){
    int i,j,k;
    int n1,n2;
    n1 = mid - left+1;
    n2 = right - mid;
    int temp1[n1],temp2[n2];
    for(i = 0; i<n1;i++){
        temp1[i] = arr[left + i];
    }
    for(j = 0; j <n2;j++){
        temp2[j] = arr[mid+j+1];
    }
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    while(j < n2){
        arr[k] = temp2[j];
        j++;
        k++;
    }
    while(i < n1){
        arr[k] = temp1[i];
        i++;
        k++;
    }
}