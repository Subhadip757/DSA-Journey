#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &adj, vector<bool> &visited, int start) {
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, -1});  // {node, parent}

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            // Case 1: Unvisited neighbor
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } 
            // Case 2: Visited neighbor that's not the parent (Cycle detected)
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false; // No cycle detected in this component
}

bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // Check for all components
            if (bfs(adj, visited, i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || v < 0 || u >= V || v >= V) {
            cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    if (isCycle(adj)) {
        cout << "Cycle detected!\n";
    } else {
        cout << "No cycle in the graph.\n";
    }

    return 0;
}