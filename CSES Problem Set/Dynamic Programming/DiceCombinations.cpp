#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m = 1e9 + 7;

int solve(int n, vector<int> &dp){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    ll ans = 0;
    for(int dice = 1; dice <= 6; dice++){
        ans = (ans + solve(n - dice, dp)) % m;
    }

    return dp[n] = ans;
}

int main(){
    int n; cin>>n;
    vector<int> dp(n + 1, -1);

    cout<<solve(n, dp);
    
    return 0;
}