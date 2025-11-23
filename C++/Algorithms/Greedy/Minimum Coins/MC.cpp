// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required.

// Example 1:

// Input: N = 43
// Output: 20 20 2 1
// Explaination:
// Minimum number of coins and notes needed
// to make 43.

#include <bits/stc++.h>
using namespace std;

vector<int> minPartition(int N)
{
    int curr[] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};

    int notes = 0, i = 0;
    vector<int> ans;

    while (N)
    {
        notes = N / curr[i];
        while (notes--)
        {
            ans.push_back(curr[i]);
        }

        N %= curr[i];
        i++;
    }

    return ans;
}