#include<stdio.h>
#define MAX 20
#define infinite 9999
#define NIL -1
#define temporary 1
#define permanent 2

int n;
int adj[MAX][MAX]={0};
int pathlength[MAX]={infinite};
int pred[MAX]={NIL};
int state[MAX]={temporary};

void create_graph()
{
	int e,s,d,w;
	printf("Enter the number of vertices and edges \n");
	scanf("%d %d",&n,&e);
	printf("Enter source and destination vertex of an  edge & edge weight\n");
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&s,&d,&w);
		adj[s][d]=w;
	}

}


int find_min()
{
	int  min=infinite;
	int v=NIL;
	for(int i=0;i<n;i++)
	{
		if(pathlength[i] < min && state[i]==temporary)
			{
				min=pathlength[i];
				v=i;
			}
	}
	return v;
}
void dijkstra(int s)
{
	int current;
	pathlength[s]=0;
	while(1)
	{
		current=find_min();
		state[current]=permanent;
		for(int i=0;i<n;i++)
		{
			if(current==NIL)
				return;
			state[current]=permanent;
			if(adj[current][i]!=0 && state[i]==temporary)
			{
				if(pathlength[current]+adj[current][i] < pathlength[i])
				{
					pred[i]=current;
					pathlength[i]=pathlength[current]+adj[current][i];
				}

			}
		}
	}
}

void findpath(int s,int d)
{
	int pre;
	pre=pred[d];
	if(pre==NIL)
		return;
	findpath(s,pre);
	printf("%d\n",pre);
}

int main()
{
	int source,dest;
	create_graph();
	printf("Enter source vertex to start with\n");
	scanf("%d",&source);
	dijkstra(source);
	printf("enter dest vertex to find the shortest path\n");
	scanf("%d",&dest);
	findpath(source,dest);
	return 0;
}