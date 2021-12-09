#include <stdio.h>

#include <stdlib.h>

void toggleCase(FILE *fptr, const char *path);

int main()

{

    FILE *fPtr;

    char path[100];

    printf("Enter path of source file: ");

    scanf("%s", path);

    fPtr = fopen(path, "r");

    if (fPtr == NULL)

    {

        printf("\nUnable to open file.\n");

        printf("Please check whether file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    toggleCase(fPtr, path);

    printf("\nSuccessfully converted characters in file from uppercase to lowercase and vice versa.\n");

    return 0;
}

void toggleCase(FILE *fptr, const char *path)

{

    FILE *dest;

    char ch;

    dest = fopen("toggle.tmp", "w");

    if (dest == NULL)

    {

        printf("Unable to toggle case.");

        fclose(fptr);

        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fptr)) != EOF)

    {

        if (isupper(ch))

            ch = tolower(ch);

        else if (islower(ch))

            ch = toupper(ch);

        fputc(ch, dest);
    }

    fclose(fptr);

    fclose(dest);

    remove(path);

    rename("toggle.tmp", path);
}