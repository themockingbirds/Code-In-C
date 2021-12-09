/* Title : Program to list all files and sub-directories in a directory */

#include <stdio.h>

#include <sys/types.h>

#include <dirent.h>

void listFiles(const char *path);

int main()

{

    char path[100];

    printf("Enter path to list files: ");

    scanf("%s", path);

    listFiles(path);

    return 0;

}

void listFiles(const char *path)

{

    struct dirent *dp;

    DIR *dir = opendir(path);

    if (!dir) 

        return; 

    while ((dp = readdir(dir)) != NULL)

    {

        printf("%s\n", dp->d_name);

    }

    closedir(dir);

}