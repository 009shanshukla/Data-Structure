#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, count;
	cout<<"enter number: ";
	cin>>n;
		
	for(int i = 2; i*i <= n; i++)
	{
		if(n % i == 0)             // if i divides n
		{
			count = 0;
			while(n % i == 0)        // count untill that number is divided by i
			{
				count++;
				n = n / i;
			}
			printf("(%d, %d)\n", i, count);
		}
	}
	if(n != 1)
	{
		printf("(%d, 1)\n", n);
	}

	return 0;
}
