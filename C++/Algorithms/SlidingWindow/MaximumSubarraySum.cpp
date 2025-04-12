#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr, int k)
{
    int left = 0;
    int sum = 0;

    int maxi = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    maxi = sum;

    for (int right = k; right < arr.size(); right++)
    {
        sum -= arr[left];
        left++;
        sum += arr[right];

        maxi = max(sum, maxi);
    }

    return maxi;
}

int main()
{
    vector<int> arr = {2, 1, -1, 3, 4, -2, 6, 5};
    int k = 3;
    cout << maxSum(arr, k);
    return 0;
}