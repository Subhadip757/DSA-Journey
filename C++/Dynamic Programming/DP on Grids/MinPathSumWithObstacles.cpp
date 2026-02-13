#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INFLL = (1LL << 60);
const int INF = 1e9;

long long minPathSumWithObstacles(const vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;

    int m = grid[0].size();
    vector<long long> dp(m, INFLL);

    if (grid[0][0] != INT_MAX)
        dp[0] = grid[0][0]; // INT_MAX used as obstacle sentinel
        
    for (int j = 1; j < m; j++)
    {
        if (grid[0][j] == INT_MAX)
            dp[j] = INFLL;
        else if (dp[j - 1] != INFLL)
            dp[j] = dp[j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == INT_MAX)
            dp[0] = INFLL;
        else if (dp[0] != INFLL)
            dp[0] += grid[i][0];
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == INT_MAX)
                dp[j] = INFLL;
            else
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
        }
    }

    return dp[m - 1] >= INFLL ? -1 : dp[m - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // Min path with obstacles: use INT_MAX as obstacle sentinel
    vector<vector<int>> gridObs = {
        {1, 1, 1},
        {1, INT_MAX, 1},
        {1, 1, 1}};
    cout << "3) Min Path Sum With Obstacles: " << minPathSumWithObstacles(gridObs) << '\n';

    return 0;
}