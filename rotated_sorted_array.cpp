#include<bits/stdc++.h>
using namespace std;

    int getPivot(vector<int>& arr,int n){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while (s<e){
            if(arr[mid] >= arr[0])
            {
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int>& arr,int start,int end,int key)
    {
        int s = start;
        int e = end;
        int mid = s + (e - s)/2;

        while(s <= e){
            if(arr[mid] == key){
                return mid;
            }

            if(key > arr[mid]){
                s = mid+1;
            }else{
                e = mid -1;
            }

            mid = s + (e - s)/2;
        }

        return -1;

    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = getPivot(nums,n);

        if(target >= nums[pivot] && target <= nums[n-1]){
            cout<< binarySearch(nums,pivot,n-1,target);
        }else{
            cout<< binarySearch(nums,0,pivot-1,target);
        }

        return 0;

    }


    int main(){
        #ifndef ONLINE_JUDGE
        freopen("./input.txt","r",stdin);
        freopen("./output.txt","w",stdout);
        #endif
        vector<int> nums;
        for (int i = 0; i < 6; ++i)
        {
            int a;
            cin >> a;
            nums.push_back(a);
        }
     
        int k;
        cin >> k;


        search(nums,k);
    }
