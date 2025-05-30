// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, ans that you are given the "true" length of the string

// Example
// input: "Mr John Smith", 13
// Output: "Mr%20John%20Smith"

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string urlify(string &str, int size)
    {
        string result;
        for (char ch : str)
        {
            if (ch == ' ')
            {
                result += "%20";
            }
            else{
                result += ch;
            }
        }
        return result;
    }
};

int main()
{
    string str = "Mr John Smith";
    int size = 13;
    Solution sol;

    string ans = sol.urlify(str, size);
    cout << ans;

    return 0;
}