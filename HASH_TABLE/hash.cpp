#include<bits/stdc++.h>
using namespace std;


// constructor 

hash :: hash()
{
	// declaring initial values to object
	for(int i = 0; i < table_size; i++)
	{
		hash_table[i] = new item;
		hash_table[i]->name = "empty";
		hash_table[i]->drink = "empty";
		hash_table[i]->next = NULL; 
	}
}

// Hash function

int hash :: Hash(string key)
{
	int hash = 0;
	int index;
	
	int loop = key.length();

	for(int i = 0; i < loop; i++)
	{
		hash = hash + key[i];
	}		
	index = hash % table_size;     // table_size modulo of sum of ASCII value of characters

	return index; 
}

// adding items

void hash :: add_item(string name, string drink)
{
	int index = Hash(name);       // first find index using hash function

	if(hash_table[index]->name == "empty")      // in case of empty
	{
		hash_table[index]->name = name;
		hash_table[index]->drink = drink;
		hash_table[index]->next = NULL;
	}	

	else          // in case if item is already present at that index
	{
		item* ptr = hash_table[index];

		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while(ptr->next != NULL)        // add to the last of list
		{
			ptr = ptr->next;
		}	 
		ptr->next = n;

	}

	
}

//counting number of items at  index

int hash :: number_of_items_in_index(int index)
{
	int count = 0;

	if(hash_table[index]->name == "empty")     
		return count;
	
	else
	{
		count = 1;
		item* ptr = hash_table[index];
		
		while(ptr->next != NULL) // move upto  last element of list at that index
		{
			count++;
			ptr = ptr->next;
		}
			
		return count;
	}
}

// printing whole table

void hash :: print_table()
{

	for(int i = 0; i < table_size; i++)
	{
		cout<<"........................................."<<endl;
		cout<<"index:  "<<i<<endl;
		cout<<"name: "<<hash_table[i]->name<<endl;
		cout<<"drink: "<<hash_table[i]->drink<<endl;

		if(number_of_items_in_index(i) > 0)      // if some more item present at that index
			print_items_in_index(i);
		
	}
}

// printing items at index

void hash :: print_items_in_index(int index)
{
	if(hash_table[index]->name == "empty")
		cout<<"index is empty"<<endl;

	else
	{
		item* ptr = hash_table[index];
		cout<<"printing items at index ...."<<endl;
		while(ptr != NULL)
		{
			cout<<"name: "<<ptr->name<<endl;
			cout<<"drink: "<<ptr->drink<<endl;
			cout<<"....................."<<endl;
			ptr = ptr->next;
		}
 
	}

}	

// search for drink using key(name)

void hash :: search_drink(string name)
{
	int index = Hash(name);
	string drink;
	bool found = false;	
	
	item* ptr = hash_table[index];

	while(ptr != NULL)
	{
		if(ptr->name == name)
		{
			found = true;
			drink = ptr->drink;
			break;
		}
		ptr = ptr->next;
	}	
	if(found == true)
	{
		cout<<"fav drink: "<<drink<<endl;
		cout<<"...................."<<endl;
	}
	else
	{
		cout<<"incorrect search"<<endl;
		cout<<".........................."<<endl;
	}	

}

// removing items

void hash :: remove_item(string name)
{
	int index = Hash(name);

	// empty case....
	
	if(hash_table[index]->name == "empty")
	{	
		cout<<"no match found..........."<<endl;
		return;
	}	

	// only 1 item and that is matched 

	else if(hash_table[index]->name == name && hash_table[index]->next == NULL)
	{
		hash_table[index]->name = "empty";
		hash_table[index]->drink = "empty";
		cout<<"deleted........"<<endl;
		return;
	}	

	//	more than 1 item and first item is matched 

	else if(hash_table[index]->name == name && hash_table[index]->next != NULL)
	{
		item* delptr = hash_table[index];
		hash_table[index] = hash_table[index]->next;
		delete delptr; 
		cout<<"deleted........"<<endl;
		return;
	}

	// more than 1 item but first item is not matched 

	else
	{
		item* p2 = hash_table[index];
		item* p1 = hash_table[index]->next;
		
		while(p1 != NULL && p1->name != name)
		{
			p2 = p1;
			p1 = p1->next;
		}	

	// no match
	
		if(p1 == NULL )
		{
			cout<<"no match...."<<endl;
			return;
		}

	// match

		else
		{
			p2->next = p1->next;
			delete p1;
			cout<<"deleted........"<<endl;
		}		

	}

}









