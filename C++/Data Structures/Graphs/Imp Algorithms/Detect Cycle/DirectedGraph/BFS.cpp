#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count != V; // If count != V, there is a cycle
}

// ----------- MAIN FUNCTION -----------
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter edges (u -> v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Cycle Detection in Directed Graph:" << endl;
    cout << "- Using BFS (Kahn's Algorithm): " << (isCyclicBFS(V, adj) ? "Cycle Found" : "No Cycle") << endl;

    return 0;
}