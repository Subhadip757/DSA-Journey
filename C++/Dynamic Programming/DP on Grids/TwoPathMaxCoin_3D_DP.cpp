#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Classic DP: two people start at (0,0) and move to (n-1,m-1) together in steps.
// Let k = i1+j1 = i2+j2 (number of steps taken). Then
// dp[k][i1][i2] = max over previous states + value collected at (i1,j1) and (i2,j2)
// Complexity O(n^3) for n x n grid, typical for n up to ~100 in contests.

long long maxCoinsTwoPersons(const vector<vector<int>> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int m = a[0].size();
    // assume square grid for simplicity; if not, adapt indices carefully.
    int N = max(n, m);
    // dp for step k (0..n+m-2), we keep a 2D array for i1 and i2
    int maxk = n + m - 2;
    // initialize with very small
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MIN / 4));
    dp[0][0] = a[0][0];
    for (int k = 1; k <= maxk; k++)
    {
        vector<vector<long long>> ndp(n, vector<long long>(n, LLONG_MIN / 4));
        for (int i1 = max(0, k - (m - 1)); i1 <= min(n - 1, k); i1++)
        {
            int j1 = k - i1;
            if (j1 < 0 || j1 >= m)
                continue;
            for (int i2 = max(0, k - (m - 1)); i2 <= min(n - 1, k); i2++)
            {
                int j2 = k - i2;
                if (j2 < 0 || j2 >= m)
                    continue;
                long long bestPrev = LLONG_MIN / 4;
                // four previous transitions
                // (i1-1,i2-1), (i1-1,i2), (i1,i2-1), (i1,i2)
                if (i1 > 0 && i2 > 0)
                    bestPrev = max(bestPrev, dp[i1 - 1][i2 - 1]);
                if (i1 > 0 && j2 > 0)
                    bestPrev = max(bestPrev, dp[i1 - 1][i2]);
                if (j1 > 0 && i2 > 0)
                    bestPrev = max(bestPrev, dp[i1][i2 - 1]);
                if (j1 > 0 && j2 > 0)
                    bestPrev = max(bestPrev, dp[i1][i2]);
                if (bestPrev <= LLONG_MIN / 8)
                    continue;
                long long add = 0;
                if (i1 == i2 && j1 == j2)
                    add = a[i1][j1];
                else
                    add = a[i1][j1] + a[i2][j2];
                ndp[i1][i2] = max(ndp[i1][i2], bestPrev + add);
            }
        }
        dp.swap(ndp);
    }
    return max(0LL, dp[n - 1][n - 1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Two-person max coin (square grid)
    vector<vector<int>> coins = {
        {1, 2, 3},
        {0, 1, 0},
        {2, 3, 4}};
    cout << "7) Max coins two persons: " << maxCoinsTwoPersons(coins) << '\n';

    return 0;
}