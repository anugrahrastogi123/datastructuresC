#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
void push(struct stack **,int);
void pop(struct stack **);
void display(struct stack *);
void main()
{
    int val,option;
    printf("\nWhich action do you want to perform?\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    do
    {
        printf("Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("\nEnter the number to be pushed on stack: ");
                    scanf("%d",&val);
                    push(&top,val);
                    break;
            case 2: pop(&top);
                    break;
            case 3: display(top);
                    break;
        }
    }while(option!=4);
}
void push(struct stack **top,int val)
{
    struct stack *temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=val;
    if(*top==NULL)
    {
        temp->next=NULL;
        *top=temp;
    }
    else
    {
        temp->next=*top;
        *top=temp;
    }
}
void pop(struct stack **top)
{
    struct stack *ptr;
    ptr=*top;
    if(*top==NULL)
        printf("\nStack Underflow.");
    else
    {
        *top=(*top)->next;
        printf("\nThe value being deleted is : %d",ptr->data);
        free(ptr);
    }
}
void display(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
        printf("\nStack is empty.");
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
