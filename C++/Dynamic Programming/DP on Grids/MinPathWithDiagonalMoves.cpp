#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INFLL = (1LL << 60);
const int INF = 1e9;

long long minPathWithDiagonal(const vector<vector<int>> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int m = a[0].size();
    vector<vector<long long>> dp(2, vector<long long>(m, INFLL));
    dp[0][0] = a[0][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + a[0][j];
    for (int i = 1; i < n; i++)
    {
        int cur = i % 2, prv = 1 - cur;
        fill(dp[cur].begin(), dp[cur].end(), INFLL);
        dp[cur][0] = dp[prv][0] + a[i][0];
        for (int j = 1; j < m; j++)
        {
            dp[cur][j] = a[i][j] + min({dp[prv][j], dp[cur][j - 1], dp[prv][j - 1]});
        }
    }
    return dp[(n - 1) % 2][m - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {1, 3, 5},
        {2, 1, 2},
        {4, 3, 1}
    };

    cout << "Minimum path sum with diagonal: " << minPathWithDiagonal(grid) << '\n';

    return 0;
}