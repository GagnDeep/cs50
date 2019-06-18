#include<stdio.h>
#include<stdlib.h>

void insertion(int *);
int n = 6;
int main(){
       int array[10] = {1,3,5,2,6,7};
       int loc , item,i,choise;

       while(1){
           printf("\n1.Insert Element  2.Print Array  3.Exit\n");
           scanf("%d",&choise);
           switch(choise){
           case 1:
           insertion(array);
           break;
           case 2:
           printf("\nArray ------------>\n");
           for(i = 0 ; i < n ; i++)
           printf("%d ",array[i]);
           break;
           case 3:
           exit(0);
       }
       }
}

void insertion(int *p){
       int loc , item,i;
    printf("\nEnter Location : ");
           scanf("%d",&loc);
           printf("\nEnter Element : ");
           scanf("%d",&item);
           if(loc == n){
               *(p+n) = item;
               n++;
           }else{
               for(i = n - 1; i >= loc-1 ; i--){
               *(p+i+1) = *(p + i);
               }
               *(p+loc-1) = item;
               n++;
       }
}