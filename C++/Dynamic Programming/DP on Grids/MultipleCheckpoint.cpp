#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INFLL = (1LL << 60);
const int INF = 1e9;

// Approach: compute shortest distances between all special points (start, checkpoints, end)
// using BFS on grid (allowed moves depend on problem - here assume 4-dir or right/down?).
// Then run bitmask DP over distances (k small, e.g., k<=15).

// BFS for grid shortest path (4-direction, obstacles marked by 1). Returns INF if unreachable.
int bfsShortest(const vector<vector<int>> &grid, pair<int, int> s, pair<int, int> t)
{
    int n = grid.size(), m = grid[0].size();
    if (grid[s.first][s.second] == 1 || grid[t.first][t.second] == 1)
        return INF;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<pair<int, int>> dq;
    dist[s.first][s.second] = 0;
    dq.push_back(s);
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    while (!dq.empty())
    {
        auto [r, c] = dq.front();
        dq.pop_front();
        if (r == t.first && c == t.second)
            return dist[r][c];
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dist[nr][nc] == INF)
            {
                dist[nr][nc] = dist[r][c] + 1;
                dq.emplace_back(nr, nc);
            }
        }
    }
    return INF;
}

// bitmask TSP: points = {start, cp1, cp2, ..., end}
long long tspOnGrid(const vector<vector<int>> &grid, const vector<pair<int, int>> &points)
{
    int K = points.size();
    // compute pairwise distances
    vector<vector<int>> dist(K, vector<int>(K, INF));
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = bfsShortest(grid, points[i], points[j]);
        }
    }
    // dp[mask][i] = min cost to visit set mask and end at i
    int full = 1 << K;
    const long long INFLL2 = (1LL << 60);
    vector<vector<long long>> dp(full, vector<long long>(K, INFLL2));
    dp[1 << 0][0] = 0; // assume point 0 is start
    for (int mask = 0; mask < full; mask++)
    {
        for (int i = 0; i < K; i++)
            if (dp[mask][i] < INFLL2)
            {
                for (int j = 0; j < K; j++)
                    if (!(mask & (1 << j)) && dist[i][j] < INF)
                    {
                        int nm = mask | (1 << j);
                        dp[nm][j] = min(dp[nm][j], dp[mask][i] + dist[i][j]);
                    }
            }
    }
    // answer: min dp[mask][end_index] where mask includes desired checkpoints
    // here return min cost to visit all points ending anywhere
    long long ans = INFLL2;
    for (int i = 0; i < K; i++)
        ans = min(ans, dp[full - 1][i]);
    return ans >= INFLL2 ? -1 : ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Multiple checkpoints example (bfs+tsp): points = {start, cp1, cp2, end}
    vector<pair<int, int>> points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}}; // small 3x3 example
    vector<vector<int>> freeGrid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    cout << "5) TSP on grid (visit all points) shortest steps: " << tspOnGrid(freeGrid, points) << '\n';

    return 0;
}