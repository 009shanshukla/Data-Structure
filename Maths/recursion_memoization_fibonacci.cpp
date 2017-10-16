#include<bits/stdc++.h>
using namespace std;
int F[100];

int fab(int n)
{
	if(F[n] != -1)
		return F[n];       // check if this state is stored

	F[n] = fab(n-1) + fab(n-2);      // store the completed state
	return F[n];
}



int main()
{

	int n;
	cout<<"enter number: ";
	cin>>n;
	F[0] = 0;
	F[1] = 1;
	
	for(int i = 2; i <= n; i++)
		F[i] = -1;

	int ans = fab(n);
	cout<<"ans: "<<ans<<endl;
 
	return 0;
}
