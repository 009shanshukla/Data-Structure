 #include<bits/stdc++.h>
using namespace std;
//creating node entity
struct node
{
	int data;
	node* link;
};

// inserting node at beginning

node* beg(int val, node* head)
{
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;

	if(head!= NULL)
	{
		node* temp = head;
		head = newnode;
		newnode->link = temp;
	}
	if(head == NULL)
	{
		head = newnode;
		return head;
	}		

	return head;
}
// printing linked list using recurssion

void print(node* head)
{
	if(head == NULL)
		return;

	cout<<head->data<<" ";
	
	print(head->link);
}

void reverse_print(node* head)
{
	if(head == NULL)
		return;
	
	reverse_print(head->link);
	cout<<head->data<<" ";
}


main()
{
	node* head = NULL;          //empty list
	int data,pos,ans;	
	head = beg(1,head);
	head = beg(2,head);
	head = beg(3,head);
	head = beg(4,head);
	print(head);
	cout<<endl;
	// list is 4,3,2,1 , now going to print in reverse
	reverse_print(head);
	cout<<endl;

	
}
