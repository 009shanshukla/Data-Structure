#include<bits/stdc++.h>
using namespace std;

struct list_node
{
	int node;
	struct list_node* next;
};

struct graph
{
	int vertices;
	int edges;
	struct list_node* l;
};

// creating adjacency list
struct graph* add_list(void)
{
	int u, v;
	struct graph* G = (struct graph*)calloc(1, sizeof(struct graph));	
	
	cout<<"enter total vertices: ";
	cin>>G->vertices;

	cout<<"enter total edges: ";
	cin>>G->edges; 

	G->l = (struct list_node*)calloc(G->vertices, sizeof(struct list_node));

// initializing adjacency list first node which is pointing to itself to show end
	for(int i = 0; i < G->vertices; i++)
	{	
		G->l[i].node = i;
		G->l[i].next = G->l+i;
	}		 

	cout<<"enter edges(u, v): ";

	for(int i = 0; i < G->edges; i++)
	{
		cin>>u>>v;

		struct list_node* temp = (struct list_node*)malloc(sizeof(struct list_node));
		temp->node = v;
		temp->next = G->l+u;

// adding newly created node to the last node
		struct list_node* t = G->l+u;
		while(t->next != G->l+u)
			t = t->next;
		
		t->next = temp;
	}
	return G;
}

void print(struct graph* G)
{
	cout<<"number of vertices: "<<G->vertices<<endl<<"number of edges: "<<G->edges<<endl;
	
	for(int i = 0; i < G->vertices; i++)
	{
		cout<<"connected nodes from node "<<i<<" are: ";
		struct list_node* temp = G->l[i].next;
		while(temp != G->l+i)
		{
			cout<<temp->node<<" ";
			temp = temp->next;
		} 
		cout<<endl;
	}		
}

int main()
{
	struct graph* G = add_list();
	print(G);
	return 0;
}
