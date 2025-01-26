#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& arr, int n){
	for (int i = 1; i < n; ++i)
	{
		bool swapped = false;

		for (int j = 0; j < n - i; ++j)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped =true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}

int main(){
	vector<int> arr = {1,53,35,322,567,321,456,321,345,34,13,57,12};

	int n = arr.size();

	bubbleSort(arr,n);

    for (int i = 0; i < n; ++i) 
    {
	    cout<<arr[i]<<" ";
    }

}