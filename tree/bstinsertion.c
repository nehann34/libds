#include<stdio.h>
#include<stdlib.h>

struct binary
{
	int info;
	struct binary *left,*right;
};

struct binary *delete(struct binary *root,int key)
{
	struct binary *temp,*succ;
	if(root==NULL)
		return NULL;
	if(key>root->info)
		root->right=delete(root->right,key);
	else if(key<root->info)
		root->left = delete(root->left,key);
	else
	{
		
		if(root->left==NULL && root->right==NULL)
		{
		
			temp=root;
			free(temp);
			root=NULL;
			return root;
			
			
		}
		if(root->left==NULL && root->right !=NULL)
		{
			temp=root;
			root=temp->right;
			free(temp);
			return root;
		}
		if(root->left!=NULL && root->right ==NULL)
		{
			temp=root;
			root=temp->left;
			free(temp);
			return root;
		}
		if(root->left!=NULL && root->right !=NULL)
		{
			
			succ=root->right;
			while(succ->left)
				succ=succ->left;
			root->info=succ->info;
			
			root->right=delete(root->right,succ->info);
			return root;
		}

	}
	
}

struct binary *insert(struct binary *root,int num)
{
	struct binary *temp=(struct binary *)malloc(sizeof(struct binary));
	
	if(root==NULL)
	{
		temp->info=num;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		return root;
	}
	if(num>root->info)
	{
		root->right=insert(root->right,num);
		return root;
	}
	if(num<root->info)
	{
		root->left=insert(root->left,num);
		return root;
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
int main()
{
	struct binary *root=NULL;
	int num;
	for(int i=0;i<6;i++)
	{
		printf("Enter the number to be inserted\n");
		scanf("%d",&num);
		root=insert(root,num);
	}
	//preorder(root);
	root=delete(root,13);
	preorder(root);

	return 0;
}
