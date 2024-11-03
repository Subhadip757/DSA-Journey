#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& mat, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
        // Base case: if destination is reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(move);
            return;
        }

        // Mark the cell as visited
        vis[row][col] = 1;

        // Move Down
        if (row + 1 < n && !vis[row + 1][col] && mat[row + 1][col] == 1) {
            solve(row + 1, col, mat, n, ans, move + 'D', vis);
        }

        // Move Up
        if (row - 1 >= 0 && !vis[row - 1][col] && mat[row - 1][col] == 1) {
            solve(row - 1, col, mat, n, ans, move + 'U', vis);
        }

        // Move Right
        if (col + 1 < n && !vis[row][col + 1] && mat[row][col + 1] == 1) {
            solve(row, col + 1, mat, n, ans, move + 'R', vis);
        }

        // Move Left
        if (col - 1 >= 0 && !vis[row][col - 1] && mat[row][col - 1] == 1) {
            solve(row, col - 1, mat, n, ans, move + 'L', vis);
        }

        // Backtrack and unmark the cell
        vis[row][col] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int n = mat.size();

        // If starting or ending cell is blocked, return an empty answer
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return ans;

        // Create a visited matrix initialized to 0
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Start solving from the top-left corner
        solve(0, 0, mat, n, ans, "", vis);
        return ans;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
