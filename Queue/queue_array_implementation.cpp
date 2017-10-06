#include<iostream>
#include<stdlib.h>
using namespace std;

int MaxSize = 4;   // to check is_full() take max size less
int front = -1;    
int rear = -1;
int queue[4];

bool is_empty()
{
	if(front == -1 && rear == -1)   //front and rear indexing no where       
		return true;
	else
		return false;
}

bool is_full()
{
	if((rear+1)%MaxSize == front)   // by modulo it will check if index is empty at back side of front
		return true;
	else
		false;	
}

void enqueue(int val)
{
	if(is_empty())
	{
		front = rear = 0;            // in case of empty queue , increase both index
		queue[rear] = val;	
		return;
	}

	else if(is_full())
	{
		cout<<"queue is full"<<endl;
		return;
	}
	else
	{
		rear = (rear+1)%MaxSize;        // increase rear and check if it reached on last index then change vaue to back of front by doing modulo
		queue[rear] = val;		
	}
}

void dequeue()
{
	if(is_empty())                   
	{
		cout<<"queue is empty"<<endl;	
		return;
	}
	else if(front == rear)
	{
		front = rear = -1;          // in case when only one element is in queue;
		return;
	}
	else
	{
		front = (front+1)%MaxSize;            // just like enqueue , increase front by doing modulo
	}
}

int front_element()
{
	return queue[front];
}

void print()
{

	int count;
	if(rear > front)                    // when no back indexing
		count = rear - front + 1;
	else if(rear == front)          // only one element
		count = 1;
	else
		count = MaxSize - front + 1 + rear;         // in case of back indexing

	int index = front;
	for(int i = 0; i< count; i++)
	{
		cout<<queue[index]<<" ";
		index = (index + 1)%MaxSize;
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
