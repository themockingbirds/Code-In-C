/* 
	1. WAP to create a structure, structure variable, initialize value to 
    it, assign values to structure variable also, ask user to input data then display 
    all result. Use all known method for this program.

 */

#include<stdio.h>
#include"cls.h" 
#include<string.h>

//Basic Form of Structure Definition.
struct
{
    int roll;
    char firstname[20], lastName[20];
} student1={1, "Ujjawal","Singh"},student2={2,"Rahul","Singh"};


int main(){
    //Accessing Structure Variable 
    printf("Roll No: %d\n",student1.roll);
    printf("First Name: %s\t", student1.firstname);
    printf("Last Name: %s\n", student1.lastName);

    //initilizing Structure Variable one by one-
    student1.roll=3;
    strcpy(student1.firstname,"Abhishek");
    strcpy(student1.lastName, "Kumar");

    printf("Roll No: %d\n", student1.roll);
    printf("First Name: %s\t", student1.firstname);
    printf("Last Name: %s\n", student1.lastName);

}