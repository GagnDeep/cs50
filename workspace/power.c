#include<stdio.h>
#include<stdlib.h>

int main(){
    int number,expo,i,ans;
    ans =1;
    i = 0;
    expo=0;
    char string[100];
    scanf("%s",string);
    number = atoi(string);
    while(string[i]!='^'){
        i++;
    }
    for(int j = i;string[j]!= '\0';j++){
        expo = expo*10;
        expo = expo+string[i] - '0';

    }
    for(int j =0;j<expo;j++){
        ans = ans * number;
    }
    printf("%d : number\n%d : expo\n%d : ans",number,expo,ans);
}