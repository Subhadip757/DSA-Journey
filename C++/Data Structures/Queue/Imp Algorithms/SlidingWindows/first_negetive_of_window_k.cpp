#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> firstNegInt(vector<int> &arr, int k)
{
    // write code here
    queue<int> q;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
            q.push(i);
    }

    for (int i = k - 1; i < n; i++)
    {
        if (arr[i] < 0)
            q.push(i);

        while (!q.empty() && q.front() < i - k + 1)
        {
            q.pop();
        }
        res.push_back(q.empty() ? 0 : arr[q.front()]);
    }
    return res;
}