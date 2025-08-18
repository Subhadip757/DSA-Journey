#include<bits/stdc++.h>
using namespace std;

int maxValue(vector<int> &wei, vector<int> &val, int w, int n, vector<vector<int>> &dp){
    if(n == 0 || w == 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(wei[n - 1] <= w){
        return dp[n][w] = max(val[n - 1] + maxValue(wei, val, w - wei[n - 1], n - 1, dp), maxValue(wei, val, w, n - 1, dp));
    }
    else {
        return dp[n][w] = maxValue(wei, val, w, n - 1, dp);
    }
}
int main(){
    vector<int> wei = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int w = 7;

    int n = wei.size();
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));


    cout<<"Max Value: "<<maxValue(wei, val, w, n, dp);
}