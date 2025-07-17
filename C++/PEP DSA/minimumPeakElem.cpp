#include <bits/stdc++.h>
using namespace std;

bool isPeak(vector<vector<int>>& mat, int i, int j, int n, int m) {
    int curr = mat[i][j];

    if (i > 0 && mat[i - 1][j] > curr) return false;  
    if (i < n - 1 && mat[i + 1][j] > curr) return false; 
    if (j > 0 && mat[i][j - 1] > curr) return false;      
    if (j < m - 1 && mat[i][j + 1] > curr) return false; 
    return true;
}

int minPeak(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int minPeakVal = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPeak(mat, i, j, n, m)) {
                minPeakVal = min(minPeakVal, mat[i][j]);
            }
        }
    }

    return (minPeakVal == INT_MAX) ? -1 : minPeakVal;
}

int main() {
    vector<vector<int>> mat = {
        {6, 4, 4, 5, 90, 1},
        {3, 10, 6, 8, 100, 0},
        {7, 9, 8, 1, 7, 1},
        {6, 5, 1, 2, 1, 2},
        {1, 2, 2, 0, 4, 7}
    };

    cout << "Minimum peak element: " << minPeak(mat) << endl;
}