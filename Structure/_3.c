/* 
    	WAP to read and print an Student detail using structure, where student contain following data:
        Roll Number, Name, Course, Session
 */

#include <stdio.h>
#include "cls.h"
#include <string.h>

struct student
{
    int roll_no;
    char name[30],course[30];
    char session[20];
};

int main()
{
    struct student stu;
    cls();
    printf("Input The Following data:\n\t");
    printf("-Roll No. : ");
    scanf("%d",&stu.roll_no);
    getchar();
    printf("\t-Name : ");
    scanf("%[^\n]s", &stu.name);
    printf("\t-Course : ");
    scanf("%s", &stu.course);
    getchar();
    printf("\t-Session : ");
    scanf("%[^\n]s",&stu.session);

    printf("Roll No. \t Name \t Course \t Session\n\n");
    printf("%d\t", stu.roll_no);
    printf("%s\t", stu.name);
    printf("%s\t", stu.course);
    printf("%s\t", stu.session);
}