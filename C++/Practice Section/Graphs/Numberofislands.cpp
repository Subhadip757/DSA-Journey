// Solve the problem of Number of Islands

// Given a 2D grid of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.

// Example:
// Input: grid = [
//     ["1","1","1","1","0"],
//     ["1","1","0","1","0"],
//     ["1","1","0","0","0"],
//     ["0","0","0","0","0"]
//]
// Output: 1

// Input: grid = [
//     ["1","1","0","0","0"],
//     ["1","1","0","0","0"],
//     ["0","0","1","0","0"],
//     ["0","0","0","1","1"]
//]
// Output: 3

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'

// Approach:
// We can use Depth First Search (DFS) to solve this problem.
// We will traverse the grid and whenever we find a '1', we will start a DFS from that cell and mark all the connected cells as visited.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.
// We will use a visited array to keep track of the cells that we have already visited.
// We will use a queue to implement the DFS.

// give the code for the above approach

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << sol.numIslands(grid) << endl;
    return 0;
}