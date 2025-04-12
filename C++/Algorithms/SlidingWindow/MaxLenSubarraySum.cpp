#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr, int sum)
{
    int csum = 0;
    int left = 0;
    int mlen = INT_MIN;

    for (int right = 0; right < arr.size(); right++)
    {
        csum += arr[right];

        if (csum > sum)
        {
            csum -= arr[left++];
        }
        if (csum == sum)
        {
            mlen = right - left + 1;
        }
    }
    return mlen;
}

int minLen(vector<int> &arr)
{
    int csum = 0;
    int minSum = INT_MAX;
    int left = 0;
    int mlen = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        csum += arr[right];

        if (csum < minSum)
        {
            minSum = csum;
        }
        else if (csum > minSum)
        {
            csum -= arr[left++];
        }
        mlen = right - left + 1;
    }
    return mlen;
}

int main()
{
    vector<int> arr = {2, 1, -1, 3, 4, -2, 6, 5};
    int sum = 3;

    cout << maxLen(arr, sum);
    cout << endl;
    cout << minLen(arr);
    return 0;
}