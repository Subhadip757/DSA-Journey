#include <bits/stdc++.h>
using namespace std;

bool match(string s1, string s2)
{
    string res = s1 + s1;

    int k = s2.length();
    string word = "";

    for (int i = 0; i < k ; i++)
    {
        word += res[i];
    }

    if (word == s2)
    {
        return true;
    }

    for (int i = k; i < res.length(); i++)
    {
        word.erase(word.begin());
        
        word += res[i];

        if (word == s2)
        {
            return true;
        }

    }
    return false;
}

int main()
{
    string s1 = "abcde";
    string s2 = "deab";

    if (match(s1, s2))
    {
        cout << "Matched";
    }
    else
    {
        cout << "Not matched";
    }

    return 0;
}