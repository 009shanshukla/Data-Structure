#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int* arr, int n)
{
	int hole, value;
	for(int i = 1; i < n; i++)
	{
		hole = i;       //pick out this index element
		value = arr[hole];    // store pick up element in new register
		while(hole > 0 && arr[hole-1] > value)   // check for new pos to fit 
		{
			arr[hole] = arr[hole-1];  // shift element 
			hole = hole-1;
		}
		arr[hole] = value;     // store to that hole that found
	}

	cout<<"sorted element: ";
	for(int i =0; i < n; i++)
		cout<<arr[i]<<" ";

	cout<<endl;	

} 

int main()
{
	int n;
	int arr[1000];
	while(1)
{	
	cout<<"enter number of elements: ";
	cin>>n;
	cout<<"enter elements: ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	insertion_sort(arr, n);
}
	return 0;
}
