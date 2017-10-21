#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include "hash.h"
#include "hash.cpp"
using namespace std;

int main()
{
	hash hash_obj;
	int input;
	string name;
	string drink;	

	while(1)
	{
		cout<<"to exit press 1: "<<endl<<"to add items press 2: "<<endl<<"to print table press 3: "<<endl<<"to search drink for a person press 4:"<<endl<<"to remove item press 5:"<<endl;

	cin>>input;
		
	switch(input)
	{
		case 1:	exit(1);
	
		case 2:	cout<<"enter name: ";
				cin>>name;
				cout<<"enter drink: ";
				cin>>drink;
				hash_obj.add_item(name, drink);
				break;

		case 3:	hash_obj.print_table();
				break;

		case 4:	cout<<"enter name: ";
				cin>>name;
				hash_obj.search_drink(name);
				break;

		case 5:	cout<<"enter name: ";
				cin>>name;
				hash_obj.remove_item(name);
				break;

		default: cout<<"incorrect input.. "<<endl;
				 break;		
	}

	}

	return 0;
}
