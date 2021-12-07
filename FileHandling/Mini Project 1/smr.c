#include<stdio.h>
#include<stdlib.h>

void insert_record();
void display_record();
void search_record();
void del_record();
void update_record();
void sort_record();

struct student
{
    int roll;
    char sec[10];
    char name[40];
    int marks;
    float grade;
};
    struct student s;
int main()
{
    int ch;
    system("clear");

    while(ch!=7)
    {
    system("clear");
    printf("\t***********************************************\n");
    printf("\t\tWELCOME TO STUDENT MANAGEMENT PROGRAM\n");
    printf("\t***********************************************\n\n\n");

        printf("\t**** AVAILABLE FUNCTIONALITIES ****\n\n\n");
        printf("\t\t1: Insert student record\n");
        printf("\t\t2: Display student record\n");
        printf("\t\t3: Search student record\n");
        printf("\t\t4: Delete student record\n");
        printf("\t\t5: Update student record\n");
        printf("\t\t6: Sort student record\n");
        printf("\t\t7: Exit\n\n");
        printf("\t\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:system("clear");
                insert_record();
                break;
            case 2:system("clear");
            display_record();
                break;

            case 3:system("clear");
            search_record();
                break;

            case 4:system("clear");
            del_record();
                break;
            case 5:system("clear");
            update_record();
                break;
            case 6:system("clear");
            sort_record();
                break;
            case 7:exit(1);
            default:
                printf("\n\t\tWrong choice Entered");
        }
        printf("\n\t\tPress any key to continue ");
        getchar();
       }
    return 0;
}

void insert_record()
{
    FILE *fp;

    fp=fopen("stu.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\t **** Previous Stored Data ****");
    display_record();

    printf("\n\n\t**** ENTER NEW STUDENT DATA ****\n\n");
    printf("\n\t\tEnter Student Roll Number: ");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("\n\t\tEnter Student Name: ");
    scanf("%[^\n]s",s.name);
    fflush(stdin);
    printf("\n\t\tEnter Student Section: ");
    scanf("%c",&s.sec);
    printf("\n\t\tEnter Student Total marks: ");
    scanf("%d",&s.marks);
    printf("\n\t\tEnter Student Grade: ");
    scanf("%f",&s.grade);
    fwrite(&s,sizeof(s),1,fp);

    {
        printf("\n\n\t !!! Student Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\t\t Updated Record !!\n");
    display_record();

}

void display_record()
{
    FILE *fp;
    fp=fopen("stu.txt","rb");

    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }

    printf("\n\n\t **** Students Details Are As Follows ****\n");
    printf("\nRoll.No\tName of Student\tSection\t\tMarks\t\tGrade\n\n");
    //printf("a.students roll number\t b.student name\t c.student section\t d.student marks\t e.student grade");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%d\t%s\t%s  \t\t%d\t\t%.2f\n",s.roll,s.name,s.sec,s.marks,s.grade);
    }
    fclose(fp);
}

void search_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Student Roll Number Which You Want To Search: ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\n\n\tSearch Sucessfull And Student Records Is as Follows: \n\n");
        printf("\nRoll.No\tName of Student\tSection\t\tMarks\t\tGrade\n\n");
        printf("%d\t%s\t%s  \t\t%d\t\t%.2f\n",s.roll,s.name,s.sec,s.marks,s.grade);
        }
    }
    if(flag==0)
    {
    printf("\n\n\t\tNo Such Record Found !!!!!\n");
    }
fclose(fp);
}

void del_record()
{
    int ro,flag=0;
    FILE *fp,*ft;
    fp=fopen("stu.txt","rb");
    ft=fopen("stu1.txt","ab+");
    if(fp==NULL)
    {
         printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\t **** Previous Stored Data ****");
    display_record();
    printf("\n\n\tEnter Student Roll Number Which You Want to Delete ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\n\t\tRecord Deleted Sucessfully \n");

        }
        else
        {
        fwrite(&s,sizeof(s),1,ft);
        }
    }
    if(flag==0)
    {
    printf("\n\n\t\tNo Such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("stu.txt");
    rename("stu1.txt","stu.txt");
    printf("\n\t\t Updated Record !!\n");
    display_record();
}

void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Roll Number of Student Whose Record You Want To Update: ");
    scanf("%d",&ro);
    printf("\n\t\t*** Previously Stored Record Of Given Roll Number ***");

    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\nRoll.No\tName of Student\tSection\t\tMarks\t\tGrade\n\n");
        printf("%d\t%s\t%s  \t\t%d\t\t%.2f\n",s.roll,s.name,s.sec,s.marks,s.grade);
        printf("\n\t\t*** Now Enter the New Record ***\n\n");

        printf("\n\t\tUpdated Student Roll Number: ");
        scanf("%d",&s.roll);
        fflush(stdin);
        printf("\n\t\tUpdated Student Name: ");
        scanf("%[^\n]s",s.name);
        printf("\n\t\tUpdated Student Section: ");
        scanf("%s",&s.sec);
        printf("\n\t\tUpdated Student Marks: ");
        scanf("%d",&s.marks);
        printf("\n\t\tUpdated Student Grade: ");
        scanf("%f",&s.grade);
        fseek(fp,-(long)sizeof(s),1);
        fwrite(&s,sizeof(s),1,fp);
        printf("\n\n\t\tRecord Updated Successfully Check The Display Section!!\n\t\t");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError : Something went wrong!!!");
    }
fclose(fp);
}
void sort_record()
{
    struct student temp;
    struct student arr[50];

    int i,j,k=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open File !!!\n");
    }
    i=0;

    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
         i++;k++;
    }

    for(i=0;i<k;i++)
        {
        for(j=0;j<k-i-1;j++)
         {
            if(arr[j].roll>arr[j+1].roll)
             {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
             }
          }
        }
        printf("\n\t\tAfter Sorting Student Details !!\n\n");
        for(i=0;i<k;i++)
        {
           printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",arr[i].roll,arr[i].name,arr[i].sec,
           arr[i].marks,arr[i].grade);
        }
    fclose(fp);
}