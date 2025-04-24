#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    int K = 0;
    int n = words.size();

    vector<int> hashArr(26, 0);
    for (string i : words)
    {
        for (char ch : i)
        {
            hashArr[ch - 'a'] = 1;
        }
    }

    for (int i = 0; i < hashArr.size(); i++)
    {
        if (hashArr[i] == 1)
            K++;
    }

    cout << K;
}