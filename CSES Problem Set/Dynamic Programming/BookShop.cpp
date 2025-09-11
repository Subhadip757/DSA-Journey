#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int solve(int n, int am, vector<int> &books, vector<int> &pages, vector<vector<int>> &dp){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= am; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= am; j++){
            if(books[i - 1] <= j){
                dp[i][j] = max(pages[i - 1] + dp[i - 1][j - books[i - 1]], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][am];
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin>>n>>x;

    vector<int> books(n), pages(n);

    for(int i = 0; i < n; i++){
        cin>>books[i];
    }
    for(int i = 0; i < n; i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

    cout<<solve(n, x, books, pages, dp);

    return 0;
}