#include<bits/stdc++.h>
using namespace std;
int arr[100][100];

void spiral(int row, int column)
{
	int dir = 0;
	int top = 0;
	int bottom = row-1;
	int left = 0;
	int right = column-1;

	while(left <= right && top <= bottom)
	{
		if(dir == 0)
		{
			for(int i = left; i <= right; i++)
				cout<<arr[top][i]<<" ";
			cout<<endl;
			
			top++;
			dir = 1;
		}

		else if(dir == 1)
		{
			for(int i = top; i <= bottom; i++)
				cout<<arr[i][right]<<" ";	
			cout<<endl;
		
			right--;
			dir = 2;
		}

		else if(dir == 2)
		{
			for(int i = right; i >= left; i--)
				cout<<arr[bottom][i]<<" ";	
			cout<<endl;
		
			bottom--;
			dir = 3;			
		}	

		else if(dir == 3)
		{
			for(int i = bottom; i >= top; i--)
				cout<<arr[i][left]<<" ";	
			cout<<endl;
		
			left++;
			dir = 0;
		}
	}
}



int main()
{
	int row, column;
	cout<<"enter row: ";
	cin>>row;
	cout<<"enter column: ";
	cin>>column;

	cout<<"enter matrix:"<<endl;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			cin>>arr[i][j];

	spiral(row, column);

	return 0;
}
