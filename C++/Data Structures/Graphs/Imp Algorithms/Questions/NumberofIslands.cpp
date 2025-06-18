#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
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

    void dfs(int row, int col, std::vector<std::vector<int>> &vis, std::vector<std::vector<char>> &grid)
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
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '0', '1'},
        {'1', '0', '1', '1', '0'},
        {'0', '0', '0', '1', '0'}};
    std::cout << sol.numIslands(grid) << std::endl;
    return 0;
}