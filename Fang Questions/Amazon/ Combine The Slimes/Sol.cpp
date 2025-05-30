#include <vector>
#include <climits>
using namespace std;

int minCost(int n, vector<int> &slimes)
{
    if (n == 1)
        return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> sum(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        sum[i][i] = slimes[i];
        for (int j = i + 1; j < n; ++j)
        {
            sum[i][j] = (sum[i][j - 1] + slimes[j]) % 100;
        }
    }

    for (int length = 2; length <= n; ++length)
    {
        for (int i = 0; i <= n - length; ++i)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k + 1][j] + sum[i][k] * sum[k + 1][j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}
