#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return 0;
        }

        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n - 1] == s2[m - 1]){
            return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);
        }
        else{
            return dp[n][m] = max(solve(s1, s2, n - 1, m, dp), solve(s1, s2, n, m - 1, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int ans = solve(text1, text2, n, m, dp);

        return ans;
    }
};

int main(){
    string s1 = "abcde", s2 = "ace";
    Solution sol;
    int ans = sol.longestCommonSubsequence(s1, s2);
    cout<<"The longest common subsequence is: "<<ans<<endl;
}