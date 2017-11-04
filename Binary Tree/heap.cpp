#include<bits/stdc++.h>
using namespace std;

int heap[100], n;

void display()
{
	if(n == 0)
	{
		cout<<"heap is empty"<<endl;
		return;	
	}	

	for(int i = 0; i < n; i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}

// inserting 
void insert(int num, int loc)
{
	int parent;
			
	while(loc > 0)
	{
		parent = (loc - 1)/2;
		
	//checking parent node that is greater or equal to inserted node
		if(num <= heap[parent])
		{
			heap[loc] = num;
			return;
		}
	// move node one index down
		heap[loc] = heap[parent];
		loc = parent;
	}
// in case of first node
	heap[0] = num;
}

// seaching for number
int search(int num)
{
	for(int i = 0; i < n; i++)
	{
		if(heap[i] == num)
		{
			return i;
		}
	}
	return -1;
}

// deleting node
void deleting(int num)
{
	int temp, left, right, parent;

	// search if number is present, then return index;

	int index = search(num);

	if(index == -1)
	{
		cout<<"number is not found"<<endl;
		return;
	}
// inserting last element at that index; 	
	heap[index] = heap[n-1];

	n = n - 1;    // total element is decremented by 1

	parent = (index - 1)/2;

	if(heap[parent] < heap[index])
	{
		insert(num, index);   
		return;
	}

	left = 2 * index + 1;
	right = 2 * index + 2;

// right child will be the last index

	while(right < n)
	{
		if(heap[index] >= heap[left] && heap[index] >= heap[right])	
			return;

		// in case of left 
	
		if(heap[left] >= heap[right])
		{
			temp = heap[index];  //exchange
			heap[index] = heap[left];
			heap[left] = temp;
			index = left;
		}	
		else   // in case of right
		{
			temp = heap[index];
			heap[index] = heap[right];
			heap[right] = temp;
			index = right;
		}
		left = 2 * index + 1;
		right = 2 * index + 2;
	}	

 // in case of last index
	if(left == n - 1 && heap[index])
	{
		temp = heap[index];  //exchange
		heap[index] = heap[left];
		heap[left] = temp;
	}
}

int main()
{
	n = 0;
	int num;
	int choice;
	while(1)
	{
		cout<<"1: to insert press: 1"<<endl<<"2: to delete press: 2"<<endl<<"3: to display press: 3"<<endl<<"4: to exit press: 4"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:	cout<<"enter value: ";
					cin>>num;
					insert(num, n);
					n = n + 1;
					break;

			case 2:	cout<<"enter value to delete: ";
					cin>>num;
					deleting(num);
					break;

			case 3:	cout<<"heap are: ";
					display();
					break;
		
			case 4:	exit(1);

			default: cout<<"wrong input"<<endl;
					 break;		
		}		
	}
	return 0;
}
