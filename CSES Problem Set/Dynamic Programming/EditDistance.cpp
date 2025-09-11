#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[n][m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;

    cin>>s1>>s2;

    int ans = solve(s1, s2);
    cout<<ans;
    return 0;
}