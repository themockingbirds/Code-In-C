/* Title : Program to copy one file to another using function */

#include <stdio.h>

#include <stdlib.h>

int fcpy(FILE * sourceFile, FILE * destFile);

int main()

{

    FILE *sourceFile;

    FILE *destFile;

    char sourcePath[100];

    char destPath[100];

    int count;

    printf("Enter source file path: ");

    scanf("%s", sourcePath);

    printf("Enter destination file path: ");

    scanf("%s", destPath);

    sourceFile  = fopen(sourcePath, "r");

    destFile    = fopen(destPath,   "w");

    if (sourceFile == NULL || destFile == NULL)

    {

        printf("\nUnable to open file.\n");

        printf("Please check if file exists and you have read/write privilege.\n");

        exit(EXIT_FAILURE);

    }

    count = fcpy(sourceFile, destFile);

    printf("\nFiles copied successfully.\n");

    printf("%d characters copied.\n", count);

    fclose(sourceFile);

    fclose(destFile);

    return 0;

}

int fcpy(FILE * sourceFile, FILE * destFile)

{

    int  count = 0;

    char ch;

    while ((ch = fgetc(sourceFile)) != EOF)

    {

        fputc(ch, destFile);

        count++;

    }

    return count;

}