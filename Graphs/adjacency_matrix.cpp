#include<bits/stdc++.h>
using namespace std;

struct graph
{
	int vertices;
	int edges;
	int **matrix;
};

struct graph* enter_matrix(void)
{
	int u, v;
	struct graph* G = (struct graph*)calloc(1, sizeof(struct graph));

	cout<<"enter number of vertices: ";
	cin>>G->vertices;

	cout<<"enter number of edges: ";
	cin>>G->edges;	

	G->matrix = (int** )calloc((G->vertices),sizeof(int*));

	for(int u = 0; u < G->vertices; u++)
	{
		G->matrix[u] = (int*)calloc((G->vertices), sizeof(int));
	}

	cout<<"enter edges (u, v): ";
	for(int i = 0; i < G->edges; i++)
	{
		cin>>u>>v;
		G->matrix[u][v] = 1;
		G->matrix[v][u] = 1;
	}

	return G;
}

void print(struct graph* G)
{
	cout<<"for direct graph: "<<endl;
	cout<<"total edges: "<<G->edges<<endl<<"total vertices: "<<G->vertices<<endl;
	for(int i = 0; i < G->vertices; i++)
	{
		cout<<"connected edges from strating "<<i<<" are: ";
		{
			for(int j = 0; j < G->vertices; j++)
			{
				if(G->matrix[i][j] == 1)
				{
					cout<<j<<" ";
				}
			}
		}
		cout<<endl;
	}
}

int main()
{
	struct graph *G = enter_matrix();
	print(G);

	return 0;
}
