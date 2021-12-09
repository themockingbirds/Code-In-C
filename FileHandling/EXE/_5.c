/*
    5. WAP to rename a file using rename() function.
 */
#include <stdio.h>

int main()

{

    char oldName[100], newName[100];

    printf("Enter old file path: ");

    scanf("%s", oldName);

    printf("Enter new file path: ");

    scanf("%s", newName);

    if (rename(oldName, newName) == 0)

    {

        printf("File renamed successfully.\n");
    }

    else

    {

        printf("Unable to rename files. Please check files exist and you have permissions to modify files.\n");
    }

    return 0;
}