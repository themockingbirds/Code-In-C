// Write a Program to Create a file and Read some data from file, when file already exist using fgetc().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    char ch;
    system("clear");
    fp = fopen("/Users/me/Library/Mobile Documents/com~apple~CloudDocs/Code In C/FileHandling/abc.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        return 0;
    }
    else
    {
        fgets()
    }
    fclose(fp);
    return 0;
}