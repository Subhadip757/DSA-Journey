#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int result = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    result = max(result, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return result;
    }
};

int main(){
    string s1 = "ABCDGH", s2 = "ACDGHR";
    Solution sol;
    cout<<"Output: "<<sol.longestCommonSubstr(s1, s2);
}