// -------The K Weakest Rows in a Matrix-----------
// Problem Statement:

// You are presented with an m x n binary matrix, where 1's denote soldiers and 0's denote civilians. In this arrangement, soldiers are always positioned ahead of civilians, meaning that in each row, all 1's will be located to the left of all 0's.

// A row i is considered weaker than a row j if either of the following conditions holds:

// The count of soldiers in row i is fewer than that in row j.
// Both rows contain an equal number of soldiers, and the index i is less than index j.

// Your task is to return the indices of the k weakest rows in the matrix, sorted from the weakest to the strongest.

// Input Explanation:
// First line denotes number of rows n.
// Second line denotes number of columns m.
// For next n lines m values each i.e matrix elements.

// Last line denotes k.
// Output Explanation:

// The indices of the k weakest rows in the matrix, sorted from the weakest to the strongest.
// Constraints:

// m == mat.length
// n == mat[i].length
// 2 <= n, m <= 100
// 1 <= k <= m

// matrix[i][j] is either 0 or 1.
// Time Limit:
// 2 sec

// Example 1:
// Input
// 3
// 3
// 1 1 0
// 1 0 0
// 1 1 1
// 2

// Output
// [1, 0]

// Example 2:
// Input
// 5
// 4
// 1 0 0 0
// 1 1 1 0
// 1 1 0 0
// 1 0 0 0
// 0 0 0 0
// 3

// Output
// [4, 0, 3]

// Sample I/O Explanation:
// The number of soldiers in each row is:
// - Row 0: 2
// - Row 1: 4
// - Row 2: 1
// - Row 3: 2
// - Row 4: 5

// The rows ordered from weakest to strongest are [2,0,3,1,4].

#include <bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    map<int, int> mp;
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
        int oneCount = 0;
        int zeroCount = 0;
        int j = 0;
        while(j < m){
            if(mat[i][j] == 1){
                oneCount++;
            }
            else{
                zeroCount++;
            }
            j++;
        }
        if(oneCount <= zeroCount && i < j){
            mp[i] = oneCount;
        }
    }

    vector<int> ans;
    for(auto it : mp){
        ans.push_back(it.first);
    }

    return ans;
}

int main() {
    int rows, cols, k;

    // Input number of rows and columns
    cin >> rows >> cols;

    // Input the matrix
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Input k
    cin >> k;

    // Find the k weakest rows
    vector<int> result = kWeakestRows(mat, k);

    // Output the result in the desired format
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}