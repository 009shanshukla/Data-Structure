#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int val, int low, int high, int size)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;

		if(arr[mid] == val)     // element found
			return mid;

		if(arr[mid] <= arr[high])      // right array is sorted
		{
			if(val > arr[mid]  && val <= arr[high])    // element is on right side
				low = mid+1;
		
			else           // otherwise on left side
				high = mid-1;
		}
		if(arr[mid] >= arr[low])        // left array is sorted
		{
			if(val < arr[mid]  && val >= arr[low])        // element is on left side
				high = mid-1;
		
			else                  // otherwise on right side
				low = mid+1;
		}
	}
	return -1;

}

int main()
{
	int arr[9] = {6,7,8,9,1,2,3,4,5};
	
	int index = search(arr, 3, 0, 8, 9);   // search element 3

	if(index == -1)
		cout<<"invalid"<<endl;
	else
		cout<<index<<endl;

}
