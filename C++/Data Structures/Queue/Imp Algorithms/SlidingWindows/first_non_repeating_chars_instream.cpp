#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string solve(string A)
{
    queue<char> q;
    string ans;
    vector<int> arr(26, 0);

    for (char ch : A)
    {
        arr[ch - 'a']++;

        q.push(ch);
        while (!q.empty() && arr[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        ans += q.empty() ? '#' : q.front();
    }
    return ans;
}