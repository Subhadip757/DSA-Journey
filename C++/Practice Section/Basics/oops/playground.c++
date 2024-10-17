#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            ans = mid;
            end = mid - 1;  
        }
        else if(nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;  
}

int last(vector<int> &nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            ans = mid;
            start = mid + 1;  
        }
        else if(nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;  
}

vector<int> searchRange(vector<int>& nums, int target) {
    int firstIndex = first(nums, target);
    int lastIndex = last(nums, target);

    return {firstIndex, lastIndex}; 
}

int main(){
    vector<int> nums = {1, 3, 5, 8, 8, 10}; 
    int target = 8;

    vector<int> result = searchRange(nums, target);  
    cout << "First Occurrence: " << result[0] << "\n";
    cout << "Last Occurrence: " << result[1] << "\n";  
}
