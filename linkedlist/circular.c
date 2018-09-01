#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *last)
{
	struct node * p;
	if(last==NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	p=last->next;
	printf("List is : ");
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	while(p!=last->next);	
}



void search(struct node *last, int item)
{
	struct node *p;
	p=last->next;
	int pos=1;
	do
	{
		if(p->data == item)
		{
			printf("Item %d found at pos %d\n",item,pos);
			return ;
		}
		p=p->next;
		pos++;
	}while(p!=last->next);
	if(p==last->next)
		printf("Item not found!!\n");
}


struct node *insertatbeg(struct node *last, int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(last==NULL)
	{
		newnode->data=val;
		last=newnode;
		last->next=last;
		return last;
	}
	newnode->data=val;
	p=last->next;
	newnode->next=p;
	last->next=newnode;
	return last;
}

struct node *insertatend(struct node *last, int val)
{
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(last==NULL)
	{
		newnode->data=val;
		last=newnode;
		last->next=last;
		return last;
	}
	newnode->data=val;
	newnode->next=last->next;
	last->next=newnode;
	last=newnode;
	return last;
}

struct node *insertatpos(struct node *last,int pos, int val)
{
	int i=1;
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data= val;
	if(pos == 1)
	{
		newnode->next = last->next;
		last->next=newnode;
		return last;
	}
	p=last->next;
	do{
		p=p->next;
		i++;
	}while(p!=last->next && i<pos-1 );

	if(p==last->next)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return last;

}

struct node *insertafter(struct node *last,int pos,int val)
{
	int i=1;
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	p=last->next;
	if(pos==1)
	{
		newnode->next=p->next;
		p->next=newnode;
		return last;
	}
	do{
		p=p->next;
		i++;
	}while(p!=last->next && i<pos-1 );

	if(p==last->next)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return last;

}


struct node *insertbefore(struct node *last,int pos,int val)
{
	int i=0;
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(pos==1)
	{
		newnode->next=last->next;
		last->next=newnode;
		return last;
	}
	p=last;
	do
	{
		p=p->next;
		i++;
	}while(p!=last && i < pos-1);

	if(p==last)
		printf("Not enough nodes\n");
	else
	{
		newnode->next=p->next;
		p->next=newnode;
	}
	return last;
}


struct node *del(struct node *last,int item)
{
	struct node *temp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	if(last->next->data==item)
	{
		temp=last->next;
		last->next=temp->next;
		free(temp);
		return last;
	}
	p=last->next;
	while(p->next!=last->next)
	{
		if(p->next->data==item)
		{
			temp=p->next;
			p->next=temp->next;
			free(temp);
			return last;

		}
		p=p->next;
	}
	printf("item not found\n");
	return last;
}


struct node *reverse(struct node *last)
{
	struct node *p=last,*q,*current,*orig_head=last->next;
	current=orig_head;
	do
	{
		q=current->next;
		current ->next = p;
		p=current;

		current=q;
	}while(current!=orig_head);
	last=current;
	return last;
}



int main()
{
	struct node *last=NULL;

	// int choice;
	// printf("Enter what do you want to like to do in a linked list:\n")
	// printf("1 : push\n 2 : Traversal\n 3 : Search\n 4 : Insertion\n 5  : Deletion\n 5 : Reverse\n");
	// scanf("%d",&choice);
	last=insertatend(last,8);
	last=insertatbeg(last,6);
	last=insertatbeg(last,7);
	// last=insertatend(last,9);
	// display(last);
	last=insertatpos(last,3,4);
	
	// last=insertatpos(last,5,5);
	// last=insertatpos(last,9,3);
	last=insertafter(last,2,10);
	last=insertbefore(last,2,11);
	
	
	//last=reverse(last);
	
	
	// display(last);
	search(last,6);
	search(last,15);
	del(last,6);
	last=insertatend(last,6);
	last=reverse(last);
	display(last);

	// search(last,2);
	return 0;
}
