#include<stdio.h>
#include<stdlib.h>

//FUNCTION PERFORMING SORT OPERATIONS
void merge(int [],int,int,int);

//FUNTION RESPONSIBLE FOR MERGING ARRAY
void mergeSort(int [],int,int);

//MAIN FUNCTION
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

//merge function
void merge(int arr[],int l ,int m,int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

        // TEMPERORY ARRAYS FOR STORING
        int temp1[n1];
        int temp2[n2];

        //COPY DATA TO TEMPERORY ARRAYS TEMP1 AND TEMP2
        for(i = 0 ; i < n1 ; i++){
            temp1[i] = arr[l+i];
        }
        for(j = 0 ; j < n2 ; j++){
            temp2[j] = arr[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;
        //MERGE TEMPERARORY ARRAY INTO PRIMARY ARRAY
        while(i<n1 && j < n2){
            if(temp1[i]<=temp2[j]){
                arr[k]  = temp1[i];
                i++;
            }else{
                arr[k] = temp2[j];
                j++;
            }
            k++;
        }

        //COPING REMAINING ELEMENTS(IF ANY)
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

//mergesort function
void mergeSort(int arr[],int l , int r){
    if(l<r){
        int m = l + (r-l)/2;
        //SORT FIRST HALF
        mergeSort(arr,l,m);
        //SORT SECOND HALF
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }

}


