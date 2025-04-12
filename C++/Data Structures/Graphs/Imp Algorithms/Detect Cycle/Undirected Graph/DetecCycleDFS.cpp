#include <iostream>
#include <vector>

using namespace std;

// DFS Function to detect cycle
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true; // Mark the node as visited

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {  // If neighbor is not visited
            if (dfs(neighbor, node, adj, visited)) {
                return true; // Cycle found
            }
        } 
        else if (neighbor != parent) { // If visited and not parent, cycle found
            return true;
        }
    }
    return false;
}

// Function to check cycle in the entire graph
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) { 
        if (!visited[i]) { // Check all components
            if (dfs(i, -1, adj, visited)) {
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

    vector<vector<int>> adj(V); // Adjacency list

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