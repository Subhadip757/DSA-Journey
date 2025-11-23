#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long maxFallingPathSum(const vector<vector<int>> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int m = a[0].size();
    vector<long long> dp(m, LLONG_MIN / 4);
    for (int j = 0; j < m; j++)
        dp[j] = a[0][j];
    for (int i = 1; i < n; i++)
    {
        vector<long long> ndp(m, LLONG_MIN / 4);
        for (int j = 0; j < m; j++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int pj = j + dj;
                if (pj >= 0 && pj < m)
                    ndp[j] = max(ndp[j], dp[pj] + a[i][j]);
            }
        }
        dp.swap(ndp);
    }
    long long ans = LLONG_MIN / 4;
    for (long long v : dp)
        ans = max(ans, v);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // Maximum falling path sum
    vector<vector<int>> fall = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};
    cout << "6) Max Falling Path Sum: " << maxFallingPathSum(fall) << '\n';

    return 0;
}