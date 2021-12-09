/*
9. Program to find occurrence of a word in file
 */
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define BUFFER_SIZE 1000

int indexOf(FILE *fptr, const char *word, int *line, int *col);

int main()

{

    FILE *fptr;

    char path[100];

    char word[50];

    int line, col;

    printf("Enter file path: ");

    scanf("%s", path);

    printf("Enter word to search in file: ");

    scanf("%s", word);

    fptr = fopen(path, "r");

    if (fptr == NULL)

    {

        printf("Unable to open file.\n");

        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    indexOf(fptr, word, &line, &col);

    if (line != -1)

        printf("'%s' found at line: %d, col: %d\n", word, line + 1, col + 1);

    else

        printf("'%s' does not exists.", word);

    fclose(fptr);

    return 0;
}

int indexOf(FILE *fptr, const char *word, int *line, int *col)

{

    char str[BUFFER_SIZE];

    char *pos;

    *line = -1;

    *col = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)

    {

        *line += 1;

        pos = strstr(str, word);

        if (pos != NULL)

        {

            *col = (pos - str);

            break;
        }
    }

    if (*col == -1)

        *line = -1;

    return *col;
}