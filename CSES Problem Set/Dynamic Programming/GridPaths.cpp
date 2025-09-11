#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 1e9 + 7;

int paths(int n, int m,  vector<vector<char> > &str, vector<vector<int> > &dp){
    if(n < 0 || m < 0) return 0;
    if(n == 0 && m == 0) return 1;
    if(str[n][m] == '*') return 0;
    if(dp[n][m] != -1) return dp[n][m];

    return dp[n][m] = (paths(n - 1, m, str, dp) + paths(n, m - 1, str, dp)) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<char> > str(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>str[i][j];
        }
    }

    if (str[0][0] == '*' || str[n-1][n-1] == '*') {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int> > dp(n, vector<int>(n, -1));

    cout<<paths(n - 1, n - 1, str, dp)<<endl;

    return 0;
}