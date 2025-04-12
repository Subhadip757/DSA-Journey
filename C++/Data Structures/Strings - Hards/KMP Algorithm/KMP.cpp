#include <bits/stdc++.h>
using namespace std;

int kmp(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);
    int prefix = 0, suffix = 1;

    while (suffix < n)
    {
        if (s[prefix] == s[suffix])
        {
            lps[suffix] = prefix + 1;
            prefix++;
            suffix++;
        }
        else
        {
            if (prefix == 0)
            {
                lps[suffix] = 0;
                suffix++;
            }
            else
            {
                prefix = lps[prefix - 1];
            }
        }
    }
    return lps[s.length() - 1];
}

int main()
{
    string str = "aabcdaabc";
    cout << "Longest :-> " << kmp(str);
}