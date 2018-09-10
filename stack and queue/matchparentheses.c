#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 20

char stack[MAX];
int top=-1;

void push (char item)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		return;
	}
	
	top=top+1;
	stack[top]=item;

}

char pop()
{
	int item;
	if(top==-1)
	{
		printf("stack underflow\n");
		return '0';
	}
	item=stack[top];
	top--;
	return item;

}
int match(char a,char b)
{
	printf("%c %c\n",a,b );
	if(a=='(' && b==')')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;	
	return 0;
}
int check(char exp[])
{
	char c;
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(exp[i]);
			printf("%d\n",top );
		}
		if(isalnum(exp[i]))
			continue;
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{
			if(top==-1)
				return 0;
			else
			{
				c=pop();
				if(match(c,exp[i]) == 0)
				{
					printf("parentheses doesn't match\n");
					return 0;
				}
			}

		}
	}
	if(top==-1)
	{
		printf("Balanced parentheses\n");
		return 1;
	}
	else
	{
		printf("Left are more than right\n");
		return 0;
	}

}

int main()
{
	int valid;
	char exp[25];
	printf("Enter expression\n");
	scanf("%s",exp);
	valid=check(exp);
	if(valid==1)
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
	return 0;
}