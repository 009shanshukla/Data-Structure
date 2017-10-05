 #include<bits/stdc++.h>
using namespace std;
//creating node entity
struct node
{
	int data;
	node* link;
};
// inserting node at beginning
node* temp_head;
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
// reversing linked list

void reverse(node* head)
{
	// go to last node
	if(head->link == NULL)
	{	
		// change head position that is going to deal in temp_head
		temp_head = head;
		return;
	}
	reverse(head->link); 

	// here after backtracking we are on second last node , now store next node 
	node* temp = head->link;

	// change link of next node to node on which right now
	temp->link = head;

	// node on which currently are, link it to from null
	head->link = NULL;

}

void print(node* head)
{
	while(head != NULL)  
	{
		cout<<head->data<<" ";
		head = head->link;  
	}
	cout<<endl;
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

// list is 4,3,2,1 , now going to reverse
	temp_head = head;        // now head is going to store in new head variable
	reverse(head);
	print(temp_head);

	
}
