#include <bits/stdc++.h>
using namespace std;

// BFS Traversal for an Adjacency Matrix Graph
void bfsTraversal(vector<vector<int>>& adjMat, int startNode) {
    int V = adjMat.size(); // Number of vertices
    vector<bool> visited(V, false);
    queue<int> q;

    // Start BFS from the given node
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all adjacent nodes
        for (int i = 0; i < V; i++) {
            if (adjMat[node][i] != 0 && !visited[i]) { // Check if there's an edge and it's not visited
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Main function to input the graph and perform BFS
int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

    cout << "Enter edges (u v) :\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;  // For unweighted graph, store 1
        adjMat[v][u] = 1;  // Since it's an undirected graph
    }

    int startNode;
    cout << "Enter starting node for BFS: ";
    cin >> startNode;

    bfsTraversal(adjMat, startNode);

    return 0;
}