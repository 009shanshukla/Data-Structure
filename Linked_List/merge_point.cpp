#include<bits/stdc++.h>
using namespace std;
//creating node entity
struct node
{
	int data;
	node* link;
};

int length_list(node* head)
{
	int l = 0;
	node* temp = head;
	while(temp != NULL)
	{
		l++;
		temp = temp->link;
	}
	return l;
}


node* merge(node* head1, node* head2)
{
	int len1 = length_list(head1);
	int len2 = length_list(head2);

	node* temp1 = head1;
	node* temp2 = head2; 

	set< node* > address;

	for(int i = 0; i < len2; i++) // push all adresses of second linked list
	{
		address.insert(temp2);
		temp2 = temp2->link;
	}	

	for(int i = 0; i < len1; i++) // parse first linked list
	{
		if(address.find(temp1) != address.end())       // if  common address is not last address
			return temp1;                               // return it

		temp1 = temp1->link;
	}
	return NULL;
}



int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp[7];
    for(int i=0;i<7;i++) {
        temp[i] = (node *)malloc(sizeof(node));
    }
    temp[0]->data = 4;
    temp[0]->link = temp[1];
    temp[1]->data = 6;
    temp[1]->link = temp[2];
    temp[2]->data = 7;
    temp[2]->link = temp[3];
    temp[3]->data = 1;
    temp[3]->link = NULL;
    temp[4]->data = 9;
    temp[4]->link = temp[5];
    temp[5]->data = 3;
    temp[5]->link = temp[6];
    temp[6]->data = 5;
    temp[6]->link = temp[2];      // clearly merge point is 7 


    head1 = temp[0];       // first linked list
	head2 = temp[4];        // second linked list

	node* merge_point = merge(head1, head2);

	if(merge_point != NULL)
		cout<<"merge point data: "<<merge_point->data<<endl;

	else
		cout<<"no merge point"<<endl;

	return 0;
}
