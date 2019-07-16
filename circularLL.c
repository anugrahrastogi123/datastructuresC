#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertBeg(struct node **start,int val)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(NULL==*start)
    {
        temp->next=temp;
        *start=temp;
    }
    else
    {
        ptr=*start;
        while(ptr->next!=*start)
            ptr=ptr->next;
        ptr->next=temp;
        temp->next=*start;
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
        temp->next=temp;
        *start=temp;
    }
    else
    {
        ptr=*start;
        while(ptr->next!=*start)
            ptr=ptr->next;
        ptr->next=temp;
        temp->next=*start;
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
    while(ptr->next!=*start)
    {
        if(ptr->data==val1)
        {
            temp->next=ptr->next;
            ptr->next=temp;
            return;
        }
        ptr=ptr->next;
    }
    if(ptr->next==*start&&ptr->data==val1)
    {
        ptr->next=temp;
        temp->next=*start;
    }
}
void deleteBeg(struct node **start)
{
    struct node *ptr;
    ptr=*start;
    while(ptr->next!=*start)
        ptr=ptr->next;
    ptr->next=(*start)->next;
    free(*start);
    *start=ptr->next;
}
void deleteEnd(struct node **start)
{
    struct node *ptr,*preptr;
    ptr=*start;
    while(ptr->next!=*start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
}
void delete(struct node *start,int key)
{
    if (start == NULL)
        return;

    // Find the required node
    struct node *ptr = start, *prev;
    while (ptr->data != key)
    {
        if (ptr->next ==start)
        {
            printf("\nGiven node is not found in the list!!!");
            break;
        }

        prev = ptr;
        ptr = ptr -> next;
    }

    // Check if node is only node
    if (ptr->next == start)
    {
        start = NULL;
        free(ptr);
        return;
    }

    // If more than one node, check if
    // it is first node
    if (ptr == start)
    {
        prev = start;
        while (prev -> next != start)
            prev = prev -> next;
        start = ptr->next;
        prev->next = start;
        free(ptr);
    }

    // check if node is last node
    else if (ptr -> next == start)
    {
        prev->next = start;
        free(ptr);
    }
    else
    {
        prev->next = ptr->next;
        free(ptr);
    }
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}
void main()
{
    struct node *start=NULL;
    insertBeg(&start,1);
    insertBeg(&start,2);
    insertBeg(&start,3);
    insertEnd(&start,1);
    insertEnd(&start,2);
    insertEnd(&start,4);
    //deleteBeg(&start);
    //deleteEnd(&start);
    insertAfter(&start,4,0);
    delete(start,1);
    display(start);
}
