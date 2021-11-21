/* 
	5. Create a structure to specify the data of customers in bank. The data to be stored is: Account Number, Name, Balance in account. Assume maximum of 200 customers in the bank.
    
    a. Write a function to print the account number and name of each customer with balance below Rs. 100.
    
    b. if a customer request for withdrawal or deposit, the form contains the following filed:
    Acct. No., amount, code,(1. For deposit, 0 for Withdrawal)

    Write a program to give a message, "The balance is insufficient for the specific withdrawal", if the withdrawal the balance falls below Rs. 100.
 */

#include<stdio.h>
#include<string.h>
#include"cls.h"

const int size=2;
struct bank{
    int acc_no;
    char name[30];
    float blnc;
    int code;
}customer[size];

void find(struct bank [],int);
void menu();
void operation (struct bank[],int);
int main(){
    int code=254;
    //input data
    for(int i=0;i<size;i++){
        printf("Name: ");
        scanf("%[^\n]s",&customer[i].name);
        printf("Account No: ");
        scanf("%d",&customer[i].acc_no);
        printf("Balance: ");
        scanf("%f",&customer[i].blnc);
        getchar();
        code+=2;
        customer[i].code=code;
        printf("\n");
    }

    printf("Record Submitted Successfully..");
    getchar();
    cls();
    //print all record on the console...
    for(int i=0;i<size;i++){
        printf("Name: %s\t",customer[i].name);
     
        printf("Account No: %d\t",customer[i].acc_no);
     
        printf("Balance: %.2f\t",customer[i].blnc);
        printf("Code: %d",customer[i].code);
        printf("\n\n");
    }

    menu();
    //function to find records of those customers whose acc blnc is below 100
    //find(customer,size);
    //function to perform deposit and withdrawal operation
    //operation(customer, size);

    return 0;
}
void menu(){
    int ch;
    printf("==============================Menu=============================\n\n");
    printf("\t\t-1. Search \n");
    printf("\t\t-2. Deposit & Withdrawal\n");
    printf("Input:");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        find(customer,size);
        break;
    case 2:
        operation(customer,size);
        break;
    
    default:
        cls();
        printf("Invalid Input,plase input again:\n\n");
        menu();
        break;
    }
}

void find(struct bank customer[],int size){
    int count =0;   
    for(int i=0;i<size;i++){
        if (customer[i].blnc < 100)
        {   
            printf("Records Found..\n\n");

            printf("Name: %s\t", customer[i].name);

            printf("Account No: %d\t", customer[i].acc_no);

            printf("Balance: %.2f\t", customer[i].blnc);

            printf("\n");
        }
    }
    menu();
}

void operation(struct bank customer[],int size){
    printf("\t\t-1. Deposit\n");
    printf("\t\t-2: Witdrawal\n");
    int ch,acc_no,pin,temp;
    printf("INPUT: ");
    scanf("%d",&ch);

    printf("\n\tEnter ACCOUNT NO: ");
    scanf("%d",&acc_no);
    printf("\n\tEnter 4 digit Pin: ");
    scanf("%d",&pin);
    for(int i=0;i<size;i++){

        if (customer[i].acc_no==acc_no && customer[i].code==pin){
            switch (ch)
            {
                case 1:
                    printf("Enter Deposit Ammount: ");
                    scanf("%d",&temp);
                    customer[i].blnc+=temp;
                    printf("Current Balance:%f\n",customer[i].blnc);
                    menu();
                    break;
                case 2:
                    if(customer[i].blnc>100){
                        printf("Enter Withdrawal Ammount: ");
                        scanf("%d", &temp);
                        customer[i].blnc -= temp;
                        printf("Current Balance:%f\n", customer[i].blnc);
                    }else{
                        printf("Insufficient Balnace");
                        getchar();
                        cls();
                        operation(customer,size);
                    }
                    
                    break;
                default:
                    printf("Invalid");
                    operation(customer, size);
                }
        }
            
    }
}

