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

const int size = 3;
struct bank
{
    int acc_no;
    char name[30];
    float blnc;
    int code;
} customer[size];

void find(struct bank[], int);
void menu();
void operation(struct bank[], int);
int main()
{
    cls();
    int code = 2500;
    //input data
    printf("Input all customers details...\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("\tCustomer %d\n", i + 1);
        printf("\t\t- Name: ");
        scanf("%[^\n]s", &customer[i].name);
        printf("\t\t - Account No: ");
        scanf("%d", &customer[i].acc_no);
        printf("\t\t - Balance: ");
        scanf("%f", &customer[i].blnc);
        getchar();
        code += 2;
        customer[i].code = code;
        printf("\n");
        if (i == size - 1)
        {
            printf("->-> Records Successfully Submitted...");
            printf("\n->-> Press Enter to continue...");
            getchar();
        }
    }
    cls();
    printf("List Of All Customer and Thier Details are given Below: \n");
    printf("Name\t Account No\t Balance\t code\n");

    //print all record on the console...
    for (int i = 0; i < size; i++)
    {
        printf("%s\t", customer[i].name);

        printf("%d\t", customer[i].acc_no);

        printf("%.2f\t", customer[i].blnc);
        printf("%d", customer[i].code);
        printf("\n\n");
    }

    menu();
    //function to find records of those customers whose acc blnc is below 100
    //find(customer,size);
    //function to perform deposit and withdrawal operation
    //operation(customer, size);

    return 0;
}
void menu()
{
    int ch;
    printf("\n==============================Menu=============================\n\n");
    printf("\t\t-1. Search \n");
    printf("\t\t-2. Deposit & Withdrawal\n");
    printf("Input:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        find(customer, size);
        break;
    case 2:
        operation(customer, size);
        break;

    default:

        cls();
        printf("Invalid Input,plase input again:\n\n");
        menu();
        break;
    }
}

void find(struct bank customer[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (customer[i].blnc < 100)
        {
            printf("Records Found..\n\n");

            printf("Name : %s\t", customer[i].name);

            printf("Account No: %d\t", customer[i].acc_no);

            printf("Balance: %.2f\t", customer[i].blnc);

            printf("\n");
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
    menu();
}

void operation(struct bank customer[], int size)
{

    printf("\n|-------------------------------------------------------------|\n");
    printf("\t\tPress -1. Deposit\n");
    printf("\t\tPress -2: Witdrawal\n");
    printf("\n|-------------------------------------------------------------|\n");
    int ch, acc_no, pin, temp;
    printf("INPUT: ");
    scanf("%d", &ch);
    if (ch == 1 || ch == 2)
    {
        printf("\n\tEnter ACCOUNT NO : ");
        scanf("%d", &acc_no);
        printf("\n\tEnter 4 digit Pin : ");
        scanf("%d", &pin);
        for (int i = 0; i < size; i++)
        {

            if (customer[i].acc_no == acc_no && customer[i].code == pin)
            {
                switch (ch)
                {
                case 1:
                    printf("Enter Ammount To Deposit : ");
                    scanf("%d", &temp);
                    customer[i].blnc += temp;
                    printf("Current Balance:%f\n", customer[i].blnc);
                    menu();
                    break;
                case 2:
                    if (customer[i].blnc > 100)
                    {
                        printf("Enter Withdrawal Ammount: ");
                        scanf("%d", &temp);
                        if (temp < 100)
                        {
                            printf("Invalid Amount, Thank you");
                        }
                        else
                        {
                            customer[i].blnc -= temp;
                            printf("Current Balance:%f\n", customer[i].blnc);
                        }
                    }
                    else
                    {
                        printf("Insufficient Balnace");
                        getchar();
                        cls();
                        operation(customer, size);
                    }
                    break;
                default:
                    printf("Invalid Input....");
                    operation(customer, size);
                }
            }
            else
            {
                printf("Invalid Data...\n");
                operation(customer, size);
            }
        }
    }
    else
    {
         printf("Invalid Pin Or Account No");
         operation(customer, size);
    }
}