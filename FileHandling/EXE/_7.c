/*
    7. Program to remove specific line from a file
 */

#include <stdio.h>

#include <stdlib.h>

#define BUFFER_SIZE 1000

void deleteLine(FILE *srcFile, FILE *tempFile, const int line);

void printFile(FILE *fptr);

int main()

{

    FILE *srcFile;

    FILE *tempFile;

    char path[100];

    int line;

    printf("Enter file path: ");

    scanf("%s", path);

    printf("Enter line number to remove: ");

    scanf("%d", &line);

    srcFile = fopen(path, "r");

    tempFile = fopen("delete-line.tmp", "w");

    if (srcFile == NULL || tempFile == NULL)

    {

        printf("Unable to open file.\n");

        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    printf("\nFile contents before removing line.\n\n");

    printFile(srcFile);

    rewind(srcFile);

    deleteLine(srcFile, tempFile, line);

    fclose(srcFile);

    fclose(tempFile);

    remove(path);

    rename("delete-line.tmp", path);

    printf("\n\n\nFile contents after removing %d line.\n\n", line);

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

void deleteLine(FILE *srcFile, FILE *tempFile, const int line)

{

    char buffer[BUFFER_SIZE];

    int count = 1;

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)

    {

        if (line != count)

            fputs(buffer, tempFile);

        count++;
    }
}