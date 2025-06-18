#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& arr) { 
        int n = arr.size();
        if (n == 0) return;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            int start = 0, end = n - 1;
            while (start < end) {
                swap(arr[i][start], arr[i][end]);
                start++;
                end--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(arr);

    for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = 0; j < (int)arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
