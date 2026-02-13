#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    cout<<(dp[k] == INF ? -1 : dp[k]);

    return 0;
}