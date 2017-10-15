#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);             // if divisor becomes zero, return dividend
}

int main()
{
	int a, b, ans;
	cout<<"enter a: ";
	cin>>a;
	cout<<"enter b: ";
	cin>>b;
	if(a >= b)
		ans = gcd(a, b);
	else
		ans = gcd(b, a);	

	cout<<"gcd: "<<ans<<endl;

	return 0;
}


