#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Input No Of Rows: ");
    scanf("%d",&n);
    if(n%2==0){
        n+=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(){
                printf("*");

            }else{
                printf(" ");
            }
        }   
    }
}