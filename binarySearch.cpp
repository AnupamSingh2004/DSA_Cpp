#include<bits/stdc++.h>

using namespace std;


  int binarySearch(vector<int>& arr,int size){

        int start = 0;
        int end = size -1;
        int mid = start + (end-start)/2;

        while (start<end)
        {
            if (arr[mid] >= arr[0])
            {
                start = mid+1;
            }
            else{
                end = mid;
            }

            mid = start + (end-start)/2;
            
        }
        if (start == size-1 && size != 2)
        {
            return arr[0];
        }else{
        return arr[start];

        }
        
        
    }

    int main(){

        vector<int> arr = {2,3,1};

        int answer = binarySearch(arr,arr.size());
        cout<<answer<<endl;
        
    }