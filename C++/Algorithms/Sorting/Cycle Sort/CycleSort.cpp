#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void cycleSort(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            int correctIdx = nums[i];

            if (nums[i] != nums[correctIdx])
            {
                swap(nums[i], nums[correctIdx]);
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 0, 2};
    sol.cycleSort(arr);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}