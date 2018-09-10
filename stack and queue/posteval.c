#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
int top=-1;
int  stack[MAX];

int power(int a,int b)
{
	int p=1;
	for(int i=0;i<b;i++)
		p=p*a;
	return a;
}
void push(int c)
{
	if(top==MAX-1)
	{
		printf("stack is full\n");
		return;
	}
	top++;
	stack[top]=c;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("stack is empty\n");
		exit(1);
	}

	item=stack[top];
	top--;
	return item;

}

int main()
{
	char post[25];
	int n1,n2,result,temp;
	scanf("%s",post);
	for(int i=0;i<strlen(post);i++)
	{
		if(post[i] >='0' && post[i] <='9')
			push(post[i] - '0');
		else
		{
			n1=pop();
			n2=pop();
			switch(post[i])
			{
				case '+':
					{
						temp=(n1+n2);
						break;
					} 
				case '-':
					{
						temp=(n2-n1);
						break;
					} 
				case '*':
					{
						temp=(n1*n2);
						break;
					} 
				case '/':
					{
						temp=(n2/n1);
						break;
					} 
				case '^':
					{
						temp=power(n2,n1);
						
					} 
				push(temp);
			}

		}
	}
	result=pop();
	printf("%d\n",result );
	return 0;
}