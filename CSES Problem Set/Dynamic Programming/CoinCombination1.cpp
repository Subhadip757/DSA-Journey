#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    vector<int> dp(target + 1, 0);
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        for(int coin : arr){
            if(i - coin >= 0){
                dp[i] += dp[i - coin] % m;
                if(dp[i] >= m) dp[i] -= m;
            }
        }
    }

    cout<<dp[target];

    return 0;
}