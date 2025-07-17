#include<bits/stdc++.h>
#include<numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % 2 != 0) return false;

    sum /= 2;

    vector<vector<bool>> dp(n, vector<bool> (sum + 1, false));

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    if(nums[0] <= sum){
        dp[0][nums[0]] = true;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            bool notTake = dp[i - 1][j];
            bool take = false;

            if(nums[i] <= j){
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = take || notTake;
        }
    }

    return dp[n - 1][sum];
}

int main(){
    vector<int> arr = {1, 2, 3};
    if(canPartition(arr)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}