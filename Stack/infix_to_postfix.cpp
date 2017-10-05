#include<bits/stdc++.h>
using namespace std;

// A good Problem

bool is_operand(char c) // checking for variable
{
	if(c >= 'a' && c <= 'z')
		return true;
	else if(c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

int weight(char c)    // for precedence giving weight 1 to 3
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;	
	}
}

bool right_associative(char c)  // in case of ^ , this is right associative
{
	if(c == '^')
		return true;
	else
		return false;	
}


bool precedence(char op1, char op2)      // comparing precedence for op1 -> in top of stack and current operator
{
	int w1 = weight(op1);          
	int w2 = weight(op2);

	if(w1 == w2)       // if both are same operator , checking for '^'
	{
		if(right_associative(w1))
			return false;
		else
			return true;
	}

	return w1 > w2 ? true : false;  // if on stack top operator's precedence is much then pop it , that's why returng true for poping
}




void postfix(char* ch, int len)
{
	stack< char > s;
	char result[100];       // strore result
	int k = 0;        // for counting length of result

	for(int i = 0; i< len; i++)
	{
		if(is_operand(ch[i]))        // if variable , simply store
			result[k++] = ch[i];

		else if(ch[i] == '(')      // if open bracket , push on stack
			s.push(ch[i]);

		else if(ch[i] == ')')     // in case of close bracket, pop until first open bracket not found
		{
			
			while(!s.empty() && s.top() != '(')
			{
				result[k++] = s.top();
				s.pop();            // poping all operator till first open bracket
			}
			s.pop();       // poping first open bracket
		}

		else
		{
			while(!s.empty() && s.top() != '(' && precedence(s.top(), ch[i]))  // in case of operator, pop from stack in case of high precedence operator is present
			{
				result[k++] = ch[i];
				s.pop();
			}
			s.push(ch[i]);  // push current operator
		}
	}

	while(!s.empty())    //after reaching end to parsing , whatever remains in stack , pop it
	{
		result[k++] = s.top();
		s.pop();
	}
	
	for(int i = 0; i<k; i++) //printing result
		cout<<result[i];

	cout<<endl;


}


int main()
{
	char ch[100];

	while(1)
	{
		cout<<"enter string infix: "<<endl;
		cin>>ch;
		postfix(ch, strlen(ch));
	}

	return 0;
}
