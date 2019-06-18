#include<stdio.h>
#include<stdlib.h>

void merge(int [], int,int,int);
void mergeSort(int [],int,int);
int main(){
    int arr[] = {6,32,66,74,11,1,3};
    int i,n;
    n = 7;
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0 ;
}
void merge(int arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m -l +1;
    int n2 = r - m;
    int temp1[n1];
    int temp2[n2];
    for(i = 0; i<n1; i++){
        temp1[i] = arr[l+i];
    }
    for(j=0; j<n2; j++){
        temp2[j] = arr[m+j+1];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    int m;
    if(l<r){
       m = l + (r-l)/2;
       mergeSort(arr,l,m);
       mergeSort(arr,m+1,r);
       merge(arr,l,m,r);
    }
}