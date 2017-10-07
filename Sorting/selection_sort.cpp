#include<bits/stdc++.h>
using namespace std;

void selection_sort(int* arr, int n)
{
	int min_index, temp;
	for(int i = 0; i < n-1; i++)
	{
		min_index = i;         // assume this index is min
		for(int j = i+1; j < n; j++)      // now check for min index that has min element from this index
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		temp = arr[min_index];     // now swap element from current index of i to min index
		arr[min_index] = arr[i];
		arr[i] = temp;
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

	selection_sort(arr, n);
}
	return 0;
}
