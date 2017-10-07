#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int* arr, int n)
{
	int flag, temp;
	for(int i = 0; i < n-1; i++)     // just for parsing till end
	{
		flag = 0;   // to check if there is swap
		for(int k = 0; k < n-i-1; k++)     // from 1st to decrement order in last
		{
			if(arr[k] > arr[k+1])     
			{
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
				flag = 1;                    // there is swap
			}
		}
		if(flag == 0)  // if no swap
			break;

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

	bubble_sort(arr, n);
}
	return 0;
}
