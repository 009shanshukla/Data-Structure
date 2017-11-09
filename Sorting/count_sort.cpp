#include<bits/stdc++.h>
using namespace std;

main()
{
	int *arr, *s_arr, *c_arr;
	int maxi, n;

	cout<<"enter max_range of a number: ";
	cin>>maxi;

	c_arr = (int*)calloc(maxi, sizeof(int));

	cout<<"enter number of elements: ";
	cin>>n;

	cout<<"enter elements: ";

	s_arr = (int*)calloc(n, sizeof(int));
	arr = (int*)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
		cin>>arr[i];

	// storing number of occcurence of each number

	for(int i = 0;i < n; i++)
		c_arr[arr[i]] += 1;


	// storing total number of occurence of a number + less than that number

	for(int i = 0;i < maxi; i++)
		c_arr[i] += c_arr[i - 1];	 
		
	// storing numbers at their respective index in stable way
	
	for(int i = n - 1; i >= 0; i--)
	{
		s_arr[c_arr[arr[i]] - 1] = arr[i];
		c_arr[arr[i]] -= 1;
	}

	cout<<"sorted array: ";

	for(int i = 0; i < n; i++)
		cout<<s_arr[i]<<" ";
	
	cout<<endl;

}
