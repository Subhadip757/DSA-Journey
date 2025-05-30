// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit [or Zero edits] away.

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
        int n = s1.length();
        int m = s2.length();

        if(abs(n - m) > 1) return false;

        string ns1 = s1.length() < s2.length() ? s1 : s2;
        string ns2 = s1.length() < s2.length() ? s2 : s1;

        int idx1 = 0;
        int idx2 = 0;

        bool foundDifference = false;

        while(idx2 < s2.length() && idx1 < s1.length()){
            if(ns1[idx1] != ns2[idx2]){
                if(foundDifference) return false;

                foundDifference = true;

                if(ns1.length() == ns2.length()) idx1++;
            }
            else{
                idx1++;
            }
            idx2++;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s1 = "pale", s2 = "bae";

    sol.away(s1, s2) ? cout<<"True" : cout<<"False";
    return 0;
}