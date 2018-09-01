#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *start)
{
	struct node * p;
	if(start==NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	p=start;
	printf("List is : ");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

void search(struct node *start, int item)
{
	struct node *p;
	p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->data == item)
		{
			printf("Item %d found at pos %d\n",item,pos);
			return ;
		}
		p=p->next;
		pos++;
	}
	printf("Item not found!!\n");
}

struct node *insertatbeg(struct node *start, int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		newnode->data=val;
		newnode->next=NULL;
		start=newnode;
		return start;
	}
	newnode->data=val;
	newnode->next=start;
	start=newnode;
	return start;
}

struct node *insertatend(struct node *start, int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		newnode->data=val;
		newnode->next=NULL;
		start=newnode;
		return start;
	}
	p=start;
	while(p->next!=NULL)
		p=p->next;

	newnode->data=val;
	p->next=newnode;
	newnode->next=NULL;
	return start;
}

struct node *insertatpos(struct node *start,int pos, int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data= val;
	if(pos == 1)
	{
		newnode->next = start;
		start=newnode;
		return start;
	}
	p=start;
	for(int i=1;i<pos-1 && p!= NULL ;i++)
		p=p->next;
	if(p==NULL)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return start;

}

struct node *insertafter(struct node *start,int pos,int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(pos==1)
	{
		newnode->next=start->next;
		start->next=newnode;
	}
	p=start;
	for(int i=1;i<=pos-1 && p!=NULL ; i++)
		p=p->next;
	if(p==NULL)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return start;

}


struct node *insertbefore(struct node *start,int pos,int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(pos==1)
	{
		newnode->next=start;
		start=newnode;
	}
	p=start;
	for(int i=1;i<pos-1 && p!=NULL ; i++)
		p=p->next;
	if(p==NULL)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return start;

}


struct node *del(struct node *start,int item)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->data==item)
	{
		temp=start;
		start=start->next;
		free(temp);
		return start;
	}
	p=start;
	while(p->next!=NULL)
	{
		if(p->next->data==item)
		{
			temp=p->next;
			p->next=temp->next;
			free(temp);
			return temp;

		}
		p=p->next;
	}
	printf("item not found\n");
	return start;
}


struct node *reverse(struct node *start)
{
	struct node *p=NULL,*q,*current;
	current=start;
	while(current!=NULL)
	{
		q=current->next;
		current ->next = p;
		p=current;
		current=q;
	}
	start=p;
	return start;

}



















int main()
{
	struct node *start=NULL;

	// int choice;
	// printf("Enter what do you want to like to do in a linked list:\n")
	// printf("1 : push\n 2 : Traversal\n 3 : Search\n 4 : Insertion\n 5  : Deletion\n 5 : Reverse\n");
	// scanf("%d",&choice);
	start=insertatend(start,8);
	start=insertatbeg(start,6);
	start=insertatbeg(start,7);
	start=insertatend(start,9);
	start=insertatpos(start,3,4);
	start=insertatpos(start,5,5);
	start=insertatpos(start,9,3);
	start=insertafter(start,2,10);
	start=insertbefore(start,2,11);
	start=reverse(start);

	// push(&start,2);
	// push(&start,1);
	// push(&start,3);
	// push(&start,4);
	// push(&start,5);
	display(start);
	// search(start,6);
	// search(start,2);
	return 0;
}
