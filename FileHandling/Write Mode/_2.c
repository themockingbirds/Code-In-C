//Write a Program to Create a file and Write some data into it, when file don't exist already using fputs().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    int a, b;
    char str1[30];
    system("clear");
    fp = fopen("abcd.txt", "w");
    if(fp==NULL){
        printf("Error");
        return 0;
    }
    else{
        printf("Input Your Name: ");
        scanf("%[^\n]s",str1);
        fputs(str1,fp);
    }
    fclose(fp);
    return 0;
}