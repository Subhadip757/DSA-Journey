#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int wordCombinations(int idx, string s, string out, vector<string> &words, int k, vector<vector<int>> &dp){
    if(out.size() > s.size()) return 0;
    if(s == out) return 1;

    if(idx == k) return out == s;
    if(dp[idx][k] != -1) return dp[idx][k];

    int left = wordCombinations(idx, s, out + words[idx], words, k, dp);
    int right = wordCombinations(idx + 1, s, out, words, k, dp);

    return dp[idx][k] = (left + right) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int k;
    cin>>k;

    vector<string> words(k);

    for(int i = 0; i < k; i++){
        cin>>words[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(s.size() + 1, -1));

    cout<<wordCombinations(0, s, "", words, k, dp) - 1;

    return 0;
}