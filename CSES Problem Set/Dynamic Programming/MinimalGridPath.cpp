#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<char>> arr(n, vector<char>(n, '.'));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<string>> dp(n, vector<string>(n, ""));
    dp[0][0] = string(1, arr[0][0]);
    
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    for(int i = 1; i < n; i++){
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(dp[i - 1][j] < dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else{
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1]<< "\n";
    return 0;
}