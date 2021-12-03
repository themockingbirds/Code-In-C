//Write a Program to Create a file and Write some data into it, when file don't exist already fprintf().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    FILE *fp;
    int a, b;
    system("clear");
    fp = fopen("abc.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        return 0;
    }
    else
    {
        printf("Welcome to My Program\n\n");
        printf("Input 1st No: ");
        scanf("%d", &a);
        printf("Input 2nd No: ");
        scanf("%d", &b);
        printf("Sum=%d", (a + b));
        fprintf(fp, "Input 1st No: %d\n Input 2nd No: %d\n Sum : %d", a, b, (a + b));
    }
    fclose(fp);
    return 0;
}