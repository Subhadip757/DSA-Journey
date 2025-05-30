// Given two strings write a method to decide if one is a permutation of the other.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // without sorting the strings
    bool permutation(string a, string b)
    {
        vector<int> temp(256, 0);
        for (int i = 0; i < a.size(); i++)
        {
            int idx = a[i] - 'a';
            temp[idx]++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            int idx = b[i] - 'a';
            temp[idx]--;

            if (temp[idx] < 0)
            {
                return false;
            }
        }
        return true;
    }

    // With Sorting the strings
    bool perm(string a, string b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }
};

int main()
{
    string a = "listen";
    string b = "silent";
    Solution sol;

    if (sol.perm(a, b))
    {
        cout << "\nIs Permutation!!\n";
    }
    else
    {
        cout << "\nNot a Permutation\n";
    }

    return 0;
}