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

bool BstUtil(int root, int max, int min)
{
	if(root == 0 )
		return true;

	if(root > min && root < max && BstUtil(tree[root].left, root, min) && BstUtil(tree[root].right, max, root) )
		return true;
	else
		return false;
}

bool CheckBst(int root)
{
	return BstUtil(root, INT_MAX, INT_MIN);
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
