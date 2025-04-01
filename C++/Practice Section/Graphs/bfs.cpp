#include <bits/stc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V, int start)
{
    queue<int> q;
    vector<bool> vis(V, 0);
    vector<int> res;

    vis[0] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return res;
}

int main()
{
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    vector<int> bfsResult = bfs(adj, V, 0);

    cout << "BFS traversal starting from node 0:" << endl;
    for (int node : bfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}