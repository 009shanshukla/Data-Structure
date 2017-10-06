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
	if(root == NULL) // if node reach to last or empty
	{
		BstNode* newnode = new BstNode();  // create and set node
		newnode->data = val;
		newnode->left = NULL;
		newnode->right = NULL;
		root = newnode;   // assign current node adress to root
	}	 
	else if(val > root->data)     // if inserted data is greater than node data , call right subtree
		root->right = insert(val, root->right);   // now assign creates node adress that is returned to as right node of current node

	else
		root->left = insert(val, root->left); //if inserted data is equal or less than node data , call left subtree,// now assign creates node adress that is returned to as right node of current node

		return root;       // return adress of first node 
}

void print(BstNode* temp)
{
	if(temp == NULL)           // print in infix order root, left then right
		return;

	cout<<temp->data<<" ";
	print(temp->left);
	print(temp->right);	

}

void search(int val, BstNode* temp)
{
	if(temp == NULL)                                  // just like insertion 
	{
		cout<<"data: "<<val<<" NOT found"<<endl;
		return;	
	}

	if(val == temp->data)
	{
		cout<<"data: "<<val<<" found"<<endl;
		return;
	}
	else if(val > temp->data)
		return search(val, temp->right);
	else
		return search(val, temp->left);	

}


int main()
{
	int inp;
	BstNode* root = NULL;
	while(1)
	{
		cout<<"to insert press: 1 "<<endl<<"to search press: 2"<<endl<<"to exit press: 3"<<endl;
		cin>>inp;
		switch(inp)
		{
			case 1:	cout<<"enter data: ";
					int val;
					cin>>val;
					root = insert(val, root);
					print(root);
					cout<<endl;
					break;

			case 2:	cout<<"enter data that you want to search: ";
					int val1;
					cin>>val1;
					search(val1,root);
					cout<<endl;
					break;


			case 3: exit(1);

			default: cout<<"wrong input"<<endl;
					 break;		

		}
		
	}
	return 0;
}
