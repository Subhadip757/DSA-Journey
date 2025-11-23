#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INFLL = (1LL << 60);
const int INF = 1e9;

long long minPathSum(const vector<vector<int>> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int m = a[0].size();
    vector<long long> dp(m, INFLL);
    
    dp[0] = a[0][0];
    for (int j = 1; j < m; j++)
        dp[j] = dp[j - 1] + a[0][j];
    for (int i = 1; i < n; i++)
    {
        dp[0] += a[i][0];
        for (int j = 1; j < m; j++)
        {
            dp[j] = a[i][j] + min(dp[j], dp[j - 1]);
        }
    }
    return dp[m - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {1, 3, 1, 2},
        {1, 5, 1, 1},
        {4, 2, 1, 3},
        {2, 1, 2, 1}};
    cout << "1) Min Path Sum (right & down): " << minPathSum(grid) << '\n';

    return 0;
}