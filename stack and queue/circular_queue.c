#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int l[MAX];
int front=-1;
int rear=-1;

int isempty()
{
	if(front == -1 && rear==-1)
		return 1;
	return 0;
}

int isfull()
{
	if((front ==0 && rear == MAX-1) || (front==rear+1))
		return 1;
	return 0;
}

void insert(int num)
{
	if(isfull())
	{
		printf("queue is full\n");
		return ;
	}
	if(front == -1)
		front=0;
	if(rear==MAX-1)
		rear=0;
	else
		rear=rear+1;
	l[rear]=num;
}

int del()
{
	int item;
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	item=l[front];
	if(front==rear)
		{
			front=-1;
			rear=-1;
		}
	else  if(front==MAX-1)
		front=0;
	else
		front=front+1;
	return item;
}

int peek()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	return l[front];
}

void display()
{
	int i=front;

	if(isempty())
	{
		printf("queue is empty\n");
		return ;
	}
	if(front<=rear)
	{
		while(i<=rear)
		{
			printf("%d", l[i]);
			i++;
		}
	}
	else
	{
		while(i<=MAX-1)
		{
			printf("%d", l[i]);
			i++;
		}
		i=0;
		while(i<=rear)
		{
			printf("%d", l[i]);
			i++;
		}

	}
	
}



int main()
{
	int choice,num;
	
	while(1)
	{
		printf("Enter choice : \n 1 for insertion\n 2 for deletion\n 3 for peek element\n 4 for display \n5 for exit \n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			{
				printf("enter number to be inserted\n");
				scanf("%d",&num);
				insert(num);
				break;
			}
		case 2 :
			{
				del();
				break;
			}
		case 3 :
			{
				printf("peek element is : ");
				printf("%d",peek());
				break;
			}
		case 4:
			{
				printf("list is: ");
				display();
				break;
			}
		case 5:
			exit(1);
		default:
			{
				printf("Enter valid choice\n");
				break;
			}

	}
}
}