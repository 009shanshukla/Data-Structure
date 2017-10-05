#include<bits/stdc++.h>
using namespace std;

void check_for_paranthesis(char* ch, int len)
{
	stack <char> s;
	for(int i =0; i<len; i++)
	{
		if(ch[i] == '(' || ch[i] == '{' || ch[i] == '[')   // if bracket is open bracket
			s.push(ch[i]);
	
		if(ch[i] == ']' || ch[i] == '}' || ch[i] == ')')   // if encounter close bracket
		{
			if(s.empty())                 // no element remains to match
			{
				cout<<"NO"<<endl;
				return;
			}

			char temp = s.top();            // matchin paranthesis
			if(ch[i] == '}' && temp != '{')
			{
				cout<<"NO"<<endl;
				return;
			}
			else if(ch[i] == ']' && temp != '[')
			{
				cout<<"NO"<<endl;
				return;
			}
			else if(ch[i] == ')' && temp != '(')
			{
				cout<<"NO"<<endl;
				return;
			}
			else         // if paranthesis matched
				s.pop();
		}
	}
	if(s.empty())    // if all matched stack should be empty
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;

}

int main()
{
	char ch[1000];
	while(1)
	{
		cin>>ch;
		check_for_paranthesis(ch, strlen(ch));
	}
	return 0;
}
