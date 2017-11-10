#include<bits/stdc++.h>
using namespace std;

int *q, *processed, f = -1, r = -1;
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

//.............................. creating queue
void push(int n)
{
	if(f == -1 && r == -1)
	{
		f++, r++;
		q[r] = n;
		return;
	}

	if(f == r && f != -1)
	{
		r++;
		q[r] = n;
		return;
	}
}

int front1()
{
	return q[f];
}

void pop()
{
	if(f == r)
	{
		f = r = -1;
		return;
	}
	f++;
	return;
}

bool empty()
{
	if(f == -1 && r == -1)
		return true;
	else
		return false; 
}

//......................bfs
void bfs(graph* G, int node)
{
	while(!empty())
	{
		int front = front1();   // process the node and then add all neighbour node in queue and then again process untill queue is not empty
		if(processed[front] != 1)
			cout<<"processed: "<<front<<endl;
		processed[front] = 1;
		pop();
		for(int i = 0; i < G->vertices; i++)
		{
			if(G->adj_mat[front][i] == 1 && !processed[i])
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
	int s;
	cout<<"enter starting node: ";
	cin>>s;

	q = (int*)calloc(G->vertices, sizeof(int));
	processed = (int*)calloc(G->vertices, sizeof(int));

	cout<<"bfs: "<<endl;
	push(s);
	bfs(G, s);

	return 0;
}
