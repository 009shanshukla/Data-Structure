#include<bits/stdc++.h>
using namespace std;
main()
{
	char arr[100];
	int n, rem, i = 0;
	cout<<"enter number: ";
	cin>>n;

	while(n > 0)
	{
		rem = n % 2;
		arr[i++] = rem + '0';   // convert digit to character
		n = n/2;
	}
	for(i--; i >= 0; i-- )
	cout<<arr[i];
	cout<<endl;
}
