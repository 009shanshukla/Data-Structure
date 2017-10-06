#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* link;
};

node* front = NULL;
node* rear = NULL;

bool is_empty()
{
	if(front == NULL && rear == NULL)
		return true;
	else
		return false;	
}

void enqueue(int val)
{
	node* newnode = new node();
	newnode->data = val;
	newnode->link = NULL;

	if(is_empty())             // if queue is empty
	{
		front = newnode;         
		rear = newnode;
		return;
	}

	rear->link = newnode;       // if not , move only rear
	rear = newnode;    

}

void dequeue()
{
	if(is_empty())
	{
		cout<<"list is empty "<<endl;
		return;
	}

	else if(front == rear)        // in case of only one element
	{
		free(front);
		front = NULL;
		rear = NULL;	
	}
	else                  // if more than one element, move only front
	{
		node* temp = front;
		front = front->link;
		free(temp);
	}

}

int front_element()
{
	return front->data;
}

void print()
{
	node* temp = front;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
	cout<<endl;
}

int main()
{
	int inp;

	while(1)
	{
		cout<<"1. to enqueue press 1"<<endl<<"2. to dequeue press 2"<<endl<<"3. for front element press 3"<<endl<<"4. to check empty press 4"<<endl<<"5. to exit press 5";
		cout<<endl;
		cin>> inp;

		switch(inp)
		{
			case 1:	cout<<"enter value: ";
					int val;
					cin>>val;
					enqueue(val);
					print();
					break;

			case 2: dequeue();
					print();
					break;

			case 3:	if(is_empty())
					{
						cout<<"queue is empty"<<endl;	
						break;
					}	
					cout<<"front element "<<front_element()<<endl;
					print();
					break;

			case 4:	if(is_empty())
					{
						cout<<"empty queue"<<endl;
						break;					
					}
					else
					{
						cout<<"not empty"<<endl;
						break;
					}
			case 5:	exit(1);

			default: cout<<"wrong input"<<endl;
					 break;  
		}



	}
	return 0;
}
