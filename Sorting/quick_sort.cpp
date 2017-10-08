#include<bits/stdc++.h>
using namespace std;

int partition(int* arr, int start, int end)
{
	int pivot = arr[end];    // assume last index as pivot
	int p_index = start;      // now start from starting of partion index 
	int temp; 
	
	for(int i = start; i < end; i++) // look till last first of pivot that is (end-1)
	{
		if(pivot >= arr[i])       // if pivot is greater then swap element  ('partition index' and current index 'i')
		{
			temp = arr[p_index];
			arr[p_index] = arr[i];
			arr[i] = temp;
			p_index++; 		
		}	
	}
	arr[end] = arr[p_index];         // now at last swap pivot element and partion index to fit the position of pivot 
	arr[p_index] = pivot;
	return p_index;	

}

void quick_sort(int* arr, int start, int end)
{
	if(end > start)       // process will go untill pivot element has no right left
	{
		int pivot_index = partition(arr, start, end);   // it will return where pivot is placed 

		quick_sort(arr, start, pivot_index-1);    // now will go left of pivot
		quick_sort(arr, pivot_index+1, end);     // and then will go right of pivot

	}
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

		quick_sort(arr, 0, n-1);

	cout<<"sorted array: ";
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
	}
	
	return 0;
}
