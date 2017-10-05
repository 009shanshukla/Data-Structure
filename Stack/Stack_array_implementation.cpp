#include<iostream>
#include<stdlib.h>
using namespace std;
int MAX_SIZE = 1000;       //max size of stack

class stack
{
		int top;
		int arr[1000];

	public:
		stack()        // constructor called
		{
			top = -1;
		}
		 
		void push(int value)
		{
			if(top == MAX_SIZE -1)  
			{
				cout<<"stack overflow"<<endl;
				return ;
			}
			arr[++top] = value;
		}

		void pop()
		{
			if(top == -1)
			{
				cout<<"stack empty"<<endl;
				return;
			}	
			top--;
			cout<<"element poped"<<endl;
		}

		void top_element()
		{
			if(top == -1)
			{
				cout<<"stack empty"<<endl;
				return ;
			}
			cout<<"top element "<<arr[top]<<endl;
		}

		void print()
		{
			if(top == -1)
			{
				cout<<"stack empty"<<endl;
				return;
			}
			for(int i = 0; i <= top; i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}

}; 

int main()
{
	
	stack st;	
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
					st.push(val);
					st.print();
					break;

			case 2:	st.pop();
					st.print();
					break;

			case 3:	st.top_element();
					st.print();
					break;

			case 4:	exit(1);

			default: cout<<"incorrect input"<<endl;
						break;
		}
	}
	return 0;
}






