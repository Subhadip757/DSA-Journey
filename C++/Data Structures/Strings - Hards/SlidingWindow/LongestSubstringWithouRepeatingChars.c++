#include <bits/stc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    vector<bool> arr(256, 0);
    int first = 0;
    int second = 0;
    int n = s.length();

    while (second < n)
    {
        if (arr[s[second]] == 0)
        {
            arr[s[second]] = 1;
            second++;
        }
        else
        {
            arr[s[first]] = 0;
            first++;
        }
        len = max(len, second - first);
    }

    return len;
}

int main()
{
    string str = "abcabcbb";
    cout << "Longest -> " << lengthOfLongestSubstring(str);
}