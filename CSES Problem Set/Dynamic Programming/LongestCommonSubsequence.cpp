#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(vector<int> &arr1, vector<int> &arr2, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr1[i - 1] == arr2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    vector<int> ans;

    while(i > 0 && j > 0){
        if(arr1[i - 1] == arr2[j - 1]){
            ans.push_back(arr1[i - 1]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<int> arr1(n), arr2(m);

    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }

    for(int i = 0; i < m; i++){
        cin>>arr2[i];
    }

    vector<int> ans = solve(arr1, arr2, n, m);
    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(int it : ans){
        cout<<it<<" ";
    }

    return 0;
}