#include<bits/stdc++.h>

using namespace std;


 int getFirstOccurence(vector<int>& nums,int target){
        int s = 0;
        int e = nums.size()-1;

        int ans = -1;

        // if(nums.empty()){
        //     return -1;
        // }
        // if(e == 1){
        //     if(nums[0] == target){
        //         return 0;
        //     }else{
        //         return -1;
        //     }
        // }

        while(s<=e){
          int mid = s+(e-s)/2;

            if(nums[mid] < target){
                s = mid + 1;
            }else if(nums[mid] > target){
                e = mid -1;
            }else{
                ans = mid;
                e = mid -1;
            }

        }
        return ans;
    }


 int getLastOccurence(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        

        int ans = -1;

        // if(nums.empty()){
        //     return -1;
        // }
        // if(e == 1){
        //     if(nums[0] == target){
        //         return 0;
        //     }else{
        //         return -1;
        //     }
        // }

        while(s<=e){
           
           if(nums[mid] < target){
                s = mid + 1;
            }else if(nums[mid] > target){
                e = mid -1;
            }else{
                ans = mid;
                s = mid+1;
            }

            mid = s+(e-s)/2;
        }
        return ans;
    }
    int main() {

        vector<int> nums = {2,2};
        int target = 2;

        int n = nums.size();

        int firstOccurence = getFirstOccurence(nums,target);
        int lastOccurence = getLastOccurence(nums,target);

        vector<int> result = {-1,-1};
        result[0] = firstOccurence;
        result[1] = lastOccurence;

        cout<<result[0]<<" "<<result[1]<<endl;
        return 0;

        
    }