// There are three types of edits that can be performed on strings: insert a character, 
// remove a character, or replace a character. Given two strings,
// write a function to check if they are one edit [or Zero edits] away.

// Example
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bae -> false

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool away(string s1, string s2){
        vector<int> charArray(26, 0);


        for(int i = 0; i < s1.size(); i++){
            charArray[s1[i] - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            charArray[s2[i] - 'a']--;
        }

        int count = 0;

        for(int i = 0; i < 26; i++){
            count += abs(charArray[i]);
        }

        return count <= 2;
    }
};

int main()
{
    Solution sol;
    string s1 = "pale", s2 = "pae";

    sol.away(s1, s2) ? cout<<"True" : cout<<"False";
    return 0;
}