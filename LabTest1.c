#include<stdio.h>
#include<stdlib.h>
struct emp
{
    char *emp_name;
    char dept_name;
    float salary;
    struct emp *next;
};
void insertEmp(struct emp **,char*,char,float);
void display(struct emp *start);
void Bsort(struct emp *start)
{
    struct emp *i,*j;
    float temp;
    char *e;
    char d;
    for(i=start;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->salary>j->salary)
            {
                temp=i->salary;
                i->salary=j->salary;
                j->salary=temp;
                e=i->emp_name;
                i->emp_name=j->emp_name;
                j->emp_name=e;
                d=i->dept_name;
                i->dept_name=j->dept_name;
                j->dept_name=d;
            }
        }
    }
}
void main()
{
    struct emp *start=NULL;
    int choice;
    char e_name[30];
    char d_name;
    float sal;
    do
    {
        printf("Enter the name of the employee : ");
        scanf(" %s",&e_name);
        printf("\nEnter the department name(A or B) : ");
        scanf(" %c",&d_name);
        printf("\nEnter the salary : ");
        scanf("%f",&sal);
        insertEmp(&start,e_name,d_name,sal);
        printf("\nDo you want to continue(0 or 1): ");
        scanf("%d",&choice);
        printf("\n");
    }while(choice==1);
    display(start);
    Bsort(start);
    printf("\nSorted list :\n");
    display(start);
}
void insertEmp(struct emp **start,char *e_name,char d_name,float sal)
{
    struct emp *temp=(struct emp *)malloc(sizeof(struct emp));
    struct emp *ptr=*start;
    temp->emp_name=e_name;
    temp->dept_name=d_name;
    temp->salary=sal;
    if(*start==NULL)
    {
        *start=temp;
        temp->next=NULL;
    }
    else
    {
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
        temp->next=NULL;
    }
}
void display(struct emp *start)
{
    int i,j=0;
    struct emp *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\nData of employee %d\n",j);
        printf("EmpName : %s \n",ptr->emp_name);
        printf("DeptName : %c \n",ptr->dept_name);
        printf("Salary : %f \n",ptr->salary);
        j++;
        ptr=ptr->next;
    }
}






























































