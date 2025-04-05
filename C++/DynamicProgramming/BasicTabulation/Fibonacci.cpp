#include <bits/stc++.h>
using namespace std;

void f(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    cout << dp[0] << " " << dp[1] << " ";

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    f(n, dp);
}