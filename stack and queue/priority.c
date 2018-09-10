#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	int priority;
	struct list *next;
};
struct list *front=NULL;

void insert(int num,int pr)
{
	struct list *temp;
	struct list *newnode=(struct list *)malloc(sizeof(struct list));
	if(newnode==NULL)
		{
			printf("memory not available\n");
			return;
		}
	newnode->data=num;
	newnode->priority=pr;
	
	if(front==NULL)
	{
		newnode->next=front;
		front=newnode;
		return;
	}
	if(front->next==NULL)
	{
		if(front->priority <= newnode->priority)
		{
			front->next=newnode;
			newnode->next=NULL;
			return;
		}
		else
		{
			newnode->next=front;
			front=newnode;
			return;

		}
	}

	temp=front;
	while(temp->next!=NULL && newnode->priority >= temp->next->priority )
			temp=temp->next;

	newnode->next=temp->next;
	temp->next=newnode;

	
}

int del()
{
	struct list *temp;
	int item;
	if(front==NULL)
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

void display()
{
	struct list *temp;
	temp=front;
	if(front==NULL)
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
	int choice,num,pr;
	
	while(1)
	{
		printf("Enter choice : \n 1 for insertion\n 2 for deletion\n 3 for display \n4 for exit \n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			{
				printf("enter number & its priority  to be inserted\n");
				scanf("%d %d",&num,&pr);
				insert(num,pr);
				break;
			}
		case 2 :
			{
				del();
				break;
			}
		case 3:
			{
				printf("list is: ");
				display();
				break;
			}
		case 4:
			exit(1);
		default:
			{
				printf("Enter valid choice\n");
				break;
			}

	}
}
}