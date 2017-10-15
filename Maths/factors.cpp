#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr1[100], arr2[100], n, y = 0, z = 0;
	cout<<"enter number: ";
	cin>>n;
	
	for(int i = 1; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			arr1[y++] = i;                // if i divides n then n / i divides n
			
			if(i*i != n)                 // in this case i and n / i will be equal, two arrays are used to print in sorted array
			{
				arr2[z++] = n/i;
			}		
		}
	}
	
	cout<<"factors are: ";
	
	for(int i = 0; i < y; i++)
		cout<<arr1[i]<<" "; 
	for(z--; z >= 0; z--)
		cout<<arr2[z]<<" "; 
	cout<<endl;

	return 0;
}
