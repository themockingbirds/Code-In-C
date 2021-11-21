/* 
	1. WAP to create a structure, structure variable, initialize value to 
    it, assign values to structure variable also, ask user to input data then display 
    all result. Use all known method for this program.

 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int roll;
    char name[30];
};

int main(){
    //creating variable separately using structure tag.
    struct student stu1={1,"Ujjawal Singh"};
    printf("Roll No: %d\n",stu1.roll);
    printf("Name: %s\n", stu1.name);

    //taking user input into structure variable
    printf("Input Name: ");
    scanf("%[^\n]s",&stu1.name);

    printf("Input Roll: ");
    scanf("%d",&stu1.roll);

    
    printf("Roll No: %d\n", stu1.roll);
    printf("Name: %s\n", stu1.name);

    
}
