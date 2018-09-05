#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int top=-1;
int s[MAX];

int isempty()
{
	if(top==-1)
		return 1;
	return 0;
}

int isfull()
{
	if(top==MAX-1)
		return 1;
	return 0;
}

void push(int num)
{
	
	if(isfull())
		{
			printf("Stack is full\n");
			return;
		}
	top=top+1;
	s[top]=num;
}

int pop()
{
	int item;
	if(isempty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	item=s[top--];
	return item;
}

int peek()
{
	int item;
	if(isempty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	item=s[top];
	return item;
}

void display()
{
	int i;
	if(isempty())
	{
		printf("stack is empty\n");
		return;
	}
	for(i=top;i>=0;i--)
		printf("%d\t",s[i] );
	printf("\n");
}

int main()
{
	int choice,num;
	
	while(1)
	{
		printf("Enter choice : \n 1 for push\n 2 for pop\n 3 for peek element\n 4 for display 5 for exit \n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			{
				printf("enter number to be pushed\n");
				scanf("%d",&num);
				push(num);
				break;
			}
		case 2 :
			{
				printf("popped element is:");
				printf("%d",pop());
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
				printf("stack is: ");
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