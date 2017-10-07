#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	int left;
	int right;
}*tree;


int temp[1000];
int k = 0;

void insert(int c, int p, char id)
{
	if(id == 'l')
		tree[p].left = c;

	else
		tree[p].right = c;
}

void inorder(int root)
{
	if(root == 0)
		return ;
	
	inorder(tree[root].left);
	temp[k++] = root;
	inorder(tree[root].right);

}

bool CheckBst(int root)
{
	inorder(root);
	int min = INT_MAX;

	for(int i = 1; i<k; i++)
	{
		if(temp[i] < temp[i-1])
			return false;
	}
	return true;
}


main()
{
	int n;
	cout<<"enter number of nodes: ";
	cin>>n;
	tree = (node*)calloc(1000,sizeof(node*));
	int child, parent, root;
	char id;

	for(int i = 0; i < n-1; i++)
	{
		cout<<"enter child:(<1000) ";
		cin>>child;
		cout<<"enter parent:(<1000) ";
		cin>>parent;
		cout<<"enter id(for left- 'l' && for right- 'r'): ";
		cin>>id;
		if(id == 'l' || id == 'r')
			insert(child, parent, id);
		else
		{
			cout<<"wrong id"<<endl;
			i--;
		}		
	}
	cout<<"enter root node: "<<endl;
	cin>>root;

	if(CheckBst(root))
		cout<<"tree is BST"<<endl;
	else
		cout<<"tree is not BST"<<endl;
	
	
}
