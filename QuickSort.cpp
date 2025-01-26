#include<bits/stdc++.h>

using namespace std;


//Time complexity O(N^2)
//Average Case O(NlogN) 

void quickSort(int a[], int start, int end){

	if(start >= end ) return ;
	int pivot = end;

	int i = start - 1;
	int j = start;

	while(j < pivot){
		if(a[j] < a[pivot]){
			++i;
			swap(a[i],a[j]);
		}
		++j;
	}
	++i;

	swap(a[pivot],a[i]);

	quickSort(a ,start , i - 1);
	quickSort(a ,i + 1, end);
}


int main(){
	int a[] = {7,2,1,8,6,3,5,4};

	quickSort(a, 0, 7);

	for(auto i:a){
		cout << i << " ";
	}

	return 0;
}