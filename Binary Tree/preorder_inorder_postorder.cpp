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

void preorder(BstNode* root)     // root, left, right
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(BstNode* root)        // left, root, right
{
	if(root == NULL)
		return;

	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(BstNode* root)      //left, right, root
{
	if(root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
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

	cout<<"inorder: ";
	inorder(root);
	cout<<endl;

	cout<<"preorder: ";
	preorder(root);
	cout<<endl;

	cout<<"postorder: ";
	postorder(root);
	cout<<endl;
	return 0;
}
