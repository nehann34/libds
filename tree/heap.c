#include<stdio.h>
#define MAX 20
int heap[MAX];
int hsize=0;


void disp(int arr[],int hsize)
{
	if(hsize==0)
		printf("heap is empty\n");
	else
	{
		for(int i=1;i<=hsize;i++)
			printf("%d\t",arr[i] );
	}
}
void restoreup(int arr[],int hsize)
	{

		int ele=arr[hsize];
		int par=hsize/2;
		if(par==0)
		{
			arr[hsize]=ele;
			return;
		}
		else
		{
		while(arr[par]< ele)
		{
			arr[hsize]=arr[par];
			hsize=par;
			par=hsize/2;

		}
		arr[hsize]=ele;
	}
	}
void insert(int  arr[],int num,int hsize)
{

	hsize++;
	arr[hsize]=num;
	printf("%d %d %d\n",arr[hsize],num,hsize );
	restoreup(arr,hsize);
}

void restoredown(int arr[],int i,int hsize)
	{
		int l=2*i;
		int r=2*i+1;
		int k=arr[i];
		while(r<=hsize)
		{
			if(k>=arr[l] && k>=arr[r])
				{
					arr[i]=k;
					return;
				}	
			else if(arr[l] > arr[r])
			{
				arr[i]=arr[l];
				i=l;
			}
			else
			{
				arr[i]=arr[r];
				i=r;
			}
			l=2*i;
			r=2*i+1;
		}
		if(l==hsize && arr[l]>k)
		{
			arr[i]=arr[l];
			i=l;
		}
		arr[i]=k;
}

int deleteroot(int arr[],int hsize)
{
	int rootval=arr[1];
	arr[1]=arr[hsize];
	hsize--;
	restoredown(arr,1,hsize);
	return rootval;
}

int main()
{
	int num,rv;
	for(int i=0;i<6;i++)
	{
		printf("Enter element to be inserted\n");
		scanf("%d",&num);
		if(hsize <= MAX)
		{
			printf("%d\n",hsize );
			insert(heap,num,hsize);
			hsize++;
		}

	}
	disp(heap,hsize);
	rv=deleteroot(heap,hsize);
	disp(heap,hsize);
	return 0;
}