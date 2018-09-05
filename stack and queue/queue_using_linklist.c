#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};
struct list *front=NULL,*rear=NULL;

int isempty()
{
	if(front==NULL)
		return 1;
	return 0;
}

void insert(int num)
{
	struct list *newnode=(struct list *)malloc(sizeof(struct list));
	if(newnode==NULL)
		{
			printf("memory not available\n");
			return;
		}
	newnode->data=num;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
		return;
	}
	rear->next=newnode;
	rear=newnode;
}

int del()
{
	struct list *temp;
	int item;
	if(isempty())
	{
		printf("list is empty\n");
		return 0;
	}
	temp=front;
	item=temp->data;
	front=front->next;
	free(temp);
	return item;

}

int peek()
{
	if(isempty())
	{
		printf("list is empty\n");
		return 0;
	}
	return (front->data);
}

void display()
{
	struct list *temp;
	temp=front;
	if(isempty())
	{
		printf("list is empty\n");
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