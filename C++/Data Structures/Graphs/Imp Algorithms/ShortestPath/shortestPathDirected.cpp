#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

// Function to perform topological sorting using DFS
void topologicalSort(int node, vector<bool> &visited, stack<int> &st, vector<vector<pair<int, int>>> &adj) {
    visited[node] = true;

    for (auto it : adj[node]) {
        int neighbor = it.first;
        if (!visited[neighbor]) {
            topologicalSort(neighbor, visited, st, adj);
        }
    }

    st.push(node);
}

// Function to find the shortest path in a DAG
void shortestPath(int n, vector<vector<pair<int, int>>> &adj, int src) {
    vector<bool> visited(n, false);
    stack<int> st;

    // Perform topological sort
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, visited, st, adj);
        }
    }

    // Initialize distances with infinity
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Process nodes in topological order
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (dist[u] != INT_MAX) {  // Only process reachable nodes
            for (auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 6;  // Number of nodes
    vector<vector<pair<int, int>>> adj(n);  // Adjacency list

    // Add edges (u -> v with weight w)
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 6});
    adj[1].push_back({2, 2});
    adj[2].push_back({4, 4});
    adj[2].push_back({5, 2});
    adj[2].push_back({3, 7});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, -3});

    int src = 0;  // Source node
    shortestPath(n, adj, src);

    return 0;
}