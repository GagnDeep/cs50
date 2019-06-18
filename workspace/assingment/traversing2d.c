#include<stdio.h>
int main(){
    int arr[4][4] = {
                  {1,2,4,5},
                  {2,5,7,9},
                  {3,5,1,6},
                  {2,1,5,4}
        };
    int i, n, j, m;
    n = 4;
    m = 4;
    printf("Array -------> \n\n");
    printf("***************");
    for(i = 0 ; i < m; i++){
        printf("\n");
        for(j = 0; j < n; j++)
        printf("%d ",arr[i][j]);
    }
    printf("\n****************\n");
    return 0;
}