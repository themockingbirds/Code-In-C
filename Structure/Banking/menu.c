void menu(void)
{
    system("clear");
    int choice;
    system("cal");
    printf("\n-BANKING MANAGEMENT SYSTEM-");
    printf("\n\n\n\t\t\t_-_-_-_-_-_-_-_-_-_-_-_WELCOME TO THE MAIN MENU_-_-_-_-_-_-_-_-_-_-_-_");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Remove existing account\n\t\t[6] View customer's list\n\t\t[7] ATM Feature\n\t\t[8] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        atm();
        break;
    case 8:
        close();
        break;
    }
}
