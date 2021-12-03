#include<stdio.h>
#include<string.h>

typedef struct student
{
    int a;
    char *name;
}stu;


int main(){

    stu s1, s2;
    s1.a=2;
    strcpy(s1.name,"Hello");
    printf("%d, %s",s1.a,s1.name);
    return 0;
}