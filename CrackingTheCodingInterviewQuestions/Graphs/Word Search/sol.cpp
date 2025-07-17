#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid, char ch){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == ch){
                dfs(nrow, ncol, vis, grid, ch);
            }
        }
    }

    string exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        string temp = "";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(char ch : word){
                    if(board[i][j] == ch && !vis[i][j]){
                        temp += ch;
                        dfs(i, j, vis, board, ch);
                    }
                }
            }
        }

        return temp;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout<<sol.exist(grid, word);
    return 0;
}