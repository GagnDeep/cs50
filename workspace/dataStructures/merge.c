#include<stdio.h>
void merge(int [],int ,int,int);
void mergeSort(int [],int,int);
int main(){
    int i,n;
    n=9;
    int arr[]={2,34,21,443,24,5,3,7,8};
    printf("Sorted array is : \n");
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void merge(int arr[],int l , int m , int r){

    //DECELERATIONS
    int i , j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    //TEMPERORY ARRAYS
    int temp1[n1],temp2[n2];

    //COPYING ELEMENTS TO TEMPERORY ELEMENTS
    for(i=0;i<n1;i++){
        temp1[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        temp2[j]=arr[m+1+j];
    }
    //MERGE TEMPERORY ARRAYS BACK INTO PRIMARY ARRAY
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(temp1[i]<=temp2[j]){
            arr[k]=temp1[i];
            i++;
        }else{
            arr[k]=temp2[j];
            j++;
        }
        k++;
    }
    //COPY REMAINING ELEMENTS OF TEMPERORY ARRAY
    while(i<n1){
        arr[k]=temp1[i];
        i++;
        k++;
    }
    while(i<n2){
        arr[k]=temp2[j];
        i++;
        k++;
    }
}
void mergeSort(int arr[],int l ,int r){
    if(l<r){
        int m = l+(r-l)/2;
        //TO SORT FIRST HALF
        mergeSort(arr,l,m);
        //TO SORT SECOND HALF
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}