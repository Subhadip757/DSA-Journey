#include <bits/stc++.h>
using namespace std;

void dfs(vector<vector<int>> adj, vector<bool> vis, int node)
{
    cout << node << " ";
    vis[node] = 1;

    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[node][i] != 0 && !vis[i])
        {
            dfs(adj, vis, i);
        }
    }
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0}, // Node 0 is connected to nodes 1 and 2
        {1, 0, 0, 1, 0}, // Node 1 is connected to nodes 0 and 3
        {1, 0, 0, 0, 1}, // Node 2 is connected to nodes 0 and 4
        {0, 1, 0, 0, 0}, // Node 3 is connected to node 1
        {0, 0, 1, 0, 0}  // Node 4 is connected to node 2
    };

    // Visited array to keep track of visited nodes
    vector<bool> vis(vertices, false);

    // Starting node for DFS traversal
    int startNode = 0;

    // Perform DFS starting from the startNode
    cout << "DFS Traversal: ";
    dfs(adj, vis, startNode);

    return 0;
}