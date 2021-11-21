
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

const int size = 450;
struct student stu[size];

void menu();
void inputData();
void display();
void displayAll();
void findByYear();
void findByRollNo();

int main()
{
    cls();
    menu();
}

void menu()
{
    int choice;
    printf("\t\t\t - To Input Data, Press 1\n");
    printf("\t\t\t - To View All Data, Press 2\n");
    printf("\t\t\t - To Find Record By Year, Press 3\n");
    printf("\t\t\t - To Find Record By Roll No., Press 4\n");
    printf("\t\t\t - To Exit The Program., Press 5\n");

    printf("Input the Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        inputData();
        break;
    }
    case 2:
    {
        displayAll();
        break;
    }
    case 3:
    {
        findByYear();
        break;
    }
    case 4:
    {
        findByRollNo();
        break;
    }
    case 5:
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
        menu();
    }
    }
}
void inputData()
{

    printf("Input The Following data:\n\n");
    for (int i = 0; i < size; i++)
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
    printf("\nRecord Submitted Successfull, Press any key to continue..\n");
    getchar();
    menu();
}
void findByYear()
{
    int year;
    printf("Input the Year: ");
    scanf("%d", &year);

    for (int i = 0; i < size; i++)
    {
        if (year == stu[i].yoj)
        {
            display(i);
        }
    }
    printf("\nThank you, Press any key to continue..\n");
    getchar();
    menu();
}

void findByRollNo()
{
    int roll_no;
    printf("Input the RollNo. : ");
    scanf("%d", &roll_no);

    for (int i = 0; i < 1; i++)
    {
        if (roll_no == stu[i].roll_no)
            display(i);
    }
    printf("\nThank You, Press any key to continue..\n");
    getchar();
    menu();
}
void display(int i)
{
    printf("%d\t", stu[i].roll_no);
    printf("%s\t", stu[i].name);
    printf("%s\t", stu[i].course);
    printf("%d\n", stu[i].yoj);
    printf("\n");
}

void displayAll()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", stu[i].roll_no);
        printf("%s\t", stu[i].name);
        printf("%s\t", stu[i].course);
        printf("%d\n", stu[i].yoj);
        printf("\n");
    }
    printf("\nThank You, Press any key to continue..\n");
    getchar();
    menu();
}
