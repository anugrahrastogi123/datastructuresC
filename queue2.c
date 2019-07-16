#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};
struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete1(struct queue *);
struct queue *display(struct queue *);
int main()
{
	int val,option;
	create_queue(q);
	do
	{
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1 : printf("\nEnter the number to insert in the queue: ");
                    scanf("%d",&val);
                    q=insert(q,val);
                    break;
			case 2 : q=delete1(q);
                    break;
			case 3 : q=display(q);
                    break;
		}
	}while(option!=4);
	return 0;
}
void create_queue(struct queue *q)
{
	q->rear=NULL;
	q->front=NULL;
}
struct queue *insert(struct queue *q, int val)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct  node));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}
struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
		printf("\nQueue is empty");
	else
	{
		while(ptr!=q->rear)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
	}
	return q;
}
struct queue *delete1(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
		printf("\nUnderflow");
	else
	{
		q->front =q->front->next;
		printf("\nThe value being deleted is : %d",ptr->data);
		free(ptr);
	}
	return q;
}
