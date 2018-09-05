#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;

int isempty()
{
	if(top==NULL)
		return 1;
	return 0;
}

void push(int num)
{
	struct stack *newnode=(struct stack *)malloc(sizeof(struct stack));
	if(newnode==NULL)
		{
			printf("Stack overflow\n");
			return;
		}
	newnode->data=num;
	newnode->next=top;
	top=newnode;
}

int pop()
{
	struct stack *temp;
	int item;
	if(isempty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	item=top->data;
	temp=top->next;
	free(top);
	top=temp;
	return item;

}

int peek()
{
	if(isempty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	return (top->data);
}

void display()
{
	struct stack *temp;
	temp=top;
	if(isempty())
	{
		printf("stack is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int choice,num;
	
	while(1)
	{
		printf("Enter choice : \n 1 for push\n 2 for pop\n 3 for peek element\n 4 for display \n5 for exit \n\n");
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
				pop();
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