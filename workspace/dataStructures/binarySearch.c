#include<stdio.h>
int main(){
    int arr[] = {6,32,66,74,11,1,3};
    int n,i,j,swap,position;
    n=7;
    for(i=1;i<n;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=swap;
            j--;
        }
    }
    int search=32;
    int first ,last,middle;
    first = 0;
    last = n;
    middle = (first + last)/2;
    while(first<=last){
        if(arr[middle]<search){
            first = middle+1;
        }else if(arr[middle]== search){
            printf("the element %d is at location : %d\n",search,middle+1);
            break;
        }else{
            last = middle -1;
        }
        middle = (first+last)/2;
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    if(first>last)
    printf("\nelement not found int the array of integers hence we are extremely sorry!!\n");
    return 0;
}
