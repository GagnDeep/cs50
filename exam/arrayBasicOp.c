#include<stdio.h>
#include<string.h>

void insert(int[], int, int, int);
void printArray(int [], int);
void deleteArray(int [], int ,int );
int binary(int [], int, int, int);
void rev(char [],int,int);

int main(){
    int array[10] = {1,3,4,5,6,34,56};
    int n = 7;
    // insert(array,0,666,n);
    // printArray(array,n);
    // deleteArray(array,0,n);
    // n = n-1;
    // printf("\n");
    // printArray(array,n);
    int search = binary(array,0,n,5);
    if(search == -9999){
        printf("\nelement not found");
    }else{
        printf("\nelement found at loc - %d\n",search);
    }

    char string[] = "gagandeep singh";

    rev(string,0,strlen(string) - 1);
    printf("\n %s",string);
    return 0;
}
void rev(char str[],int start,int end){
    if(start > end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    rev(str,start+1,end-1);
}

int binary(int arr[], int left, int right, int item){
    if(right >= left){
        int mid = left + (right - left)/2;
        if( arr[mid] == item ){
            return mid;
        }
        if(arr[mid] > item)
            return binary(arr,left,mid-1,item);
        else
        return binary(arr,mid+1, right, item);
    }
    return -9999;
}

void deleteArray(int arr[], int loc, int n){
    int item;
    if(loc == n){
        n = n-1;
        return;
    }
    for(int i = loc +1; i<n ;i++){
        arr[i - 1] = arr[i];
    }

    return;
}

void insert(int arr[],int loc, int item, int n){
    if(loc == n+1){
        arr[loc] = item;
        return;
    }
    for(int i = n+1; i<=loc; i++){
        arr[i] = arr[i-1];
    }
    arr[loc] = item;
    return;
}

void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        printf("%4d",arr[i]);
    }
}