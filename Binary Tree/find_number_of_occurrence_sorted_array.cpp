#include<bits/stdc++.h>
using namespace std;

int occurence(int* arr, int last_index, int val, char c)
{
	int low = 0;
	int high = last_index;
	int result = -1;

	while(low <= high)
	{
		int mid = low + (high - low)/2;

		if(arr[mid] == val) // if number is found
		{
			result = mid;
			if(c == 'f')      // for first occurence check for it again on left side
				high = mid-1;
			else if(c == 'l')  // for last occurence check it for on right side
				low = mid+1;
			else
				return -1;
		}

		else if(arr[mid] > val)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return result;

}

int main()
{
	int arr[9] = {1,1,5,5,5,6,6,9,13};
	int first = occurence(arr, 8, 5,'f');
	int last = occurence(arr, 8, 5,'l');
	if(first == last && first == -1)
		cout<<"result not found";

	else
		cout<<last-first+1<<endl;

}
