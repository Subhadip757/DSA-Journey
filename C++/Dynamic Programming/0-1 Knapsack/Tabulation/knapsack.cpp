#include<bits/stdc++.h>
using namespace std;

int maxValue(vector<int> &wei, vector<int> &val, int w, int n, vector<vector<int>> &dp){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < w; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(wei[i - 1] <= j){
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wei[i - 1]], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}
int main(){
    vector<int> wei = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int w = 7;

    int n = wei.size();
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));


    cout<<"Max Value: "<<maxValue(wei, val, w, n, dp);
}