#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
void insertBeg(struct node **start,int val)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(NULL==*start)
    {
        temp->prev=NULL;
        temp->next=NULL;
        *start=temp;
    }
    else
    {
        (*start)->prev=temp;
        temp->next=*start;
        temp->prev=NULL;
        *start=temp;
    }
}
void insertEnd(struct node **start,int val)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(NULL==*start)
    {
        temp->prev=NULL;
        temp->next=NULL;
        *start=temp;
    }
    else
    {
        ptr=*start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=NULL;
    }
}
void insertAfter(struct node **start,int val1,int val2)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=*start;
    while(ptr->data!=val1)
        ptr=ptr->next;
    temp->prev=ptr;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    ptr->next=temp;
}
void deleteBeg(struct node **start)
{
    struct node *ptr;
    ptr=*start;
    *start=(*start)->next;
    (*start)->prev=NULL;
    free(ptr);
}
void deleteEnd(struct node **start)
{
    struct node *ptr;
    ptr=*start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->prev->next=NULL;
    free(ptr);
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    struct node *start=NULL;
    insertBeg(&start,1);
    insertBeg(&start,2);
    insertBeg(&start,3);
    insertEnd(&start,1);
    insertEnd(&start,2);
    display(start);
}
