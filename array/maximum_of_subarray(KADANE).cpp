#include<bits/stdc++.h>
using namespace std;

int subarray(int* arr, int n)
{
	int sum = 0, ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(sum + arr[i] > 0)
		{
			sum = sum + arr[i];
			ans = max(sum, ans);
		}
		else
		{
			sum = 0;			
		}
	}
	cout<<"ans: "<<ans<<endl;
}

int main()
{
	int arr[100];
	int n;
	cout<<"array length: ";
	cin>>n;
	cout<<"enter array: ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	subarray(arr, n);

	return 0;
}
