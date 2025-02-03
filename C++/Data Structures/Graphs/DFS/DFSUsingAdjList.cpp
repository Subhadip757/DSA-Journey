#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(int node, vector<int>& vis, vector<int> adj[], vector<int>& dfs) {
    vis[node] = 1; // Mark the node as visited
    dfs.push_back(node); // Add the node to the DFS result

    // Traverse all neighbors of the current node
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfsUtil(it, vis, adj, dfs); // Recursively visit unvisited neighbors
        }
    }
}

// Function to perform DFS
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0); // Visited array to track visited nodes
    vector<int> dfs;       // To store the DFS traversal result

    // Start DFS from node 0 (assuming 0 is the starting node)
    dfsUtil(0, vis, adj, dfs);

    return dfs;
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    vector<int> dfsResult = dfsOfGraph(V, adj);

    cout << "DFS traversal starting from node 0:" << endl;
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}