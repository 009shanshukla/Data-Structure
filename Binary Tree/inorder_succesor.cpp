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
	if(temp == NULL)           // print in inorder order root, left then right
		return;

	print(temp->left);
	cout<<temp->data<<" ";
	print(temp->right);	

}

BstNode* find_min(BstNode* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;	
}

BstNode* search(int val, BstNode* temp)
{
	if(temp == NULL)                                  // just like insertion 
	{
		cout<<"data: "<<val<<" NOT found"<<endl;
		return NULL;	
	}

	if(val == temp->data)
	{
		cout<<"data: "<<val<<" found"<<endl;
		return temp;
	}
	else if(val > temp->data)
		return search(val, temp->right);
	else
		return search(val, temp->left);	

}

BstNode* successor(BstNode* current, int data)
{

	BstNode* root = search(data, current);      // search for node address

	if(root == NULL)      // data not found or empty
	{
		cout<<"NOT FOUND"<<endl;
		return root;
	}

	// case 1   if there is a right subtree
	if(root->right != NULL)
	{
		return find_min(root->right);     // find left most of right subtree , mean minimum of right subtree 
	}		

	// case 2

	if(root-> right == NULL)     // if there is no right subtree that means , it can be left most incestor which is not visited
	{
		BstNode* successor_node = NULL;  // now find successor from start
		BstNode* ancestor = root;    // visit from start node
		
		while(ancestor != current)  // visit till current node
		{
			if(ancestor->data > current->data) // in case of left sub tree
			{
				successor_node = ancestor;    // this can be successor
				ancestor = ancestor->left;    // move left 
			}
			else
				ancestor = ancestor->right;  // in case of right subtree , just move
		}
		return successor_node;
		
	}	
 

}



int main()
{
	int inp;
	BstNode* temp1;
	BstNode* root = NULL;
	while(1)
	{
		cout<<"to insert press: 1 "<<endl<<"for inorder successor press: 2"<<endl<<"to exit press: 3"<<endl;
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

			case 2:	cout<<"enter data for that u want inorder successor: ";
					int v;
					cin>>v;
					temp1 = successor(root, v);
					if(temp1 != NULL)
						cout<<temp1->data<<endl;
					break;	

			case 3: exit(1);


			default: cout<<"wrong input"<<endl;
					 break;		

		}
		
	}
	return 0;
}
