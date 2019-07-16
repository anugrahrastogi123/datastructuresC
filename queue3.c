#include <stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert();
int delete();
void display();
void main()
{
	int val,option;
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
			case 1 : insert();
				break;
			case 2 : val=delete();
				if(val!=-1)
					printf("\nThe number deleted is : %d",val);
				break;
			case 3 :display();
				break;
		}
	}while(option!=4);
}

void insert()
{
	int num;
	printf("\nEnter the number to be inserted in the queue :  ");
	scanf("%d",&num);
	if(front==0&&rear==MAX-1)
		printf("\nOverflow");
	else if(front ==-1&&rear==-1)
	{
		front=rear=0;
		queue[rear]=num;
	}
	else if(rear ==MAX-1&&front!=0)
	{
		rear=0;
		queue[rear]=num;
	}
	else
	{
		rear++;
		queue[rear]=num;
	}
}
int delete()
{
	int val;
	if(front==-1&&rear==-1)
	{
		printf("\nUnderflow");
		return -1;
	}
	val=queue[front];
	if(rear==front)
		front=rear=-1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
	return val;
}

void display()
{
	int i;
	if(front==-1&&rear==-1)
		printf("\nQueue is empty");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
				printf("\t%d",queue[i]);
		}
		else
		{
			for(i=front;i<MAX;i++)
				printf("\t%d",queue[i]);

			for(i=0;i<rear;i++)
				printf("\t%d",queue[i]);

		}
	}
}
