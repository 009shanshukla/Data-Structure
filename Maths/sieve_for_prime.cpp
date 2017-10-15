#include<bits/stdc++.h>
using namespace std;

main()
{
	int n;
	bool arr[100];
	cout<<"enter number: ";
	cin>>n;	

	for(int i = 2; i <= n; i++)
	{
		arr[i] = true;
	}
	
	for(int i = 2; i*i <= n; i++)
	{
		if(arr[i] == true)     // if number i is prime
		{
			for(int j = 2; i*j <= n; j++ )    // convert all multiple of i to non-prime
			{
				arr[i*j] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++)
	{
		if(arr[i] == true)
			cout<<i<<" ";
	}
	cout<<endl;

}
