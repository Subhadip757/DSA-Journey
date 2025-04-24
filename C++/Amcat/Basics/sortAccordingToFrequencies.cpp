#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{
    vector<int> arr = {10, 20, 10, 20, 10, 20, 30, 40, 30};
    unordered_map<int, int> mpp;

    vector<pair<int, int>> res;

    int n = arr.size();

    // [{10, 3}, {20, 3}, {30, 2}, {40, 1}]

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        res.push_back({it.first, it.second});
    }

    sort(res.begin(), res.end(), comp);

    vector<int> ans;

    for (auto &it : res)
    {
        for (int i = 0; i < it.second; i++)
        {
            ans.push_back(it.first);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}