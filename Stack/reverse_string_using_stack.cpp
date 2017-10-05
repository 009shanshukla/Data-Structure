#include<bits/stdc++.h>
using namespace std;


void reverse(char* ch, int len)
{
	stack<char> s;

	for(int i = 0; i<len; i++)
		s.push(ch[i]);
	
	int i = 0;
	while(!s.empty())
	{
		ch[i++] = s.top();
		s.pop();
	}
}

int main()
{
	char ch[100];
	cin>>ch;
	
	reverse(ch, strlen(ch));
	cout<<ch<<endl;		
}
