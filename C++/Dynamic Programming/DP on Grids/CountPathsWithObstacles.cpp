#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// grid: 0 = free, 1 = obstacle
// dp[i][j] = (grid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1])
long long countPathsWithObstacles(const vector<vector<int>> &grid, long long MOD = 1000000007LL)
{
    int n = grid.size();
    if (n == 0)
        return 0;

    int m = grid[0].size();

    vector<long long> dp(m, 0);

    if (grid[0][0] == 0)
        dp[0] = 1;

    for (int j = 1; j < m; j++)
        if (grid[0][j] == 0)
            dp[j] = dp[j - 1];

    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == 1)
            dp[0] = 0;
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 1)
                dp[j] = 0;
            else
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    return dp[m - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // Obstacles example (0 free, 1 obstacle)
    vector<vector<int>> obs = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << "2) Count Paths with Obstacles (3x3): " << countPathsWithObstacles(obs) << '\n';

    return 0;
}