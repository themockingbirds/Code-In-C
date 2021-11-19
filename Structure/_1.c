/* 
	1. WAP to create a structure, structure variable, initialize value to 
    it, assign values to structure variable also, ask user to input data then display 
    all result. Use all known method for this program.

 */

#include<stdio.h>
#include"cls.h"
#include<string.h>

//Basic Form of Structure.
struct
{
    int roll;
    char firstname[20], lastName[20];
} student1, student2;

int main(){

    return 0;
}

void fun1(){
    //Structure Definition and Variable Declaration Type - 1
    struct
    {
        int roll;
        char firstname[20], lastName[20];
    } student1, student2;
}
void fun2(){
    //Structure Definition, Structure Variable Declaration with Structure Tag  Type - 2
    struct a
    {
        int rollNo;
        char firstname[20], lastName[20];
    } s;
    struct a s1, s2;
}
void fun3(){
    //Structure Definition, Structure Variable Declaration with Structure Tag  Type - 3
    struct b
    {
        int rollNo;
        char firstname[20], lastName[20];
    } stu;
    struct b stu1, stu2;
}
void fun4(){
    //Structure Definition with Structure Tag  Type - 4
    struct c
    {
        int rollNo;
        char firstname[20], lastName[20];
    };
    struct c cstu1, cstu2;
}

void fun5(){
    //Structure Definition with Structure Tag and Structure Variable Initilization Type - 1
    struct abc
    {
        int roll;
        char fullName[30];

    } p1 = {3, "Rahul Singh"};

    struct abc p2 = {4, "Abhishek Singh"};
}