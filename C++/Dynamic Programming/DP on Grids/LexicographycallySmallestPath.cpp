#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string lexicographicallySmallestPath(const vector<string> &grid)
{
    int n = grid.size();
    if (n == 0)
        return "";
    vector<pair<int, int>> cur;
    
    cur.emplace_back(0, 0);
    string res;
    res.push_back(grid[0][0]);
    int totalSteps = 2 * n - 2;

    for (int step = 1; step <= totalSteps; step++)
    {
        char best = 'Z' + 1;
        for (auto &p : cur)
        {
            int x = p.first, y = p.second;
            if (x + 1 < n)
                best = min(best, grid[x + 1][y]);
            if (y + 1 < n)
                best = min(best, grid[x][y + 1]);
        }
        vector<pair<int, int>> next;
        next.reserve(cur.size() * 2);
        for (auto &p : cur)
        {
            int x = p.first, y = p.second;
            if (x + 1 < n && grid[x + 1][y] == best)
                next.emplace_back(x + 1, y);
            if (y + 1 < n && grid[x][y + 1] == best)
                next.emplace_back(x, y + 1);
        }
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        res.push_back(best);
        cur.swap(next);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> sgrid = {"AACA", "BABC", "ABDA", "AACA"};
    cout << "8) Lexicographically smallest path: " << lexicographicallySmallestPath(sgrid) << '\n';

    return 0;
}