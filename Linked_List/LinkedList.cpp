#include<bits/stdc++.h>
using namespace std;
//creating node entity
struct node
{
	int data;
	node* link;
};

node* store(int val, node* head)
{

	// creating a node which is isolate	
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;

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

	//  return head;	
	return head; 

}
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

node* AnyPos(int val, int pos, node* head )
{
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;

	int count = 0;

	if(pos == 1)
	{	
		newnode->link = head;
		head = newnode;
		return head;
	}

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
	newnode->link = temp->link;
	temp->link = newnode;
	return head;
	

}

node* DelFromEnd(node* head)
{
	if(head == NULL)
	{
		cout<<"List is empty"<<endl;
		return head;
	}
	node* temp = head;

	while(temp->link->link!= NULL)
		temp = temp->link;
	
	temp->link = NULL;
	temp = temp->link;
	delete(temp);
	return head;
	
}

node* DelFromAny(node* head, int id)
{
	node* temp = head;
	if(head == NULL)
	{
		cout<<"List is empty"<<endl;
		return head;
	}
	if(id == 1)
	{
		head = temp->link;
		delete(temp);
		return head;
	}
	
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
				cout<<endl<<endl;
			}
		else
		{
			cout<<"enter correct choice"<<endl;
			continue;
		}
	}
}
