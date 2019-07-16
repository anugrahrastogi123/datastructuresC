#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertBeg(struct node **start,int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(NULL==temp)
    {
        printf("Cannot create a new node, overflow has occured. ");
        return;
    }
    temp->data=val;
    temp->next=*start;
    *start=temp;
}
void insertEnd(struct node **start,int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *ptr=*start;
    temp->data=val;
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
void insertAfter(struct node **start,int val1,int val2)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=*start;
    temp->data=val2;
    if(*start==NULL)
    {
        printf("The list is empty, so %d cannot be inserted.\n",val2);
        return;
    }
    while(ptr->next!=NULL)
    {
        if(ptr->data==val1)
        {
            temp->next=ptr->next;
            ptr->next=temp;
            return;
        }
        ptr=ptr->next;
    }
    if(ptr->next==NULL&&ptr->data==val1)
    {
        ptr->next=temp;
        temp->next=NULL;
    }
}
int deleteBeg(struct node **start)
{
    if(start==NULL)
    {
        printf("Underflow\n");
        return;
    }
    int p;
    p=(*start)->data;
    struct node *temp=*start;
    *start=(*start)->next;
    free(temp);
    return p;
}
void deleteEnd(struct node **start)
{
    struct node *ptr,*preptr;
    if((*start)->next==NULL)
    {
        ptr=*start;
        start=NULL;
    }
    else
    {
        preptr=NULL;
        ptr=*start;
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
    }
    free(ptr);
}
void delete(struct node **start,int key)
{
    struct node *ptr,*preptr;
    ptr=*start;
    preptr=NULL;
    while(ptr!=NULL&&ptr->data!=key)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)return;
    preptr->next=ptr->next;
    free(ptr);
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    struct node *start=NULL;
    insertAfter(&start,4,8);
    insertEnd(&start,5);
    insertBeg(&start,1);
    insertBeg(&start,2);
    insertBeg(&start,3);
    insertBeg(&start,4);
    insertEnd(&start,0);
    insertAfter(&start,2,9);
    insertAfter(&start,0,10);
    int p=deleteBeg(&start);
    deleteEnd(&start);
    delete(&start,2);
    display(start);
    printf("\n%d",p);
}
