#include<bits/stdc++.h>
using namespace std;

struct graph
{
	int vertices;
	int edges;
	int **matrix;
};

// initializing graph
struct graph* init(void)
{
	int u, v, w;
	struct graph* G = (struct graph*)calloc(1, sizeof(struct graph));
	
	cout<<"enter number of vertices: ";
	cin>>G->vertices;

	cout<<"enter number of edges: ";
	cin>>G->edges;

	G->matrix = (int**)calloc(G->vertices, sizeof(int*));
	for(int i = 0; i < G->vertices; i++)
		G->matrix[i] = (int*)calloc(G->vertices, sizeof(int));

	for(int u = 0; u < G->vertices; u++)
	{
		for(int v = 0; v < G->vertices; v++)
		{
			if(u != v)
			G->matrix[u][v] = INT_MAX;
		}
	}

	cout<<"enter weight of edge (u, v, w): ";

	for(int i = 0; i < G->edges; i++)
	{
		cin>>u>>v>>w;
		G->matrix[u][v] = w;
	}
	return G;
}

//using floyd warshall
void floyd(struct graph* G)
{
	long long int dis[G->vertices][G->vertices];
	for(int i = 0; i < G->vertices; i++)
	{
		for(int j = 0; j < G->vertices; j++)
			dis[i][j] = G->matrix[i][j];
	}	

	for(int k = 0; k < G->vertices; k++) // pick all vertices as source one by one
	{
		for(int i = 0; i < G->vertices; i++)   // pick all vertices as destination one by one
		{
			for(int j = 0; j < G->vertices; j++)    // pick all vertices as intermediate one by one and check if it makes shortest path
			{
				if(dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}	
	}

// copying again to original matrix
	for(int i = 0; i < G->vertices; i++)
	{
		for(int j = 0; j < G->vertices; j++)
		{
			G->matrix[i][j] = dis[i][j];	 
		}
	}		
}

void print(struct graph* G)
{
	for(int u = 0; u < G->vertices; u++)
	{
		for(int v = 0; v < G->vertices; v++)
		{
			if(G->matrix[u][v] >= INT_MAX)
				cout<<"* ";
			else
				cout<<G->matrix[u][v]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	struct graph* G = init();
		
	cout<<"initial weight: "<<endl;
	print(G);

	cout<<"floyd warshall: "<<endl;
	floyd(G);
	print(G);
	return 0;
}
