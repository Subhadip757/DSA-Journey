#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int dice = 1; dice <= 6; dice++){
            if(i - dice >= 0){
                dp[i] = (dp[i] + dp[i - dice]) % m;
            }
        }
    }

    cout<<dp[n];
    return 0;
}