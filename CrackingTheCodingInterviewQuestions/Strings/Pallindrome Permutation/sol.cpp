// Given a string. write a function to check if it is a permutation of a pallindrome. A pallindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words

// Example:
// Input: "Tact Coa"
// Output: True

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool pali(string str){
        vector<int> vis(128, 0);
        for(char ch : str){
            if(ch == ' ') continue;
            char temp = tolower(ch);
            vis[int(temp)]++;
        }

        int oddCount = 0;

        for(int i = 0; i < 128; i++){
            if(vis[i] % 2 != 0){
                oddCount++;
            }
            if(oddCount > 1) return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string str = "Tact Coa";

    if(sol.pali(str)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}