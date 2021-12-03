#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define 
void new_acc();
void edit();
void transact();
void see();
void erase();
void view_list();
void close();
void atm();

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
            close();
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

void new_acc()
{

}
void edit()
{

}
void transact()
{

}
void see()
{

}
void erase()
{

}
void view_list()
{

}
void atm()
{
    
}
void close()
{

}