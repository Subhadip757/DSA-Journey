#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MCM(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i = n - 2; i >= 0; i--){
        for(int j = i; j <= n - 2; j++){
            if(i >= j){
                dp[i][j] = 0;
                continue;
            }
            int minCost = INT_MAX;

            for(int k = i; k < j; k++){
                int x = arr[i] * arr[k + 1] * arr[j + 1];
                int tc = dp[i][k] + dp[k + 1][j] + x;
                minCost = min(tc, minCost);
            }

            dp[i][j] = minCost;
        }
    }

    return dp[0][n - 2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4};
    cout<<MCM(arr);

    return 0;
}