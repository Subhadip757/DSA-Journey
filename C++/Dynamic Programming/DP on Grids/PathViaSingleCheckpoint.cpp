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

// For sums: simply compute minPathSum(start->cp) + minPathSum(cp->end)
// For counts: multiply ways (taking care of obstacles)
long long minPathViaCheckpoint(const vector<vector<int>> &grid, pair<int, int> cp)
{
    int n = grid.size();
    int m = grid[0].size();
    // compute min from (0,0) to cp
    int x = cp.first, y = cp.second;
    vector<vector<int>> sub(x + 1, vector<int>(y + 1));
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            sub[i][j] = grid[i][j];
    long long a = minPathSum(sub);
    // compute min from cp to end: create grid of size (n-x) x (m-y)
    vector<vector<int>> sub2(n - x, vector<int>(m - y));
    for (int i = x; i < n; i++)
        for (int j = y; j < m; j++)
            sub2[i - x][j - y] = grid[i][j];
    long long b = minPathSum(sub2);
    return a + b - grid[x][y]; // cp counted twice, so subtract once
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    pair<int, int> cp = {1, 1}; // checkpoint at (row=1,col=1)

    cout << "Grid:\n";
    for (auto &row : grid) {
        for (auto &v : row) cout << v << " ";
        cout << "\n";
    }

    cout << "Min path sum from (0,0) to (n-1,m-1): " << minPathSum(grid) << "\n";
    cout << "Min path sum via checkpoint (1,1): " << minPathViaCheckpoint(grid, cp) << "\n";

    return 0;
}