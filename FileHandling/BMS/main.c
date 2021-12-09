#include <stdio.h>
#include <stdlib.h>
//#include<windows.h>
#include <unistd.h>
#include <stdbool.h>
#include<string.h>
#include "atm.h"
#include "edit.h"
#include "menu.h"
#include "new_acc.h"
#include "see.h"
#include "transact.h"
#include "view.h"

int i, j;
int main_exit;

struct date
{
    int month, day, year;
};

struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}
void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}
void closed()
{
    printf("\n\n\n\nBrought To You by code-projects.org");
}

int main()
{
    char pass[10], password[10] = "pass";
    int i = 0;
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s", pass);
    /*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {
            printf("*");
            pass[i]=getch();
            i++;
        }
    }while (pass[i]!=13);
    pass[10]='\0';*/
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
        system("pause");
        system("clear");

        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
            closed();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    return 0;
}