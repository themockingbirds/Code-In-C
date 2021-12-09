/* 
1. WAP to create a file and write data into file.
    a.Using fprintf
    b.Using fputs
    c.Using fputs
*/
#include <stdio.h>
#include <stdlib.h>

void f_printf();
void f_puts();
void f_putc();
void input();

char data[100];
int main()
{
    
    system("clear");
    printf("Using fscanf():\n");
    input();
    f_printf();

    printf("Using fputs():\n");
    input();
    f_puts();

    printf("Using fputc():\n");
    input();
    f_putc();

    return 0;
}

void f_printf(){
    FILE *fptr = fopen("FILES/fprintf.txt", "w");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }
   
    fprintf(fptr,"%s",data);
    fclose(fptr);
    fflush(stdin);
    printf("File created and saved successfully. :) \n");
}

void f_puts(){
    FILE *fptr = fopen("FILES/fputs.txt", "w");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }
    fputs(data,fptr);
    fclose(fptr);
    fflush(stdin);
    printf("File created and saved successfully. :) \n");
    
}

void f_putc(){
    FILE *fptr = fopen("FILES/fputc.txt", "w");
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }
    for (int i = 0; data[i] != '\0'; i++)
    {
        fputc(data[i], fptr);
    }
    fclose(fptr);
    fflush(stdin);
    printf("File created and saved successfully. :) \n");
}

void input(){
    printf("Enter contents to store in file : \n");
    scanf("%[^\n]s",data);
}