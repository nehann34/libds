#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
int top=-1;
char stack[MAX];
char stack1[MAX];
int top1=-1;



void push(char c)
{
	if(top==MAX-1)
	{
		printf("stack is full\n");
		return;
	}
	top++;
	stack[top]=c;
}
char pop()
{
	char item;
	if(top==-1)
	{
		printf("stack is empty\n");
		exit(1);
	}

	item=stack[top];
	top--;
	return item;

}
void rev(char exp[])
{
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(')
		{
			exp[i]=')';
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			exp[i]='(';
			push(exp[i]);
		}
		else
			push(exp[i]);
	}
	for(int i=0;i<strlen(exp);i++)
		exp[i]=pop();
	printf("%s\n",exp );
}
int priority(char c)
{
	if(c=='^')
		return 3;
	if(c=='*' || c== '/')
		return 2;
	if(c=='+' || c== '-')
		return 1;
	else
		return 0;

}

void intopre(char infix[])
{
	char postfix[25],next;
	int c=0,item;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			postfix[c++]=infix[i];
		if(infix[i]=='(')
			push(infix[i]);
		if(infix[i]=='+' || infix[i]=='-' ||infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
		{
			while(top!=-1 && priority(stack[top]) >= priority(infix[i]) )
				postfix[c++]=pop();
			push(infix[i]);

		}
		if(infix[i]==')')
		{
			while(next=pop()!='(')
				postfix[c++]=next;
		}
	}
	while(top != -1)
		postfix[c++]=pop();
	postfix[c]='\0';
	rev(postfix);
	printf("%s\n",postfix);
}

int main()
{
	char infix[25],*revin;
	printf("Enter infix exp\n");
	scanf("%s",infix);
	rev(infix);
	intopre(infix);
	return 0;
}
