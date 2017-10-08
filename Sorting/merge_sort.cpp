#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int* left, int* right, int left_size, int right_size)
{
	int i = 0, j = 0, k = 0;  // 'i' will keep track of left array, j will do for right and k will do for original array 
	
	while(i < left_size && j < right_size)     // compare index by index element untill one or both array will not exhaust
	{
		if(left[i] <= right[j])  // if left array is smaller, add it in originay array
		{
			arr[k++] = left[i++]; 
		}
		else   // otherwise add right array element in original array
		{ 
			arr[k++] = right[j++];
		}
	}

	while(i < left_size)    // in case of only one array exhaust , one array will have some element, add them in original array, in this case left array
	{
		arr[k++] = left[i++];
	}

	while(j < right_size)    // in case of only one array exhaust , one array will have some element, add them in original array, in this case right array
	{
		arr[k++] = right[j++];
	}
	
}


void merge_sort(int* arr, int size)
{
	if(size < 2)
		return;       // split untill 1 size array remains

	int mid = size/2;         // split half
	int* left = new int(mid);     // create  left array
	int* right = new int(size-mid); // create  right array

	for(int i = 0; i < mid; i++)
		left[i] = arr[i];       // add half elements in left array

	for(int i = mid; i < size; i++)
		right[i-mid] = arr[i];   // add other half elements in right array

	merge_sort(left, mid);     // split again left array until 1 size array remains
	merge_sort(right, size-mid);   // split  right array likewise left array

	merge(arr,left, right, mid, size-mid);   // now merge both left and right array and sort them
  
	delete left;       // deletion of dynamic created array is necessary for space complexity
	delete right;

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
	
		merge_sort(arr, n);
		
		cout<<"sorted array: ";
		for(int i =0; i < n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}
