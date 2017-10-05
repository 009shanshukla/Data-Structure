#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* link;	
};
node* top = NULL;

void push(int val)
{
	if(top == NULL)
	{
		node* temp = new node();
		temp->data = val;
		temp->link = NULL;
		top = temp;
		return;
	}
	
	node* temp = new node();
	temp->data = val;
	temp->link = top;
	top = temp;
	return;
	
}

void pop()
{
	if(top == NULL)
	{
		cout<<"empty list"<<endl;
		return;
	}
	node* temp = top;	
	top = top->link;
	delete(temp);
	 
}

void top_element()
{
	cout<<"top data: "<<top->data<<endl;
}

void print()
{
	if(top == NULL)
	{
		cout<<"empty list"<<endl;
		return;	
	}
	node* temp = top;
	while(temp != NULL )
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
	cout<<endl;
}

int main()
{
	
	while(1)
	{	
		int input;
		cout<<endl<<"1. to push press: 1"<<endl<<"2. to pop press: 2"<<endl<<"3. for  top press: 3"<<endl<<"4. to exit press: 4"<<endl;
		cin>>input;

		switch(input)
		{
			case 1:	cout<<"enter element"<<endl;
					int val;
					cin>>val;
					push(val);
					cout<<"element pushed"<<endl;	
					print();
					break;

			case 2:	pop();
					print();
					break;

			case 3:	top_element();
					print();
					break;

			case 4:	exit(1);

			default: cout<<"incorrect input"<<endl;
						break;
		}



	}
	return 0;
}
