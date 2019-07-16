#include<stdio.h>
#define MAX 20
int arr[MAX],top=-1;
void push(int arr[],int val);
int pop(int arr[]);
void display(int arr[]);
void main()
{
    int val,option;
    printf("\nWhich action do you want to perform?\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    do
    {
        //printf("\nWhich action do you want to perform?\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("\nEnter the number to be pushed on stack: ");
                    scanf("%d",&val);
                    push(arr,val);
                    break;
            case 2: val=pop(arr);
                    if(val!=-1)
                        printf("\nThe value deleted from stack is : %d\n",val);
                    break;
            case 3: display(arr);
                    break;
        }
    }while(option!=4);
}
void push(int arr[],int val)
{
    if(top==MAX-1)
    {
        printf("\nStack overflow.\n");
        return;
    }
    else
    {
        top=top+1;
        arr[top]=val;
    }
}
int pop(int arr[])
{
    int item;
    if(top==-1)
    {
        printf("\nStack underflow.\n");
        return -1;
    }
    else
    {
        item=arr[top];
        top=top-1;
        return item;
    }
}
void display(int arr[])
{
    int i;
    if(top==-1)
        printf("\nStack is empty.");
    else
        for(i=top;i>=0;i--)
            printf("%d ",arr[i]);
}
