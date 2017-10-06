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

int height(BstNode* root)
{
	if(root == NULL)
		return -1;     // leaf node will return -1 beacuse leaf node height should be zero after adding 1 

	return max(height(root->left), height(root->right)) + 1;
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

	cout<<"height: "<<height(root)<<endl;

	return 0;
}
