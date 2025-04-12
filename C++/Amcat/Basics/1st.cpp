#include <bits/stc++.h>
using namespace std;

int main()
{
    vector<int> arr = {9, 5, 6, 8, 1, 4, 10, 20, 7};
    vector<int> sol;
    vector<int> temp1;
    vector<int> temp2;
    int k;
    cin >> k;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        temp1.push_back(arr[i]);
    }

    sort(temp1.begin(), temp1.end());

    for (int i = k; i < n; i++)
    {
        temp2.push_back(arr[i]);
    }

    sort(temp2.rbegin(), temp2.rend());

    for (int i = 0; i < temp1.size(); i++)
    {
        sol.push_back(temp1[i]);
    }

    for (int i = 0; i < temp2.size(); i++)
    {
        sol.push_back(temp2[i]);
    }

    for (auto &it : sol)
    {
        cout << it << " ";
    }
}