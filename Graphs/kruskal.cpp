#include<bits/stdc++.h>
using namespace std;

int father[100];
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

	for(int i = 0; i < G->vertices; i++)
	{
		for(int j = 0; j < G->vertices; j++)
		{	
			G->adj_mat[i][j] = INT_MAX;
		}
	}

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

//.......... find set

int find(int node)
{
	if(father[node] == node)
		return node;

	return find(father[node]);
}

//...............union set

int unite(int x, int y)
{
	if(x != y)
	{
		father[x] = y;
		return 1;	
	}	
	return 0;
}

//.... kruskal algorithm

void kruskal(graph* G)
{
	int mst_edges = 1;
	int mst_wt = 0;
	int a, b, u, v, minn;
	while(mst_edges < G->vertices)      //mst edges will be 1 less than total vertices
	{
 // getting shortest edge
		minn = INT_MAX;                                  
		for(int i = 0; i < G->vertices; i++)
		{
			for(int j = 0; j < G->vertices; j++)
			{
				if(G->adj_mat[i][j] < minn)
				{
					minn = G->adj_mat[i][j];
					a = u = i;
					b = v = j;
				}
			}
		} 
		cout<<"picked edge: "<<u<<" "<<v;
		u = find(u);
		v = find(v);
 // getting parent for end of the edge
		cout<<" ......parent "<<u<<" "<<v<<endl;

// in case if both have different father that means disjoint set
		if(unite(u, v))
		{
			cout<<mst_edges<<" edges: "<<a<<" "<<b<<" and wt: "<<minn<<endl;
			mst_wt += minn;
			mst_edges++;
		}
		// now removing that edge from matrix
		G->adj_mat[a][b] = G->adj_mat[b][a] = INT_MAX;
	}	
	cout<<"min cost: "<<mst_wt<<endl;
}

int main()
{
	cout<<"enter directed graph: "<<endl;	
	struct graph* G = init(); 	
	print(G);

// initializing disjoint set where father[i] gives father if node i
	for(int i = 0; i < 100; i++)
		father[i] = i;

	kruskal(G);	

	return 0;
}
