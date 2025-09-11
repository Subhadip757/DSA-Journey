#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &arr, vector<int> &dp){
    if(n == 0) return 0;
    if(n < 0) return 1e9;
    if(dp[n] != -1) return dp[n];

    int ans = 1e9;
    for(int coin : arr){
        ans = min(ans, 1 + solve(n - coin, arr, dp));
    }

    return dp[n] = ans;
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    vector<int> dp(target + 1, -1);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int ans = solve(target, arr, dp);
    if(ans == 1e9) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}