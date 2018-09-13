#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct binary
{
	char info;
	struct binary *left,*right;
};

struct binary *inpost(char in[],char post[],int n)
{
	struct binary *temp=(struct binary *)malloc(sizeof(struct binary));
	char *p,*q;
	int i;
	q=&post[0];
	p=&in[0];
	//printf("%c %c\t",*q,*p);
	if(n==0)
		return NULL;
	for( i=0;i<n-1;i++)
		q++;
	//printf("%c\n",*q );
	temp->info=*q;
	//printf("%c\n",temp->info );
	temp->left=NULL;
	temp->right=NULL;
	if(n==1)
		return temp;
	for(i=0;*p!=*q;i++)
		p++;
	temp->left=inpost(in,post,i);
	for(int j=1;j<=i;j++)
		post++;
	p++;
	temp->right=inpost(p,post,n-i-1);
	return temp;
}

void inorder(struct binary *root)
{
	struct binary *ptr=root;
	if(ptr==NULL)
		return ;
	inorder(ptr->left);
	printf("%c\n",ptr->info );
	inorder(ptr->right);
	
}
int main()
{
	char in[25],post[25];
	int l;
	struct binary *root=NULL;
	printf("Enter in and post order to create tree\n");
	scanf("%s",in);
	scanf("%s",post);
	l=strlen(in);
	printf("%d\n",l );
	root=inpost(in,post,l);
	inorder(root);


	return 0;
}