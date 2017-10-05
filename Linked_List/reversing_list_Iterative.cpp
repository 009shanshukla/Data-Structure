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
// reversing linked list

node* reverse(node* head)
{
	if(head == NULL)
	{
		cout<<"list is empty"<<endl;
		return head;
	}  

	node* current = head;
	node* prev = NULL;   // first node will store null 
	node* next;
	while(current != NULL)
	{
		next = current->link;  // store address of next node
		current->link = prev;  // change link to previous node
		prev = current;			// move previous node to current	
		current = next;			// move current to next node
		
	}
	head = prev;    // prev holds address of last node so assign it to head
	return head;
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

	head = reverse(head);
	print(head);
}
