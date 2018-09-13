#include<stdio.h>
#include<stdlib.h>

struct binary
{
	int info;
	struct binary *left,*right;
};


struct binary *insert(struct binary *root,int num)
{
	struct binary *ptr,*par;
	struct binary *temp=(struct binary *)malloc(sizeof(struct binary));
	ptr=root;
	if(ptr==NULL)
	{
		temp->info=num;
		temp->left=NULL;
		temp->right=NULL;
		ptr=temp;
		return ptr;
	}
	if(ptr->left==NULL)
	{
		temp->info=num;
		temp->left=NULL;
		temp->right=NULL;
		ptr->left=temp;
		return ptr;
	}
	if(ptr->right==NULL)
	{
		temp->info=num;
		temp->left=NULL;
		temp->right=NULL;
		ptr->right=temp;
		return ptr;
	}
	
	
	if(ptr->left->left ==NULL || ptr->left->right==NULL)
	{
		par=ptr;
		ptr->left=insert(ptr->left,num);
	}
	else
	{
		ptr=par;
		ptr->right=insert(ptr->right,num);
	}

}

void preorder(struct binary *root)
{
	struct binary *ptr=root;
	if(ptr==NULL)
		return ;
	printf("%d\n",ptr->info );
	preorder(ptr->left);
	preorder(ptr->right);
	

}

void inorder(struct binary *root)
{
	struct binary *ptr=root;
	if(ptr==NULL)
		return ;
	inorder(ptr->left);
	printf("%d\n",ptr->info );
	inorder(ptr->right);
	
}

void postorder(struct binary *root)
{
	struct binary *ptr=root;
	if(ptr==NULL)
		return ;
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d\n",ptr->info );	
}


int main()
{
	struct binary *root=NULL;
	int num;
	for(int i=0;i<9;i++)
	{
		printf("Enter the number to be inserted\n");
		scanf("%d",&num);
		root=insert(root,num);
	}
	preorder(root);
	return 0;
}
