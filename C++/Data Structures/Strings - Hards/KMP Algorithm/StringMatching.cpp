#include <bits/stc++.h>
using namespace std;

void lpsFind(vector<int> &lps, string &s)
{
    int prefix = 0, suffix = 1;

    while (suffix < s.size())
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
}

int strStr(string s1, string s2)
{
    vector<int> lps(s2.size(), 0);
    lpsFind(lps, s2);

    int first = 0, second = 0;
    while (first < s1.size())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
        if (second == s2.size())
        {
            return first - second;
        }
    }
    return -1;
}