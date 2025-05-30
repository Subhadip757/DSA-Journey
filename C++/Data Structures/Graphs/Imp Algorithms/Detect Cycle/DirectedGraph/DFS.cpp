#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack)
{
    vis[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, adj, vis, recStack))
                return true;
        }
        else if (recStack[neighbor])
        {
            return true; // Cycle detected
        }
    }

    recStack[node] = false;
    return false;
}

bool isCyclicDFS(int V, vector<int> adj[])
{
    vector<bool> vis(V, false), recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, recStack))
                return true;
        }
    }
    return false;
}

// ----------- MAIN FUNCTION -----------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter edges (u -> v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Cycle Detection in Directed Graph:" << endl;
    cout << "- Using DFS: " << (isCyclicDFS(V, adj) ? "Cycle Found" : "No Cycle") << endl;

    return 0;
}
