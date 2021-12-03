#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    system("clear");
    printf("Enter number: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++)
    {
        if (i % 2 == 0)
        {
            printf("\n%d is not a Prime Number", i);
            getchar();
            //exit(0);
        }
    }
    printf("\n%d is a Prime Number", n);
    return 0;
}