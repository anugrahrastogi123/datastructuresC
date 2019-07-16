#include<stdio.h>
#define size 10
int Queue[size],front=-1,rear=-1;
void enqueue(int);
void dequeue();
void display();
void main(){
	int choice,num;
	do{
		printf("Enter your choice\n");
		printf("1 - Insert\n");
		printf("2 - Delete\n");
		printf("3 - Display\n");
		printf("4 - Exit\n");
		scanf("%d",&choice);
		switch(choice){
	case 1:
		printf("Enter the element to be inserted\n");
		scanf("%d",&num);
		enqueue(num);
		break;
	case 2:
		dequeue();
		break;
	case 3:
		display();
		break;
	case 4:
		break;
	default:
		printf("Wrong input\n");
		}
	}while(choice!=4);

}
void enqueue(int x){
	if(front == 0 && rear == size-1){
		printf("Queue is already full\n");
	}
	else{
		if(front==-1){
			front++;
		}
		Queue[++rear] = x;
	}
}
void dequeue(){
	if(front == -1 || front > rear){
		printf("Queue is already empty\n");
	}
	else{
		++front;
	}
}
void display(){
	int temp = front;
	if(front==-1 & front>rear){
		printf("Queue is empty\n");
	}
	else{
		while(front<=rear){
			printf("%d\t",Queue[front++]);
		}
	}
	front = temp;
	printf("\n");
}
