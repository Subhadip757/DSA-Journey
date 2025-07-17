#include<bits/stdc++.h>
#include<numeric>
using namespace std;

bool solve(int n, int sum, vector<int> &nums, vector<vector<int>> &dp){
    if(n == 0){
        if(sum == 0) return true;
        return nums[0] == sum;
    }

    if(dp[n][sum] != -1) return dp[n][sum];

    if(nums[n] <= sum){
        return dp[n][sum] = solve(n - 1, sum - nums[n], nums, dp) || solve(n - 1, sum, nums, dp);
    }
    else{
        return dp[n][sum] = solve(n - 1, sum, nums, dp);
    }
}

bool partition(vector<int> &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if(sum % 2 != 0) return false;
    sum /= 2;

    vector<vector<int>> dp(n, vector<int> (sum, -1));

    return solve(n, sum, arr, dp);
}

int main(){
    vector<int> arr = {1, 5, 11, 5};
    if(partition(arr)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}