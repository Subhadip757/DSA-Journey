#include <bits/stdc++.h>
using namespace std;

int movX[4] = {-1, 1, 0, 0};
int movY[4] = {0, 0, -1, 1};

bool insideGrid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool validPlacement(int cx, int cy, int mode, int length, vector<vector<char>> &mat) {
    int rows = mat.size(), cols = mat[0].size();
    int mid = length / 2;

    for (int i = -mid; i <= mid; i++) {
        int nx = cx + (mode ? i : 0);
        int ny = cy + (mode ? 0 : i);
        if (!insideGrid(nx, ny, rows, cols) || mat[nx][ny] == 'B')
            return false;
    }
    return true;
}

bool rotationPossible(int cx, int cy, vector<vector<char>> &mat) {
    int rows = mat.size(), cols = mat[0].size();
    for (int i = cx - 1; i <= cx + 1; i++) {
        for (int j = cy - 1; j <= cy + 1; j++) {
            if (!insideGrid(i, j, rows, cols) || mat[i][j] == 'B')
                return false;
        }
    }
    return true;
}

// Compare if current ladder cells match destination
bool reachedGoal(int cx, int cy, int mode, int length, vector<pair<int,int>> &goal) {
    vector<pair<int,int>> now;
    int mid = length / 2;

    for (int i = -mid; i <= mid; i++) {
        int nx = cx + (mode ? i : 0);
        int ny = cy + (mode ? 0 : i);
        now.push_back({nx, ny});
    }

    sort(now.begin(), now.end());
    vector<pair<int,int>> goalSorted = goal;
    sort(goalSorted.begin(), goalSorted.end());
    return now == goalSorted;
}

// BFS to find minimum moves
int findMinMoves(vector<vector<char>> &mat, vector<pair<int,int>> &startCells, vector<pair<int,int>> &goalCells) {
    int rows = mat.size(), cols = mat[0].size();
    int length = startCells.size();

    sort(startCells.begin(), startCells.end());
    int sumR = 0, sumC = 0;
    for (auto &p : startCells) {
        sumR += p.first;
        sumC += p.second;
    }
    int startR = sumR / length;
    int startC = sumC / length;

    int orientation = (startCells[0].first == startCells[1].first) ? 0 : 1; 

    vector<vector<vector<int>>> visited(rows, vector<vector<int>>(cols, vector<int>(2, 0)));
    queue<array<int,4>> q; 
    q.push({startR, startC, orientation, 0});
    visited[startR][startC][orientation] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int r = cur[0], c = cur[1], mode = cur[2], dist = cur[3];

        if (reachedGoal(r, c, mode, length, goalCells))
            return dist;

        for (int k = 0; k < 4; k++) {
            int nr = r + movX[k], nc = c + movY[k];
            if (insideGrid(nr, nc, rows, cols) && !visited[nr][nc][mode] && validPlacement(nr, nc, mode, length, mat)) {
                visited[nr][nc][mode] = 1;
                q.push({nr, nc, mode, dist + 1});
            }
        }

        int flipped = 1 - mode;
        if (!visited[r][c][flipped] && rotationPossible(r, c, mat) && validPlacement(r, c, flipped, length, mat)) {
            visited[r][c][flipped] = 1;
            q.push({r, c, flipped, dist + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<char>> matrix(R, vector<char>(C));
    vector<pair<int,int>> source, target;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'l')
                source.push_back({i, j});
            else if (matrix[i][j] == 'L')
                target.push_back({i, j});
        }
    }

    int steps = findMinMoves(matrix, source, target);
    if (steps == -1)
        cout << "Impossible\n";
    else
        cout << steps << "\n";

    return 0;
}