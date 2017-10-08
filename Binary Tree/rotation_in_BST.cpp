#include<bits/stdc++.h>
using namespace std;

int pivot(int* arr, int start, int end, int size)
{

	while(start <= end)           // do binary search
	{
		if(arr[start] <= arr[end])        // if this condition follows it means , array is already sorted
			return start;

		int mid = start + (end - start)/2;      

		if(arr[mid] <= arr[(mid+1)%size] && arr[mid] <= arr[(mid+size-1)%size])         // condition for pivot element
			return mid;

		else if(arr[mid] >= arr[start])          // it means right side is for smaller elements
		{
			start = mid+1;
		}	
		else if(arr[mid] <= arr[end])           // it means left side is for smaller elements
		{
			end = mid-1;
		}
	}
	return -1;	

}

int main()
{
	int arr[9] = {6,7,8,9,1,2,3,4,5};
	
	int index = pivot(arr, 0, 8, 9);      // pivot index is that who has left side lesser and right side greater
     
	if(index == -1)
		cout<<"invalid"<<endl;
	else
		cout<<index<<endl;

}
