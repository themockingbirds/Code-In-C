//Write a Program to Create a file with specific location and Input some data into a file.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    char ch;
    system("clear");
    fp = fopen("//Users//Documents/abc.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        return 0;
    }
    else
    {
       printf("File Successfull Created...\n");
    }
    fclose(fp);
    return 0;
}