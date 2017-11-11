#include<bits/stdc++.h>
using namespace std;

int *parent, *key, *mst_node;

struct graph
{	
	int edges;
	int vertices;
	int** adj_mat;
};

// initializing graph (refer to matrix representation)
graph* init()
{
	int u, v, w;
	graph* G = (graph* )calloc(1, sizeof(graph));
	cout<<"enter total vertices: ";
	cin>>G->vertices;
	
	cout<<"total edges: ";
	cin>>G->edges;

	G->adj_mat = (int**)calloc(G->vertices, sizeof(int*));
	for(int i = 0; i < G->vertices; i++)
		G->adj_mat[i] = (int*)calloc(G->vertices, sizeof(int));

	cout<<"enter edges with weight(u, v, w): ";
	for(int i = 0; i < G->edges; i ++)
	{
		cin>>u>>v>>w;
		G->adj_mat[u][v] = w;
		G->adj_mat[v][u] = w;
	}
	return G;

}

// ............printing weight

void print(graph* G)
{
	cout<<"enter adjacency matrix: "<<endl;
	for(int i = 0; i < G->vertices; i++)
	{
		for(int j = 0; j < G->vertices; j++)
{
			if(G->adj_mat[i][j] == INT_MAX)
				cout<<"* ";
			else
				cout<<G->adj_mat[i][j]<<" ";
}
		cout<<endl;
	}
}

//.............prims algo

int minkey(graph* G)
{
	int minn = INT_MAX, x;
// finding the node that is not included in mst and has min key value
	for(int i = 0; i < G->vertices; i++)
	{
		if(minn > key[i] && (mst_node[i] == 0))
		{
			minn = key[i];
			x = i;
		}
	}
	return x;
}

void print_prims(graph* G)
{
	cout<<"edges  weight"<<endl;
	for(int i = 1; i < G->vertices; i++)
	{
		cout<<i<<"-"<<parent[i]<<" "<<G->adj_mat[i][parent[i]]<<endl;
	}
}

void prims(graph* G)
{
// initializing visited array
	int mst_edges = 1;
	parent = (int*)calloc(G->vertices, sizeof(int));
	key = (int*)calloc(G->vertices, sizeof(int));
	mst_node = (int*)calloc(G->vertices, sizeof(int));

	for(int i = 0; i < G->vertices; i++)
		key[i] = INT_MAX;

	// first node	
	key[0] = 0;	
	parent[0] = -1;

	while(mst_edges < G->vertices)
	{
		int u = minkey(G);
		mst_node[u] = 1;     // including node in mst

// updating key value of each node that is not included in mst 
		for(int v = 0; v < G->vertices; v++)
		{
			if(key[v] > G->adj_mat[u][v] && G->adj_mat[u][v])
			{
				key[v] = G->adj_mat[u][v];
				parent[v] = u;
			}
		}
		mst_edges++;
	}	
	print_prims(G);
}

int main()
{
	cout<<"enter directed graph: "<<endl;	
	struct graph* G = init(); 	
	print(G);

	prims(G);	

	return 0;
}

















