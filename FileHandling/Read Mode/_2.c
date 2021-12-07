//Write a Program to Create a file and Read some data from file, when file already exist using fgetc() with feof().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    char ch;
    system("clear");
    fp = fopen("abc.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        return 0;
    }
    else
    {
        while (!feof(fp))
        {
            ch = fgetc(fp);
            printf("%c", ch);
        }
    }
    fclose(fp);
    return 0;
}