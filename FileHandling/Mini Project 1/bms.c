/*
    5. Create a structure to specify the data of customers in bank. The data to be stored is: Account Number,
    Name, Balance in account. Assume maximum of 200 customers in the bank.

    a. Write a function to print the account number and name of each customer with balance below Rs. 100.

    b. if a customer request for withdrawal or deposit, the form contains the following filed:
    Acct. No., amount, code,(1. For deposit, 0 for Withdrawal)

    Write a program to give a message, "The balance is insufficient for the specific withdrawal",
    if the withdrawal balance falls below Rs. 100.
 */

#include <stdio.h>
#include <string.h>
#include "cls.h"

const int size = 2;
struct bank
{
    int acc_no;
    char name[30];
    float blnc;
    int code;
} customer[size];

void find(struct bank[], int);
void menu();
void display();
void operation(struct bank[], int);

int main()
{
    cls();
    int code = 2500;
    //Welcome Message...
    printf("\n");
    printf("\t#################                            #################\n");
    printf("\t################# WELCOME TO OUR BANK PORTAL #################\n");
    printf("\t#################                            #################\n");
    // input data
    printf("\n\tInput all customers details...\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("\t\tCustomer %d\n", i + 1);
        printf("\t\t\t - Name: ");
        scanf("%[^\n]s", &customer[i].name);
        printf("\t\t\t - Account No: ");
        scanf("%d", &customer[i].acc_no);
        printf("\t\t\t - Balance: ");
        scanf("%f", &customer[i].blnc);
        getchar();
        code += 2;
        customer[i].code = code;
        printf("\n");
        if (i == size - 1)
        {
            printf("\t\tRecords Successfully Submitted...");
            printf("\n\t\tPress Enter to continue...");
            getchar();
        }
    }
    cls();
    display();
    menu();
    // function to find records of those customers whose acc blnc is below 100
    // find(customer,size);
    // function to perform deposit and withdrawal operation
    // operation(customer, size);

    return 0;
}
void menu()
{
    int ch;
    printf("\n\t==============================Menu=============================\n\n");
    printf("\t\t\t-1. Search \n");
    printf("\t\t\t-2. Deposit & Withdrawal\n");
    printf("\t\tInput:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        cls();
        find(customer, size);
        break;
    case 2:
        cls();
        display();
        operation(customer, size);
        break;

    default:
        cls();
        printf("\t\tInvalid Input,plase input again:\n\n");
        fflush(stdin);
        menu();
        break;
    }
}

void find(struct bank customer[], int size)
{
    int count = 0;
    cls();
    for (int i = 0; i < size; i++)
    {
        if (customer[i].blnc < 100)
        {   
            

            if(count==0){
                printf("\n\tRecords Found..\n");
                printf("\tName\tAccount No\tBalance\t\tcode\n");
            }
            
            printf("\t%s\t\t", customer[i].name);

            printf("%4d\t\t", customer[i].acc_no);

            printf("%.2f\t\t", customer[i].blnc);
            printf("%4d", customer[i].code);
            printf("\n\n");
            count++;
        }
    }
    if (count > 0)
    {
        printf("\n\t|--Total %d Records Found.--|\n", count);
    }
    else
    {
        printf("\t\tNo Records Found.\n");
    }
    fflush(stdin);
    printf("\n\tPress \"ENTER\" to continue...");
    getchar();
    cls();
    display();
    menu();
}

void operation(struct bank customer[], int size)
{
    int flag=0;
    printf("\n\t|------------------------Deposit//Withdrawal------------------|\n");
    printf("\t\t\tPress -1. Deposit\n");
    printf("\t\t\tPress -2: Witdrawal\n");
    printf("\n\t|-------------------------------------------------------------|\n");
    int ch, acc_no, pin, temp;
    printf("\tINPUT: ");
    scanf("%d", &ch);
    if (ch == 1 || ch == 2)
    {
        printf("\n\t\tEnter ACCOUNT NO : ");
        scanf("%d", &acc_no);
        printf("\n\t\tEnter 4 digit Pin : ");
        scanf("%d", &pin);
        for (int i = 0; i < size; i++)
        {

            if (customer[i].acc_no == acc_no && customer[i].code == pin)
            {   
                flag=1;
                switch (ch)
                {
                case 1:
                    
                    printf("\n\t\tEnter Ammount To Deposit : ");
                    scanf("%d", &temp);
                    customer[i].blnc += temp;
                    printf("\n\tCurrent Balance:%f\n", customer[i].blnc);
                    printf("\tThank You For Using Our Service, Have a Good Day !!,\n\tPress \"ENTER\" to Continue...");
                    fflush(stdin);
                    getchar();
                    cls();
                    display();
                    menu();
                    break;
                case 2:
                    if (customer[i].blnc > 100)
                    {
                        printf("\n\t\tEnter Withdrawal Ammount: ");
                        scanf("%d", &temp);
                        if (temp < 100 || temp%100!=0)
                        {
                            printf("\tInvalid Amount, Please \"ENTER\" To Continue...");
                            fflush(stdin);
                            getchar();
                            cls();
                            display();
                            operation(customer, size);
                        }
                        else
                        {
                            customer[i].blnc -= temp;
                            printf("\n\tCurrent Balance:%f\n", customer[i].blnc);
                            printf("\n\tThank You For Using Our Service, Have a Good Day !!,\n\tPress \"ENTER\" to Continue...");
                            fflush(stdin);
                            getchar();
                            cls();
                            display();
                            menu();
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("\n\t\tInsufficient Balnace,\n\t\tEnter to continue...");
                        getchar();
                        cls();
                        display();
                        operation(customer, size);
                    }
                    break;
                default:
                    printf("\tInvalid Input......");
                    operation(customer, size);
                }
            }
        }
        if (flag == 0)
        {
            printf("\n\t\tInvalid Pin Or Account No.\n\t\tEnter to Continue..");
            fflush(stdin);
            getchar();
            cls();
            display();
            operation(customer, size);
        }
    }
    else
    {
        printf("\t\tInvalid Input,plase input again...\n\n");
        fflush(stdin);
        getchar();
        cls();
        display();
        operation(customer, size);
    }
}

void display()
{
    printf("\n\tList Of All Customer and Thier Details are given Below: \n");
    printf("\tName\tAccount No\tBalance\t\tcode\n");

    // print all record on the console...
    for (int i = 0; i < size; i++)
    {
        printf("\t%s\t\t", customer[i].name);

        printf("%4d\t\t", customer[i].acc_no);

        printf("%.2f\t\t", customer[i].blnc);
        printf("%4d", customer[i].code);
        printf("\n\n");
    }
}