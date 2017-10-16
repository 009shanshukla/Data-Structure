#include<bits/stdc++.h>
using namespace std;

int power(int n, int x)
{
	if(x == 0)
		return 1;

	else if(x % 2 == 0)
	{
		int y = power(n, x / 2);       // spliting into two half
		return y * y;
	}
	else
	{
		return n * power(n, x - 1);   // spliting into even
	}
}


int main()
{
	int n, x;
	cout<<"enter number: ";
	cin>>n;
	cout<<"enter power: ";
	cin>>x;

	int ans = power(n, x);
	cout<<"ans: "<<ans<<endl;

	return 0;
}
