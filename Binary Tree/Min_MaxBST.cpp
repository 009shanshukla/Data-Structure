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

void min_max(BstNode* root)
{
	BstNode* temp = root;

	while(temp->right != NULL)
	{
		temp = temp->right;  // find rightmost node for max
	}
	cout<<"max: "<<temp->data<<endl;
	
	temp = root;

	while(temp->left != NULL)
	{
		temp = temp->left;           // find left most node for min
	}
	cout<<"min: "<<temp->data<<endl;
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

	min_max(root);

	return 0;
}
