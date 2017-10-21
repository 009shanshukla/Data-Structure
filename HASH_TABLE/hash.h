#include<bits/stdc++.h>
using namespace std;

#ifndef HASH_H
#define HASH_H


class hash
{
	private:
			static const int table_size = 10;

			struct item 
			{
				string name;
				string drink;
				item* next;	
			};
			
			item* hash_table[table_size]; 	
	
	public:
			hash();
			int Hash(string key);
			void add_item(string name, string drink);
			int number_of_items_in_index(int index);
			void print_table();
			void print_items_in_index(int index);
			void search_drink(string name);
			void remove_item(string name);
};


#endif
