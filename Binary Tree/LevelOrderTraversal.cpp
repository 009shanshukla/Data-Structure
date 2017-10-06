#include<bits/stdc++.h>
using namespace std;

// node for BST
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

// insertion in BST
BstNode* insert(int val, BstNode* root)
{
	if(root == NULL) 
	{
		BstNode* newnode = new BstNode();  
		newnode->data = val;
		newnode->left = NULL;
		newnode->right = NULL;
		root = newnode;   
	}	 
	else if(val > root->data)     
		root->right = insert(val, root->right);   

	else
		root->left = insert(val, root->left); 

		return root;      
}

void level_order(BstNode* root)
{
	queue< BstNode* > q;
	if(root == NULL)
	{
		cout<<"No element"<<endl;
		return;
	}

	q.push(root);         // insert first node address
	while(!q.empty())
	{
		cout<<q.front()->data<<" ";            // print front of queue

		if(q.front()->left != NULL)
			q.push(q.front()->left);         // add left child in queue

		if(q.front()->right != NULL)
			q.push(q.front()->right);      // add right child in queue

		q.pop();     // remove visited node
	}
	cout<<endl;
}



int main()
{
	BstNode* root = NULL;
	root = insert(15,root);
	root = insert(10,root);
	root = insert(20,root);
	root = insert(17,root);
	root = insert(25,root);
	root = insert(8,root);
	root = insert(12,root);

	level_order(root);

	return 0;
}
