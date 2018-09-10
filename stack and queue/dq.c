#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int dq[MAX];
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

void insertrear(int num)
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
	dq[rear]=num;
}
void insertfront(int num)
{
	if(isfull())
	{
		printf("queue is full\n");
		return ;
	}
	if(front==-1)
		{
			front=0;
			rear=0;
		}
	if(front==0)
		front=MAX-1;
	else
		front=front-1;
	dq[front]=num;
}

int delfront()
{
	int item;
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	item=dq[front];
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
int delrear()
{
	int item;
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	item=dq[rear];
	if(front==rear)
		{
			front=-1;
			rear=-1;
		}
	else  if(rear==0)
		rear=MAX-1;
	else
		rear=rear-1;
	return item;
}
int peekfront()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	return dq[front];
}
int peekrear()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	return dq[rear];
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
			printf("%d", dq[i]);
			i++;
		}
	}
	else
	{
		while(i<=MAX-1)
		{
			printf("%d", dq[i]);
			i++;
		}
		i=0;
		while(i<=rear)
		{
			printf("%d", dq[i]);
			i++;
		}

	}
	
}



int main()
{
	int choice,num;
	
	while(1)
	{
		printf("Enter choice : \n 1 for insertion at rear\n 2 for insertion at front \n 3 for deletion at front \n 4 for deletion at rear \n 5 for peek element at front\n 6 for peek element at rear 7 for display \n8 for exit \n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			{
				printf("enter number to be inserted\n");
				scanf("%d",&num);
				insertrear(num);
				break;
			}
			case 2:
			{
				printf("enter number to be inserted\n");
				scanf("%d",&num);
				insertfront(num);
				break;
			}
		case 3 :
			{
				delfront();
				break;
			}
			case 4 :
			{
				delrear();
				break;
			}
		case 5 :
			{
				printf("peek element is : ");
				printf("%d",peekfront());
				break;
			}
				case 6:
			{
				printf("peek element is : ");
				printf("%d",peekrear());
				break;
			}
		case 7:
			{
				printf("list is: ");
				display();
				break;
			}
		case 8:
			exit(1);
		default:
			{
				printf("Enter valid choice\n");
				break;
			}

	}
}
}