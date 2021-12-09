#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
int login(void);
int atm()
{
    // Functions

    void mainMenu();
    void checkBalance(float balance);
    float moneyDeposit(float balance);
    float moneyWithdraw(float balance);
    void menuExit();
    void errorMessage();

    int login(void)
    {
        float number = 1234;
        int pass;
        printf("\n\n\t\t\tEnter the PIN No:");
        scanf("%d", &pass);

        if (pass == number)
        {
            printf("\n\nPIN Matched!\nLOADING");
            for (i = 0; i <= 6; i++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            mainMenu();
        }
        else
        {
            printf("Invalid\n Try Again");
            login();
        }
        return 0;
    }

    // Main Code
    // Local Declarations
    int option;
    float balance = 15000.00;
    int choose;
    bool again = true;

    // insert code here...
    login();
    while (again)
    {

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Your Selection:\t");
        scanf("%d", &option);
        system("CLS");

        switch (option)
        {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;

            case 4:
                menuExit();
                return 0;

            default:
                errorMessage();
                break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
        system("CLS");

        if (choose == 2)
        {
            again = false;
            menuExit();
        }
        else
        {
            mainMenu();
        }
    }

    return 0;

} // main code

// Functions

void mainMenu()
{

    printf("\n\n\t\t==========Welcome to ATM Feature==========\n\n");
    printf("\n\t\t----Please choose one of the options below----\n");
    printf("\n\t\t< 1 >  Check Balance\n");
    printf("\n\t\t< 2 >  Deposit\n");
    printf("\n\t\t< 3 >  Withdraw\n");
    printf("\n\t\t< 4 >  Exit\n\n");

} // Main Menu

void checkBalance(float balance)
{
    printf("You Choose to See your Balance\n");
    printf("****Your Available Balance is:   $%.2f\n\n", balance);

} // Check Balance

float moneyDeposit(float balance)
{
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);

    balance += deposit;

    printf("****Your New Balance is:   $%.2f\n\n", balance);
    return balance;

} // money deposit

float moneyWithdraw(float balance)
{
    float withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);

    while (back)
    {
        printf("Enter your amount to withdraw:\n");
        scanf("%f", &withdraw);

        if (withdraw < balance)
        {
            back = false;
            balance -= withdraw;
            printf("$$$$Your withdrawing money is:  $%.2f\n", withdraw);
            printf("****Your New Balance is:   $%.2f\n\n", balance);
        }

        else
        {

            printf("+++You don't have enough money+++\n");
            printf("Please contact to your Bank Customer Services\n");
            printf("****Your Balance is:   $%.2f\n\n", balance);
        }
    }
    return balance;

} // money withdraw

void menuExit()
{
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
    printf("-----      Brought To by code-projects.org      -----\n");

} // exit menu

void errorMessage()