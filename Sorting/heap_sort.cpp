#include<bits/stdc++.h>
using namespace std;

int k;
int heap[100];

// creating max heap
void insert(int num, int loc)
{
	int parent;
	
	while(loc > 0)
	{
		parent = (loc - 1)/2;
		if(heap[parent] >= num)
		{
			heap[loc] = num;
			return;
		}
		heap[loc] = heap[parent];
		loc = parent;
	}
	heap[0] = num;
}

// just like deletion of node
void percolate(int index, int n)
{
	int parent, left, right, temp;

	left = 1;
	right = 2;
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

// displaying elements of heap	
void display(int n)
{
	for(int i = 0; i < n; i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}

main()
{
	int n, num, temp, count;
	cout<<"enter no. of elements: ";
	cin>>n;
	cout<<"enter elements: ";
	
	k = 0;

	for(int i = 0; i < n; i++)
	{
		cin>>num;
		insert(num, k);
		k = k + 1;
	}
	cout<<"heapify: ";
	display(n);

	count = n - 1;
	for(int i = n - 1; i >= 0; i--)
	{
		count = count - 1;
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		
		percolate(0, count);
	}

	display(n);
	
}
