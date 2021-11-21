
/* 
    	WAP to read and print an Student detail using structure, where student contain following data:
        Roll Number, Name, Course, Joining Year
        Assume that there are not more than 450 students in the college.
		a. Write a function to print name of all students, who joined in a particular year.
		b. Write a function to print the data of all students who roll number is received by function.

 */

#include <stdio.h>
#include "cls.h"
#include <string.h>

struct student
{
    int roll_no;
    char name[30], course[30];
    int yoj;
};

void menu(struct student[], int);
void findByYear(struct student[], int);
void findByRollNo(struct student[], int);
void display(struct student[], int);

int main()
{
    cls();
    int size = 1;
    struct student stu[size];
    int min_size = 1;
    //Input Student Records...
    for (int i = 0; i < min_size; i++)
    {
        printf("\t-Roll No. : ");
        scanf("%d", &stu[i].roll_no);
        getchar();
        printf("\t-Name : ");
        scanf("%[^\n]s", &stu[i].name);
        printf("\t-Course : ");
        scanf("%s", &stu[i].course);
        getchar();
        printf("\t-Joining Year : ");
        scanf("%d", &stu[i].yoj);
        getchar();
    }
    //display all records...
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", stu[i].roll_no);
        printf("%s\t", stu[i].name);
        printf("%s\t", stu[i].course);
        printf("%d\n", stu[i].yoj);
        printf("\n");
    }

    menu(stu, size);

    return 0;
}

void menu(struct student stu[], int size)
{
    int choice;
    printf("\t\t\t - To Find Record By Year, Press 1\n");
    printf("\t\t\t - To Find Record By Roll No., Press 2\n");
    printf("\t\t\t - To Exit The Program., Press 3\n");

    printf("Input the Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
    {
        findByYear(stu, size);
        break;
    }
    case 2:
    {
        findByRollNo(stu, size);
        break;
    }
    case 3:
    {
        return;
        break;
    }
    default:
    {
        cls();
        printf("Invalid Input,Please Input Valid Number.");
        getchar();
        printf("\n\n");
        menu(stu, size);
    }
    }
}
void findByYear(struct student stu[], int size)
{
    int year;
    printf("Input the Year: ");
    scanf("%d", &year);

    for (int i = 0; i < size; i++)
    {
        if (year == stu[i].yoj)
        {
            display(stu, i);
        }
    }
    printf("\nThank you, Press any key to continue..\n");
    getchar();
    menu(stu, size);
}

void findByRollNo(struct student stu[], int size)
{
    int roll_no;
    printf("Input the RollNo. : ");
    scanf("%d", &roll_no);

    for (int i = 0; i < 1; i++)
    {
        if (roll_no == stu[i].roll_no)
            display(stu, i);
    }
    printf("\nThank You, Press any key to continue..\n");
    getchar();
    menu(stu, size);
}

void display(struct student stu[], int i)
{
    printf("%d\t", stu[i].roll_no);
    printf("%s\t", stu[i].name);
    printf("%s\t", stu[i].course);
    printf("%d\n", stu[i].yoj);
    printf("\n");
}
