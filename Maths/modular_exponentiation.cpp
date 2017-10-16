#include<bits/stdc++.h>
using namespace std;

int power(int n, int x, int m)
{
	if(x == 0)
		return 1;

	else if(x % 2 == 0)
	{
		int y = power(n, x / 2, m);       // spliting into two half
		return (y * y) % m;
	}
	else
	{
		return ((n % m) * power(n, x - 1, m)) % m;   // spliting into even
	}
}


int main()
{
	int n, x, m;
	cout<<"enter number: ";
	cin>>n;
	cout<<"enter power: ";
	cin>>x;
	cout<<"enter modulo: ";
	cin>>m;	

	int ans = power(n, x, m);
	cout<<"ans: "<<ans<<endl;

	return 0;
}
