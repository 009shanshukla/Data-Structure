#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int height;
};

node* create(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int height(node* n)
{
	if(n == NULL)
		return 0;
	else
		return n->height;
}

void print(node* n)
{
	if(n == NULL)
		return;
	cout<<n->data<<" ";
	print(n->left);
	print(n->right);	
}

int maxx(int a, int b)
{
	return (a > b ? a : b);
}

int get_balance(node* n)
{
	if(n == NULL)
		return 0;

	return (height(n->left) - height(n->right));
}

node* left_rotate(node* n)
{
//	cout<<"left rotation.."<<endl;
	node* temp1 = n->right;
	node* temp2 = temp1->left;

	temp1->left = n;
	n->right = temp2;

	n->height = 1 + maxx(height(n->left), height(n->right));
	temp1->height = 1 + maxx(height(temp1->left), height(temp1->right)); 
//	cout<<"returning  node after left rotation.. "<<temp1->data<<endl;
	return temp1;
	

}

node* right_rotate(node* n)
{
//	cout<<"right rotation.."<<endl;
	node* temp1 = n->left;
	node* temp2 = temp1->right;

	temp1->right = n;
	n->left = temp2;

	n->height = 1 + maxx(height(n->left), height(n->right));
	temp1->height = 1 + maxx(height(temp1->left), height(temp1->right)); 
//	cout<<"returning  node after right rotation.. "<<temp1->data<<endl;
	return temp1;

}

node* insert(int data, node* root)
{
// BST insertion	
	if(root == NULL)
	{
		node* temp = create(data);
	//	cout<<"returning from node.. "<<temp->data<<endl;
		return temp;
	}
	
	if(data > root->data)
	{
	//	cout<<"going right of node "<<root->data<<endl;
		root->right = insert(data, root->right);	
	//	cout<<"inserting "<<root->right->data<<"on right of "<<root->data<<endl;
	}
	else if(data < root->data)
	{
	//	cout<<"going left of node "<<root->data<<endl;
		root->left = insert(data, root->left);
	//	cout<<"inserting "<<root->left->data<<"on left of "<<root->data<<endl;
	}
	else
	{
		return root;
	}

// height update on this node

	root->height = 1 + maxx(height(root->left), height(root->right));
//	cout<<"current node"<<root->data<<endl;
//	cout<<"height "<<root->height<<endl;

// get balanced
//	cout<<"getting balance...  ";
	int balance = get_balance(root);   // check for current node
	cout<<balance<<endl;

// for left subtree insertion

	if(balance > 1)
	{
	// left insertion
		if(data < root->left->data)
		{
	//		cout<<"left left insertion....."<<endl;
			node* temp = right_rotate(root);
	//		cout<<"returning from.. "<<temp->data<<endl;
			return temp;
		}
	// right insertion 
		else
		{
	//		cout<<"left right insertion....."<<endl;
			root->left = left_rotate(root->left);
	//		cout<<"after left rotation inserting "<<root->left->data<<"on right of "<<root->data<<endl;
			node* temp = right_rotate(root);
	//		cout<<"returning from.. "<<temp->data<<endl;
			return temp;
		}
	}	 
	
	if(balance < -1)
	{
	// right insertion
		if(data > root->right->data)
		{
	//		cout<<"right right insertion....."<<endl;
			node* temp = left_rotate(root);
	//		cout<<"returning from.. "<<temp->data<<endl;
			return temp;
		}
	// left insertion 
		else
		{
	//		cout<<"right left insertion....."<<endl;
			root->right = right_rotate(root->right);
//			cout<<"after right rotation inserting "<<root->right->data<<"on right of "<<root->data<<endl;
			node* temp = left_rotate(root);
	//		cout<<"returning from.. "<<temp->data<<endl;
			return temp;
		}
	}
// root pointer (unchanged)
//	cout<<"returning finally from node"<<root->data<<endl;
	return root;

}

int main()
{
	node* root = NULL;
	int inp, data;
	while(1)
	{
		cout<<"1. to insert press 1: "<<endl<<"2. to print press 2: "<<endl<<"3. to exit press 3: "<<endl;
		cin>>inp;
	//	inp = 1;
		switch(inp)
		{
			case 1:	cout<<"enter data: ";
					cin>>data;
					root = insert(data, root);
		//			cout<<"avl nodes are: ";
		//			print(root);
		//			cout<<endl<<"............."<<endl;
					break;

			case 2:	cout<<"avl nodes are: ";
					print(root);
					cout<<endl;
					break;	

			case 3:	exit(1);
	
			default: cout<<"wrong input"<<endl;	
					break;
		}
		
	}
	return 0;
}
