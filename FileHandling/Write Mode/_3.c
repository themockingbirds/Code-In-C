//Write a Program to Create a file and Write some data into it, when file don't exist already using fputc().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    int a, b;
    char str1[30];
    system("clear");
    fp = fopen("abcde.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        return 0;
    }
    else
    {
        printf("Input Your Name: ");
        scanf("%[^\n]s", str1);

        for(int i=0;str1[i]!='\0';i++){
            fputc(str1[i],fp);
        }
    }
    fclose(fp);
    return 0;
}