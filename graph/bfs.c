#include<stdio.h>
#define MAX 20
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX]={0};
int state[MAX];
int queue[MAX];

int front=-1;
int rear=-1;

int isempty()
{
	if(front == -1 || (front==rear+1))
		return 1;
	return 0;
}

int isfull()
{
	if(front ==0 && rear == MAX-1)
		return 1;
	return 0;
}

void insert_queue(int num)
{
	if(isfull())
	{
		printf("queue is full\n");
		return ;
	}
	if(front == -1)
		front=0;
	rear=rear+1;
	queue[rear]=num;
}

int delete_queue()
{
	int item;
	if(isempty())
	{
		printf("queue is empty\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
}

void create_graph()
{
	int e,s,d;
	printf("Enter the number of vertices and edges\n");
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++)
	{
		printf("Enter source and destination vertex of an  edge\n");
		scanf("%d %d",&s,&d);
		adj[s][d]=1;
	}

}

void bfs(int s)
{

	insert_queue(s);
	state[s]=waiting;
	while(!isempty())
	{
		s=delete_queue();
		printf("%d\t",s );
		for(int i=0;i<n;i++)
			{
				if(adj[s][i]==1 && state[i]==initial)
					{
						insert_queue(i);
						state[i]=waiting;

					}
			}
	}
	printf("\n");
}



void bfs_traversal()
{
	int source,v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("Enter source vertex to start with\n");
	scanf("%d",&source);
	bfs(source);
}





int main()
{
	create_graph();
	bfs_traversal();
	return 0;
}