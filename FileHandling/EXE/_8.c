/*
    8. WAP to remove empty lines from file.
 */

#include <stdio.h>

#include <stdlib.h>

#define BUFFER_SIZE 1000

int isEmpty(const char *str);

void removeEmptyLines(FILE *srcFile, FILE *tempFile);

void printFile(FILE *fptr);

int main()

{

    FILE *srcFile;

    FILE *tempFile;

    char path[100];

    printf("Enter file path: ");

    scanf("%s", path);

    srcFile = fopen(path, "r");

    tempFile = fopen("remove-blanks.tmp", "w");

    if (srcFile == NULL || tempFile == NULL)

    {

        printf("Unable to open file.\n");

        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    printf("\nFile contents before removing all empty lines.\n\n");

    printFile(srcFile);

    rewind(srcFile);

    removeEmptyLines(srcFile, tempFile);

    fclose(srcFile);

    fclose(tempFile);

    remove(path);

    rename("remove-blanks.tmp", path);

    printf("\n\n\nFile contents after removing all empty line.\n\n");

    srcFile = fopen(path, "r");

    printFile(srcFile);

    fclose(srcFile);

    return 0;
}

void printFile(FILE *fptr)

{

    char ch;

    while ((ch = fgetc(fptr)) != EOF)

        putchar(ch);
}

int isEmpty(const char *str)

{

    char ch;

    do

    {

        ch = *(str++);

        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')

            return 0;

    } while (ch != '\0');

    return 1;
}

void removeEmptyLines(FILE *srcFile, FILE *tempFile)

{

    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)

    {

        if (!isEmpty(buffer))

            fputs(buffer, tempFile);
    }
}