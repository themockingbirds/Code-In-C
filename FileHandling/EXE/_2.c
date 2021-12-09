/*
2. WAP to create a file and read data from file.
    a. Using fscanf
    b. Using fgets
    c. Using fgetc
 */

#include <stdio.h>
#include <stdlib.h>

void f_scanf();
void f_gets();
void f_getc();

char data[100];
int main()
{

    system("clear");
    printf("Using fscanf():\n");
    f_scanf();

    printf("Using fputs():\n");
    f_gets();

    printf("Using fputc():\n");
    f_getc();

    return 0;
}

void f_scanf()
{
    FILE *fptr = fopen("FILES/fprintf.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }

    fscanf(fptr, "%[^\n]s", data);
    printf("\t%s\n",data);
    fclose(fptr);
    fflush(stdin);
}

void f_gets()
{
    FILE *fptr = fopen("FILES/fputs.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }
    fgets(data,100,fptr);
    printf("\t%s\n",data);
    fclose(fptr);
    fflush(stdin);
    
}

void f_getc()
{
    FILE *fptr = fopen("FILES/fputc.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }
    char ch;
    printf("\t");
    while (1)
    {
        ch = fgetc(fptr);
        if (ch == EOF)
            break;
        printf("%c", ch);
    }
    printf("\n");
    fclose(fptr);
    fflush(stdin);
}