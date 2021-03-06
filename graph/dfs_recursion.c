#include<stdio.h>
#define MAX 20
#define initial 1
#define visited 2
int n;
int adj[MAX][MAX]={0};
int state[MAX];


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

void dfs(int s)
{
		printf("%d\t",s);
		state[s]=visited;
		for(int i=0;i<n;i++)
		{
			if(adj[s][i]==1 && state[i]==initial)
				dfs(i);
		}

		printf("\n");

}
void dfs_traversal()
{
	int source,v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("Enter source vertex to start with\n");
	scanf("%d",&source);
	dfs(source);
}

int main()
{
	create_graph();
	dfs_traversal();
	return 0;
}