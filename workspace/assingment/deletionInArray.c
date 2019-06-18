#include<stdio.h>
#include<stdlib.h>

void deletion(int *);
int n = 6;
int main(){
       int array[10] = {1,3,5,2,6,7};
       int loc , item,i,choise;

       while(1){
           printf("\n1.Delete Element  2.Print Array  3.Exit\n");
           scanf("%d",&choise);
           switch(choise){
           case 1:
           deletion(array);
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
void deletion(int *p){
    int loc , i;
    printf("\nEnter Location : ");
    scanf("%d",&loc);
    if(loc>=n || loc<=0){
        printf("\nDeletion not possible");
        return;
    }
    for(i = loc-1; i < n-1 ; i++){
        p[i] = p[i+1];
    }
    n--;
}