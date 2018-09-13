#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct binary
{
	char info;
	struct binary *left,*right;
};

struct binary *inpre(char in[],char pre[],int n)
{
	struct binary *temp=(struct binary *)malloc(sizeof(struct binary));
	char *p;
	int i;
	p=&in[0];
	if(n==0)
		return NULL;
	temp->info=*pre;
	temp->left=NULL;
	temp->right=NULL;
	if(n==1)
		return temp;
	for(i=0;*p!=*pre;i++)
		p++;
	pre++;
	temp->left=inpre(in,pre,i);
	for(int j=1;j<=i;j++)
		pre++;
	p++;
	temp->right=inpre(p,pre,n-i-1);
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
int height(struct binary *root)
{
	struct binary *ptr=root;
	int lh,rh;
	if(root==NULL)
		return 0;
	lh=height(ptr->left);
	rh=height(ptr->right);
	if(lh > rh)
		return lh+1;
	else
		return rh+1;

}
int main()
{
	char in[25],pre[25];
	int l;
	struct binary *root=NULL;
	printf("Enter in and pre order to create tree\n");
	scanf("%s",in);
	scanf("%s",pre);
	l=strlen(in);
	printf("%d\n",l );
	root=inpre(in,pre,l);
	inorder(root);
	printf("height of the tree is %d\n",height(root));


	return 0;
}