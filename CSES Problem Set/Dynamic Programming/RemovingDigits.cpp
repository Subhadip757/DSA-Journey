#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(char c : s){
            int dig = c - '0';
            if(dig != 0){
                dp[i] = min(dp[i], dp[i - dig] + 1);
            }
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}