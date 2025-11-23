#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(string s, vector<int> &lps){
    int prefix = 0, suffix = 1;

    while(suffix < s.size()){
        if(s[prefix] == s[suffix]){
            lps[suffix] = prefix + 1;
            prefix++;
            suffix++;
        }
        else{
            if(prefix == 0){
                lps[suffix] = 0;
                suffix++;
            }
            else{
                prefix = lps[prefix - 1];
            }
        }
    }
}

int kmp(string s1, string s2){
    vector<int> lps(s2.size());
    solve(s2, lps);
    int first = 0, second = 0;

    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            if(second == 0){
                first++;
            }
            else{
                second = lps[second - 1];
            }
        }
        if(second == s2.size()){
            return first - second;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text = "abxabcabcaby";
    string pattern = "abcaby";

    int index = kmp(text, pattern);
    if (index != -1)
        cout << "Pattern found at index: " << index << "\n";
    else
        cout << "Pattern not found\n";

    return 0;
}