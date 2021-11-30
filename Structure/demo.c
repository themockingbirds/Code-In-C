#include <stdio.h>

void read();
void display(int[], int[], int, int);
void sort1(int[], int[], int, int);
void merge(int[], int[], int, int);
void print(int[], int);
int main()
{
    read();
}

void read()
{
    int m, n;

    //input for array 1 
    printf("enter the size of array1: ");
    scanf("%d", &n);
    int var[n];
    for (int i = 0; i < n; i++)
    {
        printf("var[%d]: ", i);
        scanf("%d", &var[i]);
    }

    //input for array 2 
    printf("enter the size of array2: ");
    scanf("%d", &m);
    int varr[m];
    for (int i = 0; i < m; i++)
    {
        printf("var[%d]", i);
        scanf("%d", &varr[i]);
    }

    sort1(var, varr, n, m);

}

void sort1(int var[], int varr[], int n, int m)
{
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (var[i] > var[j])
            {
                temp = var[i];
                var[i] = var[j];
                var[j] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (varr[i] > varr[j])
            {
                temp = varr[i];
                varr[i] = varr[j];
                varr[j] = temp;
            }
        }
    }

    printf("Sorted Array:-\n");
    display(var, varr, n, m);
    printf("\nMerged Array: \n");
    merge(var, varr, n, m);
}

void merge(int var[], int varr[], int n, int m)
{

    int size = n + m;
    int j = 0, k = 0;
    int varNew[size];
    for (int i = 0; i < size; i++)
    {
        if (i < n)
        {
            varNew[i] = var[j];
            j++;
        }
        else
        {
            varNew[i] = varr[k];
            k++;
        }
    }
    print(varNew, size);
}

void print(int var[], int n)
{

    for (int i = 0; i < n; i++)
        printf("%d ", var[i]);
}
void display(int var[], int varr[], int n, int m)
{

    printf("\n\nArray 1: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", var[i]);
    }

    printf("\n\nArray 2: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", varr[i]);
    }

    printf("\n");
}