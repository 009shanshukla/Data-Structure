#include<bits/stdc++.h>
using namespace std;
//creating node entity
struct node
{
	int data;
	node* link;
	node* prev;
};

node* store(int val, node* head)
{

	// creating a node which is isolate	
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;
	newnode->prev = NULL;

   // creating a temparory node pointer to head , we do not disturb head pointer
 	node* temp = head;
  
	if(temp == NULL)   // if temp is not pointing , point it to first node     
	{
		head = newnode;
		return head;
	}
	
    // traverse until last node is not found
	while(temp->link !=	NULL)
		temp = temp->link;

	// add last node to newly created node 
	temp->link = newnode;
	newnode->prev = temp;

	//  return head;	
	return head; 

}
node* beg(int val, node* head)
{
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;
	newnode->prev = NULL;

// if list is empty
	if(head == NULL)
	{
		head = newnode;
		return head;
	}

// if list is non empty	
	if(head!= NULL)
	{
		node* temp = head;
		head = newnode;
		newnode->link = temp;
		temp->prev = newnode;
	}
			

	return head;
}

// store at given position
node* AnyPos(int val, int pos, node* head )
{
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;
	newnode->prev = NULL;

	int count = 0;

// if store at beginning
	if(pos == 1)
	{	
		newnode->link = head;
		head = newnode;
		head->prev = newnode;
		return head;
	}

// first find nth-1 node 
	node* temp = head;
	for(int i=0; i<pos-2; i++)
	{	
		temp = temp->link;
		if(temp == NULL && i != pos-2)
		{
			cout<<"out of position"<<endl;
			return head;
		}
	}

// link newnode to that node which is linked by nth-1 node
	newnode->link = temp->link;
	temp->link->prev = newnode;
// link nth-1 node to newnode then newnode will become nth node
	temp->link = newnode;
	newnode->prev = temp;

	return head;
	

}

node* DelFromEnd(node* head)
{
// in case of empty list
	if(head == NULL)
	{
		cout<<"List is empty"<<endl;
		return head;
	}


	node* temp = head;
// find address of second last node
	while(temp->link->link!= NULL)
		temp = temp->link;

// link last second address to null	
	temp->link = NULL;
// delete last node
	temp = temp->link;
	delete(temp);
	return head;
	
}

// delete from any position
node* DelFromAny(node* head, int id)
{
	node* temp = head;
	if(head == NULL)
	{
		cout<<"List is empty"<<endl;
		return head;
	}

// from beginning
	if(id == 1)
	{
		head = temp->link; //move head to next node
		head->prev = NULL;
		delete(temp);      //delete prev node
		return head;
	}
	
// just liking adding nth position
	for(int i=0; i<id-2; i++)
	{
		temp = temp->link;
		if(temp == NULL && i != id-2)
		{
			cout<<"out of position"<<endl;
			return head;
		}
	}
	node* temp1 = temp->link;
	temp->link = temp1->link;
	temp1->link->prev = temp;

	delete(temp1);
	return head;
}

void print(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->link;  
	}

}

void print_reverse(node* head)
{
	while(head->link != NULL)
		head = head->link;

	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->prev;  
	}

}


main()
{

	node* head = NULL;          //empty list
	int data,pos,ans;	
	while(1)
	{
		cout<<"To add press: 1"<<endl<<"to delete press: 2"<<endl;
		cin>>ans;
		if(ans == 1)
		{
			cout<<"enter data: ";
			cin>>data;
			cout<<"to exit press: 0"<<endl<<"1. for end press: 1"<<endl<<"2.for beg press 2"<<endl<<"3.for nth pos press : 3"<<endl;
			cin>>pos;
			if(pos == 0)
				break;
			else if(pos == 1)
				head = store(data, head);	
			else if(pos == 2)
				head = beg(data, head);		
			else if(pos == 3)
			{
				int id;
				cout<<"enter nth pos ";
				cin>>id;
				head = AnyPos(data, id, head);
			}
			else
			{
				cout<<"enter correct choice"<<endl;
				continue;
			}	
			
			print(head);
			cout<<endl;
			print_reverse(head);
			cout<<endl<<endl;
		}
		else if(ans == 2)
			{
				cout<<"1. from end press: 1"<<endl<<"2.from beg press 2"<<endl<<"3.from nth pos press : 3"<<endl;
				int pos;
				cin>>pos;
				if(pos == 1)
					head = DelFromEnd(head);
				else if(pos == 2)
					head = DelFromAny(head,1);
				else if(pos == 3)
				{
					int id;
					cout<<"enter pos: "<<endl;
					cin>>id;
					head = DelFromAny(head,id);		

				}
				print(head);
				cout<<endl;
				print_reverse(head);
				cout<<endl<<endl;
			}
		else
		{
			cout<<"enter correct choice"<<endl;
			continue;
		}
	}
}
