#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& arr,int n){
	for (int i = 0; i < n-1; ++i)
	{
		int minIndex = i;

		for (int j = i+1; j < n; ++j)
		{
			if (arr[j]<arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex],arr[i]);
	}

	for (int k = 0; k < n; ++k)
	{
		cout<<arr[k]<<" ";
	}
}

int main(){
	vector<int> arr = {1,3,6,3,4,5};
	int n = 6;
	selectionSort(arr,n);
}