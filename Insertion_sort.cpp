#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& arr,int n){
    for (size_t i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                //shift
                arr[j+1] = arr[j];
            }
            else //ruk jao
            {
                break;
            }
            
        }
        arr[j+1] = temp;

    }
    
}

int main(){

    vector<int> arr = {2,5,7,4,2,57,234,4,6,2};
    int n = arr.size();

    insertionSort(arr,n);

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

}