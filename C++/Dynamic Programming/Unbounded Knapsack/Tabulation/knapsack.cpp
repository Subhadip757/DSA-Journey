#include<bits/stdc++.h>
using namespace std;

int unbound(vector<int> &wt, vector<int> &val, int w){
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(wt[i - 1] <= j){
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
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
    int w = 8;

    int ans = unbound(wei, val, w);
    cout<<"Max Value: "<<ans;
}