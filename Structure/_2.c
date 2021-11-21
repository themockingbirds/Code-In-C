/* 
	
	WAP to read and print an employee's detail using structure, where employee contain following data:
	Employee ID, Name, Salary, city, phone no.

 */

#include<stdio.h>
#include"cls.h"
#include<string.h>

struct employee 
{
    int emp_id,phone_no;
    char name[30],city[30];
    float salary;

};

int main(){
    struct employee emp;

    printf("Input The Following data:\n\t");
    printf("-Name : ");
    scanf("%[^\n]s",&emp.name);
    printf("\t-Employee Id : ");
    scanf("%d",&emp.emp_id);
    getchar();
    printf("\t-City : ");
    scanf("%[^\n]s",&emp.city);

    printf("\t-Salary : ");
    scanf("%f",&emp.salary);

    printf("Emp_ID \t Name \t City \t Phone No. \t Salary\n\n");
    printf("%d\t", emp.emp_id);
    printf("%s\t",emp.name);
    printf("%s\t",emp.city);
    printf("%.d\t",emp.phone_no);
    printf("%.2f\n", emp.salary);
}