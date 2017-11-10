#include<bits/stdc++.h>
using namespace std;

int *s, *processed, front = -1;
struct graph
{	
	int edges;
	int vertices;
	int** adj_mat;
};

// initializing graph (refer to matrix representation)
graph* init()
{
	int u, v;
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
			if(i == j)
				G->adj_mat[i][j] = 1;
		}
	}

	cout<<"enter edges(u, v): ";
	for(int i = 0; i < G->edges; i ++)
	{
		cin>>u>>v;
		G->adj_mat[u][v] = 1;
		//G->adj_mat[v][u] = 1;
	}
	return G;

}

//.............creating stack

void pop()
{
	front--;
}

int first()
{
	return s[front];
}

bool isempty()
{
	if(front == -1)
		return true;
	else
		return false;
}

void push(int n)
{
	s[++front] = n;
}

//...........dfs

void dfs(graph* G, int node)
{
	while(!isempty())
	{
		int front = first();   // process node and then push all its neighbour into stack
		if(!processed[front])
			cout<<"processed: "<<front<<endl;
		pop();
		processed[front] = 1;
		
		for(int i = 0; i < G->vertices; i++)
		{
			if(!processed[i] && G->adj_mat[front][i] == 1)
				push(i);
		}		
	}
}

void print(graph* G)
{
	cout<<"enter adjacency matrix: "<<endl;
	for(int i = 0; i < G->vertices; i++)
	{
		for(int j = 0; j < G->vertices; j++)
			cout<<G->adj_mat[i][j]<<" ";

		cout<<endl;
	}
}

int main()
{
	cout<<"enter directed graph: "<<endl;	
	struct graph* G = init(); 	
	print(G);	
	int st;
	cout<<"enter starting node: ";
	cin>>st;

	s = (int*)calloc(G->vertices, sizeof(int));
	processed = (int*)calloc(G->vertices, sizeof(int));

	cout<<"dfs: "<<endl;
	push(st);
	dfs(G, st);

	return 0;
}





















